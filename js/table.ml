open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

type t = int

type element_segment = int

let add_table wasm_mod name initial maximum =
  meth_call wasm_mod "addTable"
    [| inject (string name); inject initial; inject maximum |]

let add_active_element_segment wasm_mod table name funcnames offset =
  meth_call wasm_mod "addActiveElementSegment"
    [|
      inject (string table);
      inject (string name);
      inject (array (Array.of_list (List.map string funcnames)));
      inject offset;
    |]
