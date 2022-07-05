//Provides: caml_binaryen_add_function_export
//Requires: caml_jsstring_of_string
function caml_binaryen_add_function_export(
  wasm_mod,
  internal_name,
  external_name
) {
  return wasm_mod.addFunctionExport(
    caml_jsstring_of_string(internal_name),
    caml_jsstring_of_string(external_name)
  );
}

//Provides: caml_binaryen_add_table_export
//Requires: caml_jsstring_of_string
function caml_binaryen_add_table_export(
  wasm_mod,
  internal_name,
  external_name
) {
  return wasm_mod.addTableExport(
    caml_jsstring_of_string(internal_name),
    caml_jsstring_of_string(external_name)
  );
}

//Provides: caml_binaryen_add_memory_export
//Requires: caml_jsstring_of_string
function caml_binaryen_add_memory_export(
  wasm_mod,
  internal_name,
  external_name
) {
  return wasm_mod.addMemoryExport(
    caml_jsstring_of_string(internal_name),
    caml_jsstring_of_string(external_name)
  );
}

//Provides: caml_binaryen_add_global_export
//Requires: caml_jsstring_of_string
function caml_binaryen_add_global_export(
  wasm_mod,
  internal_name,
  external_name
) {
  return wasm_mod.addGlobalExport(
    caml_jsstring_of_string(internal_name),
    caml_jsstring_of_string(external_name)
  );
}

//Provides: caml_binaryen_get_export
//Requires: caml_jsstring_of_string
function caml_binaryen_get_export(wasm_mod, external_name) {
  return wasm_mod.getExport(caml_jsstring_of_string(external_name));
}

//Provides: caml_binaryen_remove_export
//Requires: caml_jsstring_of_string
function caml_binaryen_remove_export(wasm_mod, external_name) {
  return wasm_mod.removeExport(caml_jsstring_of_string(external_name));
}

//Provides: caml_binaryen_get_num_exports
function caml_binaryen_get_num_exports(wasm_mod) {
  return wasm_mod.getNumExports();
}

//Provides: caml_binaryen_get_export_by_index
function caml_binaryen_get_export_by_index(wasm_mod, index) {
  return wasm_mod.getExportByIndex(index);
}

//Provides: caml_binaryen_export_get_name
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_export_get_name(exp) {
  var export_info = Binaryen.getExportInfo(exp);
  return caml_string_of_jsstring(export_info.name);
}

//Provides: caml_binaryen_export_get_value
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_export_get_value(exp) {
  var export_info = Binaryen.getExportInfo(exp);
  return caml_string_of_jsstring(export_info.value);
}

//Provides: caml_binaryen_external_function
//Requires: Binaryen
function caml_binaryen_external_function() {
  return Binaryen._BinaryenExternalFunction();
}

//Provides: caml_binaryen_external_table
//Requires: Binaryen
function caml_binaryen_external_table() {
  return Binaryen._BinaryenExternalTable();
}

//Provides: caml_binaryen_external_memory
//Requires: Binaryen
function caml_binaryen_external_memory() {
  return Binaryen._BinaryenExternalMemory();
}

//Provides: caml_binaryen_external_global
//Requires: Binaryen
function caml_binaryen_external_global() {
  return Binaryen._BinaryenExternalGlobal();
}

//Provides: caml_binaryen_external_tag
//Requires: Binaryen
function caml_binaryen_external_tag() {
  return Binaryen._BinaryenExternalTag();
}

//Provides: caml_binaryen_export_get_kind
//Requires: Binaryen
function caml_binaryen_export_get_kind(exp) {
  var export_info = Binaryen.getExportInfo(exp);
  return export_info.kind;
}
