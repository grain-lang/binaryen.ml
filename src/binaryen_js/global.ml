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
