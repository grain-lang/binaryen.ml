//Provides: caml_binaryen_module_create
//Requires: Binaryen
function caml_binaryen_module_create() {
  return new Binaryen.Module();
}

//Provides: caml_binaryen_module_dispose
function caml_binaryen_module_dispose(wasm_mod) {
  return wasm_mod.dispose();
}

//Provides: caml_binaryen_module_parse
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_module_parse(text) {
  return Binaryen.parseText(caml_jsstring_of_string(text));
}

//Provides: caml_binaryen_module_print
//Requires: caml_sys_fds
//Requires: caml_string_of_jsstring
//Requires: caml_ml_output, caml_ml_string_length
function caml_binaryen_module_print(wasm_mod) {
  var text = wasm_mod.emitText();
  var chanid = caml_sys_fds[1].chanid; // stdout
  var s = caml_string_of_jsstring(text);
  caml_ml_output(chanid, s, 0, caml_ml_string_length(s));
}

//Provides: caml_binaryen_module_print_asmjs
//Requires: caml_sys_fds
//Requires: caml_string_of_jsstring
//Requires: caml_ml_output, caml_ml_string_length
function caml_binaryen_module_print_asmjs(wasm_mod) {
  var asm = wasm_mod.emitAsmjs();
  var chanid = caml_sys_fds[1].chanid; // stdout
  var s = caml_string_of_jsstring(asm);
  caml_ml_output(chanid, s, 0, caml_ml_string_length(s));
}

//Provides: caml_binaryen_module_print_stack_ir
//Requires: caml_sys_fds
//Requires: caml_string_of_jsstring
//Requires: caml_ml_output, caml_ml_string_length
function caml_binaryen_module_print_stack_ir(wasm_mod) {
  var stackir = wasm_mod.emitStackIR();
  var chanid = caml_sys_fds[1].chanid; // stdout
  var s = caml_string_of_jsstring(stackir);
  caml_ml_output(chanid, s, 0, caml_ml_string_length(s));
}

//Provides: caml_binaryen_module_validate
function caml_binaryen_module_validate(wasm_mod) {
  return wasm_mod.validate();
}

//Provides: caml_binaryen_module_optimize
function caml_binaryen_module_optimize(wasm_mod) {
  return wasm_mod.optimize();
}

//Provides: caml_binaryen_module_run_passes
//Requires: caml_jsstring_of_string, caml_list_to_js_array
function caml_binaryen_module_run_passes(wasm_mod, passes) {
  return wasm_mod.runPasses(
    caml_list_to_js_array(passes).map(caml_jsstring_of_string)
  );
}

//Provides: caml_binaryen_module_auto_drop
function caml_binaryen_module_auto_drop(wasm_mod) {
  return wasm_mod.autoDrop();
}

//Provides: caml_binaryen_module_write
//Requires: to_option
//Requires: caml_jsstring_of_string, caml_string_of_jsstring, caml_bytes_of_array
function caml_binaryen_module_write(wasm_mod, sourceMapUrl) {
  if (sourceMapUrl) {
    var url = caml_jsstring_of_string(sourceMapUrl[1]);
    var obj = wasm_mod.emitBinary(url);
    var sourceMap =
      obj.sourceMap != null ? caml_string_of_jsstring(obj.sourceMap) : null;
    return [0, caml_bytes_of_array(obj.binary), to_option(sourceMap)];
  } else {
    var binary = wasm_mod.emitBinary();
    return [0, caml_bytes_of_array(binary), 0];
  }
}

//Provides: caml_binaryen_module_write_text
//Requires: caml_string_of_jsstring
function caml_binaryen_module_write_text(wasm_mod) {
  var text = wasm_mod.emitText();
  return caml_string_of_jsstring(text);
}

//Provides: caml_binaryen_module_write_stack_ir
//Requires: caml_string_of_jsstring
function caml_binaryen_module_write_stack_ir(wasm_mod) {
  var text = wasm_mod.emitStackIR();
  return caml_string_of_jsstring(text);
}

//Provides: caml_binaryen_module_read
//Requires: Binaryen
//Requires: caml_uint8_array_of_bytes
function caml_binaryen_module_read(bytes) {
  var data = caml_uint8_array_of_bytes(bytes);
  return Binaryen.readBinary(data);
}

//Provides: caml_binaryen_module_interpret
function caml_binaryen_module_interpret(wasm_mod) {
  return wasm_mod.interpret();
}

//Provides: caml_binaryen_module_add_debug_info_filename
//Requires: caml_jsstring_of_string
function caml_binaryen_module_add_debug_info_filename(wasm_mod, filename) {
  return wasm_mod.addDebugInfoFileName(caml_jsstring_of_string(filename));
}

//Provides: caml_binaryen_module_get_debug_info_filename
function caml_binaryen_module_get_debug_info_filename(wasm_mod, index) {
  return wasm_mod.getDebugInfoFileName(index);
}

//Provides: caml_binaryen_add_custom_section
//Requires: caml_jsstring_of_string, caml_array_of_string
function caml_binaryen_add_custom_section(wasm_mod, name, contents) {
  return wasm_mod.addCustomSection(
    caml_jsstring_of_string(name),
    caml_array_of_string(contents)
  );
}

//Provides: caml_binaryen_module_update_maps
function caml_binaryen_module_update_maps(wasm_mod) {
  // The JS version doesn't expose `update_maps`
  return;
}
