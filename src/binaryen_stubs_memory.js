//Provides: caml_binaryen_set_memory
//Requires: caml_list_to_js_array, caml_convert_bytes_to_array
//Requires: caml_jsstring_of_string, caml_js_from_bool
function caml_binaryen_set_memory(wasm_mod, initial, maximum, exportName, segmentNames, segmentPassives, segmentOffsets, segmentSizes, shared) {
  var segs = caml_list_to_js_array(segmentNames).map(function (segmentName, idx) {
    return {
      data: caml_convert_bytes_to_array(segmentName),
      passive: segmentPassives[idx + 1], // OCaml Lists are offset by 1
      offset: segmentOffsets[idx + 1] // OCaml Lists are offset by 1
    }
  });

  return wasm_mod.setMemory(
    initial,
    maximum,
    caml_jsstring_of_string(exportName),
    segs,
    caml_js_from_bool(shared)
  );
}
//Provides: caml_binaryen_set_memory__bytecode
//Requires: caml_binaryen_set_memory
function caml_binaryen_set_memory__bytecode() {
  return caml_binaryen_set_memory(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6], arguments[7], arguments[8]);
}
