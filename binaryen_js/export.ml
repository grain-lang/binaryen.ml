open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

type t

let add_function_export wasm_mod internal_name external_name =
  meth_call wasm_mod "addFunctionExport"
    [| inject (string internal_name); inject (string external_name) |]

let add_table_export wasm_mod internal_name external_name =
  meth_call wasm_mod "addTableExport"
    [| inject (string internal_name); inject (string external_name) |]

let add_memory_export wasm_mod internal_name external_name =
  meth_call wasm_mod "addMemoryExport"
    [| inject (string internal_name); inject (string external_name) |]

let add_global_export wasm_mod internal_name external_name =
  meth_call wasm_mod "addGlobalExport"
    [| inject (string internal_name); inject (string external_name) |]

let remove_export wasm_mod external_name =
  meth_call wasm_mod "removeExport" [| inject (string external_name) |]
