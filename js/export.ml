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

let get_export wasm_mod external_name =
  meth_call wasm_mod "getExport" [| inject (string external_name) |]

let remove_export wasm_mod external_name =
  meth_call wasm_mod "removeExport" [| inject (string external_name) |]

let get_num_exports wasm_mod = meth_call wasm_mod "getNumExports" [||]

let get_export_by_index wasm_mod index =
  meth_call wasm_mod "getExportByIndex" [| inject index |]

let get_name export =
  let export_info =
    meth_call global##.binaryen "getExportInfo" [| inject export |]
  in
  to_string (get export_info "name")

let get_value export =
  let export_info =
    meth_call global##.binaryen "getExportInfo" [| inject export |]
  in
  to_string (get export_info "value")

let external_function =
  meth_call global##.binaryen "_BinaryenExternalFunction" [||]

let external_table = meth_call global##.binaryen "_BinaryenExternalTable" [||]

let external_memory = meth_call global##.binaryen "_BinaryenExternalMemory" [||]

let external_global = meth_call global##.binaryen "_BinaryenExternalGlobal" [||]

let external_tag = meth_call global##.binaryen "_BinaryenExternalTag" [||]

let export_get_kind export =
  let export_info =
    meth_call global##.binaryen "getExportInfo" [| inject export |]
  in
  get export_info "kind"
