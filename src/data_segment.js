
//Provides: caml_binaryen_get_num_memory_segments
function caml_binaryen_get_num_memory_segments(wasm_mod) {
  return wasm_mod.getNumMemorySegments();
}

//Provides: caml_binaryen_get_data_segment
//Requires: caml_jsstring_of_string, to_option
function caml_binaryen_get_data_segment(wasm_mod, name) {
  return to_option(wasm_mod.getDataSegment(caml_jsstring_of_string(name)));
}

//Provides: caml_binaryen_get_data_segment_by_index
function caml_binaryen_get_data_segment_by_index(wasm_mod, index) {
  return wasm_mod.getDataSegmentByIndex(index);
}

// Provides: caml_binaryen_data_segment_get_name
// Requires: caml_string_of_jsstring
function caml_binaryen_data_segment_get_name(wasm_mod, segment) {
  var info = wasm_mod.getMemorySegmentInfo(segment);
  return caml_string_of_jsstring(info.name);
}

//Provides: caml_binaryen_get_memory_segment_byte_offset
//Requires: to_option
function caml_binaryen_get_memory_segment_byte_offset(wasm_mod, segment) {
  var info = wasm_mod.getMemorySegmentInfo(segment);
  return to_option(info.offset);
}

//Provides: caml_binaryen_get_memory_segment_byte_length
//Requires: Binaryen
function caml_binaryen_get_memory_segment_byte_length(segment) {
  return Binaryen._BinaryenGetMemorySegmentByteLength(segment);
}

//Provides: caml_binaryen_get_memory_segment_passive
//Requires: Binaryen
function caml_binaryen_get_memory_segment_passive(segment) {
  return Binaryen._BinaryenGetMemorySegmentPassive(segment);
}

//Provides: caml_binaryen_get_memory_segment_data
//Requires: caml_bytes_of_array
function caml_binaryen_get_memory_segment_data(wasm_mod, segment) {
  var info = wasm_mod.getMemorySegmentInfo(segment);
  return caml_bytes_of_array(info.data);
}
