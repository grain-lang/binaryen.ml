//Provides: caml_binaryen_add_function_import
//Requires: caml_jsstring_of_string
function caml_binaryen_add_function_import(
  wasm_mod,
  internalName,
  externalModuleName,
  externalBaseName,
  paramsty,
  resultsty
) {
  return wasm_mod.addFunctionImport(
    caml_jsstring_of_string(internalName),
    caml_jsstring_of_string(externalModuleName),
    caml_jsstring_of_string(externalBaseName),
    paramsty,
    resultsty
  );
}
//Provides: caml_binaryen_add_function_import__bytecode
//Requires: caml_binaryen_add_function_import
function caml_binaryen_add_function_import__bytecode() {
  return caml_binaryen_add_function_import(
    arguments[0],
    arguments[1],
    arguments[2],
    arguments[3],
    arguments[4],
    arguments[5]
  );
}

//Provides: caml_binaryen_add_table_import
//Requires: caml_jsstring_of_string
function caml_binaryen_add_table_import(
  wasm_mod,
  internalName,
  externalModuleName,
  externalBaseName
) {
  return wasm_mod.addTableImport(
    caml_jsstring_of_string(internalName),
    caml_jsstring_of_string(externalModuleName),
    caml_jsstring_of_string(externalBaseName)
  );
}

//Provides: caml_binaryen_add_memory_import
//Requires: caml_jsstring_of_string
function caml_binaryen_add_memory_import(
  wasm_mod,
  internalName,
  externalModuleName,
  externalBaseName,
  shared
) {
  return wasm_mod.addMemoryImport(
    caml_jsstring_of_string(internalName),
    caml_jsstring_of_string(externalModuleName),
    caml_jsstring_of_string(externalBaseName),
    shared // bool will come through as an int
  );
}

//Provides: caml_binaryen_add_global_import
//Requires: caml_jsstring_of_string
function caml_binaryen_add_global_import(
  wasm_mod,
  internalName,
  externalModuleName,
  externalBaseName,
  typ,
  is_mut
) {
  return wasm_mod.addGlobalImport(
    caml_jsstring_of_string(internalName),
    caml_jsstring_of_string(externalModuleName),
    caml_jsstring_of_string(externalBaseName),
    typ,
    is_mut // bool will come through as an int
  );
}
//Provides: caml_binaryen_add_global_import__bytecode
//Requires: caml_binaryen_add_global_import
function caml_binaryen_add_global_import__bytecode() {
  return caml_binaryen_add_global_import(
    arguments[0],
    arguments[1],
    arguments[2],
    arguments[3],
    arguments[4],
    arguments[5]
  );
}

//Provides: caml_binaryen_add_tag_import
//Requires: caml_jsstring_of_string
function caml_binaryen_add_tag_import(
  wasm_mod,
  internalName,
  externalModuleName,
  externalBaseName,
  paramsty,
  resultsty
) {
  return wasm_mod.addTagImport(
    caml_jsstring_of_string(internalName),
    caml_jsstring_of_string(externalModuleName),
    caml_jsstring_of_string(externalBaseName),
    paramsty,
    resultsty
  );
}
//Provides: caml_binaryen_add_tag_import__bytecode
//Requires: caml_binaryen_add_tag_import
function caml_binaryen_add_tag_import__bytecode() {
  return caml_binaryen_add_tag_import(
    arguments[0],
    arguments[1],
    arguments[2],
    arguments[3],
    arguments[4],
    arguments[5]
  );
}

//Provides: caml_binaryen_function_import_get_module
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_function_import_get_module(func) {
  var func_info = Binaryen.getFunctionInfo(func);
  return caml_string_of_jsstring(func_info.module);
}

//Provides: caml_binaryen_memory_import_get_module
//Requires: caml_string_of_jsstring, caml_jsstring_of_string
function caml_binaryen_memory_import_get_module(mod, memoryName) {
  var memory_info = mod.getMemoryInfo(caml_jsstring_of_string(memoryName));
  return caml_string_of_jsstring(memory_info.module);
}

//Provides: caml_binaryen_global_import_get_module
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_global_import_get_module(global) {
  var global_info = Binaryen.getGlobalInfo(global);
  return caml_string_of_jsstring(global_info.module);
}

//Provides: caml_binaryen_tag_import_get_module
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_tag_import_get_module(tag) {
  var tag_info = Binaryen.getTagInfo(tag);
  return caml_string_of_jsstring(tag_info.module);
}

//Provides: caml_binaryen_function_import_get_base
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_function_import_get_base(func) {
  var func_info = Binaryen.getFunctionInfo(func);
  return caml_string_of_jsstring(func_info.base);
}

//Provides: caml_binaryen_memory_import_get_base
//Requires: caml_string_of_jsstring, caml_jsstring_of_string
function caml_binaryen_memory_import_get_base(mod, memoryName) {
  var memory_info = mod.getMemoryInfo(caml_jsstring_of_string(memoryName));
  return caml_string_of_jsstring(memory_info.base);
}

//Provides: caml_binaryen_global_import_get_base
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_global_import_get_base(global) {
  var global_info = Binaryen.getGlobalInfo(global);
  return caml_string_of_jsstring(global_info.base);
}

//Provides: caml_binaryen_tag_import_get_base
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_tag_import_get_base(tag) {
  var tag_info = Binaryen.getTagInfo(tag);
  return caml_string_of_jsstring(tag_info.base);
}
