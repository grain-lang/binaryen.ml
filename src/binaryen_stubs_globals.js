//Provides: caml_binaryen_add_global
//Requires: caml_jsstring_of_string
function caml_binaryen_add_global(wasm_mod, name, typ, is_mut, init) {
  return wasm_mod.addGlobal(
    caml_jsstring_of_string(name),
    typ,
    // TODO: Check this
    is_mut, // bool will come through as an int
    init
  );
}

//Provides: caml_binaryen_get_global
//Requires: caml_jsstring_of_string
function caml_binaryen_get_global(wasm_mod, name) {
  return wasm_mod.getGlobal(caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_remove_global
//Requires: caml_jsstring_of_string
function caml_binaryen_remove_global(wasm_mod, name) {
  return wasm_mod.removeGlobal(caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_get_num_globals
function caml_binaryen_get_num_globals(wasm_mod) {
  return wasm_mod.getNumGlobals();
}

//Provides: caml_binaryen_get_global_by_index
function caml_binaryen_get_global_by_index(wasm_mod, index) {
  return wasm_mod.getGlobalByIndex(index);
}

//Provides: caml_binaryen_global_get_name
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_global_get_name(global) {
  var global_info = binaryen.getGlobalInfo(global);
  return caml_string_of_jsstring(global_info.name);
}

//Provides: caml_binaryen_global_get_type
//Requires: binaryen
function caml_binaryen_global_get_type(global) {
  var global_info = binaryen.getGlobalInfo(global);
  return global_info.type;
}

//Provides: caml_binaryen_global_is_mutable
//Requires: binaryen
//Requires: caml_js_to_bool
function caml_binaryen_global_is_mutable(global) {
  var global_info = binaryen.getGlobalInfo(global);
  return caml_js_to_bool(global_info.mutable);
}

//Provides: caml_binaryen_global_get_init_expr
//Requires: binaryen
function caml_binaryen_global_get_init_expr(global) {
  var global_info = binaryen.getGlobalInfo(global);
  return global_info.init;
}
