//Provides: caml_binaryen_set_memory
//Requires: caml_list_to_js_array, caml_convert_bytes_to_array
//Requires: caml_jsstring_of_string, caml_js_from_bool
function caml_binaryen_set_memory(
  wasm_mod,
  initial,
  maximum,
  exportName,
  segmentNames,
  segmentData,
  segmentPassives,
  segmentOffsets,
  segmentSizes,
  shared,
  memory64,
  memoryName
) {
  var datas = caml_list_to_js_array(segmentData);
  var passives = caml_list_to_js_array(segmentPassives);
  var offsets = caml_list_to_js_array(segmentOffsets);
  var segs = caml_list_to_js_array(segmentNames).map(function (name, idx) {
    return {
      name: caml_jsstring_of_string(name),
      data: caml_convert_bytes_to_array(datas[idx]),
      passive: caml_js_from_bool(passives[idx]),
      offset: offsets[idx],
    };
  });

  return wasm_mod.setMemory(
    initial,
    maximum,
    caml_jsstring_of_string(exportName),
    segs,
    caml_js_from_bool(shared),
    caml_js_from_bool(memory64),
    caml_jsstring_of_string(memoryName)
  );
}
//Provides: caml_binaryen_set_memory__bytecode
//Requires: caml_binaryen_set_memory
function caml_binaryen_set_memory__bytecode() {
  return caml_binaryen_set_memory(
    arguments[0],
    arguments[1],
    arguments[2],
    arguments[3],
    arguments[4],
    arguments[5],
    arguments[6],
    arguments[7],
    arguments[8],
    arguments[9],
    arguments[10],
    arguments[11]
  );
}

//Provides: caml_binaryen_has_memory
//Requires: caml_js_to_bool
function caml_binaryen_has_memory(mod) {
  return caml_js_to_bool(mod.hasMemory());
}

//Provides: caml_binaryen_memory_get_initial
//Requires: caml_jsstring_of_string
function caml_binaryen_memory_get_initial(mod, memoryName) {
  var memory_info = mod.getMemoryInfo(caml_jsstring_of_string(memoryName));
  return memory_info.initial;
}

//Provides: caml_binaryen_memory_has_max
//Requires: caml_js_to_bool, caml_jsstring_of_string
function caml_binaryen_memory_has_max(mod, memoryName) {
  var memory_info = mod.getMemoryInfo(caml_jsstring_of_string(memoryName));
  if (memory_info.max != null) {
    return caml_js_to_bool(true);
  } else {
    return caml_js_to_bool(false);
  }
}

//Provides: caml_binaryen_memory_get_max
//Requires: caml_jsstring_of_string
function caml_binaryen_memory_get_max(mod, memoryName) {
  var memory_info = mod.getMemoryInfo(caml_jsstring_of_string(memoryName));
  if (memory_info.max != null) {
    return memory_info.max;
  } else {
    // This ensures that our return is equal to Memory.unlimited
    return -1;
  }
}

//Provides: caml_binaryen_memory_is_shared
//Requires: caml_js_to_bool, caml_jsstring_of_string
function caml_binaryen_memory_is_shared(mod, memoryName) {
  var memory_info = mod.getMemoryInfo(caml_jsstring_of_string(memoryName));
  return caml_js_to_bool(memory_info.shared);
}

//Provides: caml_binaryen_memory_is_64
//Requires: caml_js_to_bool, caml_jsstring_of_string
function caml_binaryen_memory_is_64(mod, memoryName) {
  var memory_info = mod.getMemoryInfo(caml_jsstring_of_string(memoryName));
  return caml_js_to_bool(memory_info.is64);
}

//Provides: caml_binaryen_get_num_memory_segments
function caml_binaryen_get_num_memory_segments(wasm_mod) {
  return wasm_mod.getNumMemorySegments();
}

//Provides: caml_binaryen_get_memory_segment_byte_offset
//Requires: caml_jsstring_of_string
function caml_binaryen_get_memory_segment_byte_offset(wasm_mod, name) {
  var info = wasm_mod.getMemorySegmentInfo(caml_jsstring_of_string(name));
  return info.offset;
}

//Provides: caml_binaryen_get_memory_segment_passive
//Requires: caml_jsstring_of_string
function caml_binaryen_get_memory_segment_passive(wasm_mod, name) {
  var info = wasm_mod.getMemorySegmentInfo(caml_jsstring_of_string(name));
  return info.passive;
}

//Provides: caml_binaryen_get_memory_segment_data
//Requires: caml_bytes_of_array, caml_jsstring_of_string
function caml_binaryen_get_memory_segment_data(wasm_mod, name) {
  var info = wasm_mod.getMemorySegmentInfo(caml_jsstring_of_string(name));
  return caml_bytes_of_array(info.data);
}
