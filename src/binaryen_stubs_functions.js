//Provides: caml_binaryen_add_function
//Requires: caml_jsstring_of_string, caml_js_from_array
function caml_binaryen_add_function(wasm_mod, name, params, results, locals, body) {
  return wasm_mod.addFunction(
    caml_jsstring_of_string(name),
    params,
    results,
    caml_js_from_array(locals),
    body
  );
}
//Provides: caml_binaryen_add_function__bytecode
//Requires: caml_binaryen_add_function
function caml_binaryen_add_function__bytecode() {
  return caml_binaryen_add_function(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
}

//Provides: caml_binaryen_get_function
//Requires: caml_jsstring_of_string
function caml_binaryen_get_function(wasm_mod, name) {
  return wasm_mod.getFunction(caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_remove_function
//Requires: caml_jsstring_of_string
function caml_binaryen_remove_function(wasm_mod, name) {
  return wasm_mod.removeFunction(caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_get_num_functions
function caml_binaryen_get_num_functions(wasm_mod) {
  return wasm_mod.getNumFunctions();
}

//Provides: caml_binaryen_get_function_by_index
function caml_binaryen_get_function_by_index(wasm_mod, index) {
  return wasm_mod.getFunctionByIndex(index);
}

//Provides: caml_binaryen_set_start
function caml_binaryen_set_start(wasm_mod, func) {
  return wasm_mod.setStart(func);
}

//Provides: caml_binaryen_function_set_debug_location
//Requires: binaryen
function caml_binaryen_function_set_debug_location(func, exp, file, line, column) {
  return binaryen._BinaryenFunctionSetDebugLocation(func, exp, file, line, column);
}

//Provides: caml_binaryen_function_get_name
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_function_get_name(func) {
  return caml_string_of_jsstring(binaryen.Function.getName(func));
}

//Provides: caml_binaryen_function_get_params
//Requires: binaryen
function caml_binaryen_function_get_params(func) {
  return binaryen.Function.getParams(func);
}

//Provides: caml_binaryen_function_get_results
//Requires: binaryen
function caml_binaryen_function_get_results(func) {
  return binaryen.Function.getResults(func);
}

//Provides: caml_binaryen_function_get_num_vars
//Requires: binaryen
function caml_binaryen_function_get_num_vars(func) {
  return binaryen.Function.getNumVars(func);
}

//Provides: caml_binaryen_function_get_var
//Requires: binaryen
function caml_binaryen_function_get_var(func, index) {
  return binaryen.Function.getVar(func, index);
}

//Provides: caml_binaryen_function_get_body
//Requires: binaryen
function caml_binaryen_function_get_body(func) {
  return binaryen.Function.getBody(func);
}

//Provides: caml_binaryen_function_set_body
//Requires: binaryen
function caml_binaryen_function_set_body(func, body) {
  return binaryen.Function.setBody(func, body);
}
