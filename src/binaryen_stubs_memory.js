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

//Provides: caml_binaryen_has_memory
//Requires: caml_js_to_bool
function caml_binaryen_has_memory(mod) {
  return caml_js_to_bool(mod.hasMemory());
}

//Provides: caml_binaryen_memory_get_initial
function caml_binaryen_memory_get_initial(mod) {
  var memory_info = mod.getMemoryInfo();
  return memory_info.initial;
}

//Provides: caml_binaryen_memory_has_max
//Requires: caml_js_to_bool
function caml_binaryen_memory_has_max(mod) {
  var memory_info = mod.getMemoryInfo();
  if (memory_info.max != null) {
    return caml_js_to_bool(true);
  } else {
    return caml_js_to_bool(false);
  }
}

//Provides: caml_binaryen_memory_get_max
function caml_binaryen_memory_get_max(mod) {
  var memory_info = mod.getMemoryInfo();
  if (memory_info.max != null) {
    return memory_info.max;
  } else {
    // This ensures that our return is equal to Memory.unlimited
    return -1;
  }
}

//Provides: caml_binaryen_memory_is_shared
//Requires: caml_js_to_bool
function caml_binaryen_memory_is_shared(mod) {
  var memory_info = mod.getMemoryInfo();
  return caml_js_to_bool(memory_info.shared);
}
