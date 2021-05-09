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

let get_num_globals wasm_mod = meth_call wasm_mod "getNumGlobals" [||]

let get_global_by_index wasm_mod index =
  meth_call wasm_mod "getGlobalByIndex" [| inject index |]

let get_name global_ =
  let global_info =
    meth_call global##.binaryen "getGlobalInfo" [| inject global_ |]
  in
  to_string (get global_info "name")

let get_type global_ =
  let global_info =
    meth_call global##.binaryen "getGlobalInfo" [| inject global_ |]
  in
  get global_info "type"

let is_mutable global_ =
  let global_info =
    meth_call global##.binaryen "getGlobalInfo" [| inject global_ |]
  in
  to_bool (get global_info "mutable")

let get_init_expr global_ =
  let global_info =
    meth_call global##.binaryen "getGlobalInfo" [| inject global_ |]
  in
  get global_info "init"
