open Binaryen

let wasm_mod = Module.create ()

(* Create function type for i32 (i32, i32) *)
let params () = Type.create [| Type.int32; Type.int32 |]

let results = Type.int32

let x () = Expression.local_get wasm_mod 0 Type.int32

let y () = Expression.local_get wasm_mod 1 Type.int32

let load = Expression.load wasm_mod 1 ~signed:true 0 0 Type.int32 (y ())

let select =
  Expression.select wasm_mod
    (Expression.const wasm_mod (Literal.int32 1l))
    (x ()) load

let bin = Expression.binary wasm_mod Op.add_int32 select (y ())

let add =
  Expression.block wasm_mod ~return_type:Type.int32 "add"
    [
      Expression.if_ wasm_mod
        (Expression.const wasm_mod (Literal.int32 0l))
        (Expression.unreachable wasm_mod)
        (Expression.null ());
      bin;
    ]

(* Create the add function *)
let adder = Function.add_function wasm_mod "adder" (params ()) results [||] add

let call_adder =
  Expression.call_indirect wasm_mod "table"
    (Expression.const wasm_mod (Literal.int32 0l))
    [
      Expression.const wasm_mod (Literal.int32 3l);
      Expression.const wasm_mod (Literal.int32 5l);
    ]
    (params ()) Type.int32

let start =
  Function.add_function wasm_mod "start" Type.none Type.none [||]
    (Expression.drop wasm_mod call_adder)

let _ = Export.add_function_export wasm_mod "adder" "adder"

let _ =
  Table.add_table wasm_mod "table" 1 1 [ "adder" ]
    (Expression.const wasm_mod (Literal.int32 0l))

let _ = Function.set_start wasm_mod start

let _ = Memory.set_memory wasm_mod 1 Memory.unlimited "memory" [] false

let _ = Module.print wasm_mod

let _ = Module.optimize wasm_mod

let _ = Module.print wasm_mod

let byts, _ = Module.write wasm_mod None

let new_mod = Module.read byts

let _ = Module.validate new_mod

let _ = Module.print new_mod

let _ = Module.dispose wasm_mod

let _ = Module.dispose new_mod
