open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

type t

let add_function wasm_mod name params results vars body =
  meth_call wasm_mod "addFunction"
    [|
      inject (string name);
      inject params;
      inject results;
      inject (array vars);
      inject body;
    |]

let set_start wasm_mod func = meth_call wasm_mod "setStart" [| inject func |]

let set_debug_location func expr file line column =
  ignore
    (meth_call global##.binaryen "_BinaryenFunctionSetDebugLocation"
       [| inject func; inject expr; inject file; inject line; inject column |])

let get_function wasm_mod name =
  meth_call wasm_mod "getFunction" [| inject (string name) |]

let remove_function wasm_mod name =
  meth_call wasm_mod "removeFunction" [| inject (string name) |]

let get_num_functions wasm_mod = meth_call wasm_mod "getNumFunctions" [||]
