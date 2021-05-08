open Binaryen

let _ = assert (Settings.are_colors_enabled () == 1)

let _ = Settings.set_colors_enabled 0

let _ = assert (Settings.are_colors_enabled () == 0)

let wasm_mod = Module.create ()

let _ = Module.set_features wasm_mod [ Module.Feature.all ]

(* Create function type for i32 (i32, i32) *)
let params () = Type.create [| Type.int32; Type.int32 |]

let results = Type.int32

let x () = Expression.Local_get.make wasm_mod 0 Type.int32

let y () = Expression.Local_get.make wasm_mod 1 Type.int32

let load = Expression.Load.make wasm_mod 1 ~signed:true 0 0 Type.int32 (y ())

let select =
  Expression.Select.make wasm_mod
    (Expression.Const.make wasm_mod (Literal.int32 1l))
    (x ()) load

let bin = Expression.Binary.make wasm_mod Op.add_int32 select (y ())

let add =
  Expression.Block.make wasm_mod ~return_type:Type.int32 "add"
    [
      Expression.If.make wasm_mod
        (Expression.Const.make wasm_mod (Literal.int32 0l))
        (Expression.Unreachable.make wasm_mod)
        (Expression.Null.make ());
      bin;
    ]

(* Create the add function *)
let adder = Function.add_function wasm_mod "adder" (params ()) results [||] add

let call_adder =
  Expression.Call_indirect.make wasm_mod "table"
    (Expression.Const.make wasm_mod (Literal.int32 0l))
    [
      Expression.Const.make wasm_mod (Literal.int32 3l);
      Expression.Const.make wasm_mod (Literal.int32 5l);
    ]
    (params ()) Type.int32

let start =
  Function.add_function wasm_mod "start" Type.none Type.none [||]
    (Expression.Drop.make wasm_mod call_adder)

let _ = Export.add_function_export wasm_mod "adder" "adder"

let _ = Table.add_table wasm_mod "table" 1 1

let _ =
  Global.add_global wasm_mod "max_int64" Type.int64 false
    (Expression.Const.make wasm_mod (Literal.int64 Int64.max_int))

let _ =
  Global.add_global wasm_mod "test_float64_bits" Type.float64 false
    (Expression.Const.make wasm_mod (Literal.float64_bits 0x3FF3AE147AE147AEL))

let _ =
  Table.add_active_element_segment wasm_mod "table" "elem" [ "adder" ]
    (Expression.Const.make wasm_mod (Literal.int32 0l))

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
