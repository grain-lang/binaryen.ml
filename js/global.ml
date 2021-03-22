open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

type t

let add_global wasm_mod name typ is_mut init =
  meth_call wasm_mod "addGlobal"
    [|
      inject (string name);
      inject typ;
      inject (if is_mut then 1 else 0);
      inject init;
    |]

let get_global wasm_mod name =
  meth_call wasm_mod "getGlobal" [| inject (string name) |]

let remove_global wasm_mod name =
  meth_call wasm_mod "removeGlobal" [| inject (string name) |]

let get_num_globals wasm_mod =
  meth_call global##.binaryen "_BinaryenGetNumGlobals" [| inject wasm_mod |]

let get_global_by_index wasm_mod index =
  meth_call global##.binaryen "_BinaryenGlobalByIndex"
    [| inject wasm_mod; inject index |]

let get_name global_ =
  to_string
    (meth_call global##.binaryen "_BinaryenGlobalGetName" [| inject global_ |])

let get_type global_ =
  meth_call global##.binaryen "_BinaryenGlobalGetType" [| inject global_ |]

let is_mutable global_ =
  to_bool
    (meth_call global##.binaryen "_BinaryenGlobalIsMutable"
       [| inject global_ |])

let get_init_expr global_ =
  meth_call global##.binaryen "_BinaryenGlobalGetInitExpr" [| inject global_ |]
