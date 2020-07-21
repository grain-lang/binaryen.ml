open Binaryen

let wasm_mod = Module.create ()

(* Create function type for i32 (i32, i32) *)
let params = Type.create [| Type.int32; Type.int32 |]

let results = Type.int32

(* Get arguments 0 and 1, add them *)
let x = Expression.local_get wasm_mod 0 Type.int32

let y = Expression.local_get wasm_mod 1 Type.int32

let add = Expression.binary wasm_mod Op.add_int32 x y

(* Create the add function *)
let adder = Function.add_function wasm_mod "adder" params results [||] add

let _ = Module.print wasm_mod

let _ = Module.dispose wasm_mod

let _ = Printf.printf "OK!\n"
