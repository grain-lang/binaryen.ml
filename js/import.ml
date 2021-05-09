open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

let add_function_import wasm_mod internal_name external_module_name
    external_base_name params result =
  meth_call wasm_mod "addFunctionImport"
    [|
      inject (string internal_name);
      inject (string external_module_name);
      inject (string external_base_name);
      inject params;
      inject result;
    |]

let add_table_import wasm_mod internal_name external_module_name
    external_base_name =
  meth_call wasm_mod "addTableImport"
    [|
      inject (string internal_name);
      inject (string external_module_name);
      inject (string external_base_name);
    |]

(* TODO: Check this bool conversion *)
let add_memory_import wasm_mod internal_name external_module_name
    external_base_name shared =
  meth_call wasm_mod "addMemoryImport"
    [|
      inject (string internal_name);
      inject (string external_module_name);
      inject (string external_base_name);
      inject (if shared then 1 else 0);
    |]

(* TODO: Check this bool conversion *)
let add_global_import wasm_mod internal_name external_module_name
    external_base_name typ is_mut =
  meth_call wasm_mod "addGlobalImport"
    [|
      inject (string internal_name);
      inject (string external_module_name);
      inject (string external_base_name);
      inject typ;
      inject (if is_mut then 1 else 0);
    |]

let function_import_get_module func =
  let func_info =
    meth_call global##.binaryen "getFunctionInfo" [| inject func |]
  in
  to_string (get func_info "module")

let global_import_get_module global_ =
  let global_info =
    meth_call global##.binaryen "getGlobalInfo" [| inject global_ |]
  in
  to_string (get global_info "module")

let function_import_get_base func =
  let func_info =
    meth_call global##.binaryen "getFunctionInfo" [| inject func |]
  in
  to_string (get func_info "base")

let global_import_get_base global_ =
  let global_info =
    meth_call global##.binaryen "getGlobalInfo" [| inject global_ |]
  in
  to_string (get global_info "base")
