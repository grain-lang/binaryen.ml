open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

let set_function_table wasm_mod initial maximum funcnames offset =
  meth_call wasm_mod "setFunctionTable"
    [|
      inject initial;
      inject maximum;
      inject (array (Array.of_list (List.map string funcnames)));
      inject offset;
    |]

let unlimited = -1
