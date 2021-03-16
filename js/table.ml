open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

let add_table wasm_mod name initial maximum funcnames offset =
  meth_call wasm_mod "addTable"
    [|
      inject (string name);
      inject initial;
      inject maximum;
      inject (array (Array.of_list (List.map string funcnames)));
      inject offset;
    |]
