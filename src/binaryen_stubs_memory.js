//Provides: caml_binaryen_set_memory
//Requires: caml_list_to_js_array, caml_convert_bytes_to_array
//Requires: caml_jsstring_of_string, caml_js_from_bool
function caml_binaryen_set_memory(wasm_mod, initial, maximum, exportName, segments, segmentPassives, segmentOffsets, segmentSizes, shared) {
  var passives = caml_list_to_js_array(segmentPassives);
  var offsets = caml_list_to_js_array(segmentOffsets);
  var segs = caml_list_to_js_array(segments).map(function (segment, idx) {
    return {
      data: caml_convert_bytes_to_array(segment),
      passive: caml_js_from_bool(passives[idx]),
      offset: offsets[idx]
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
