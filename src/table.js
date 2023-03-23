//Provides: caml_binaryen_add_table
//Requires: caml_jsstring_of_string
function caml_binaryen_add_table(wasm_mod, table, initial, maximum, tableType) {
  return wasm_mod.addTable(
    caml_jsstring_of_string(table),
    initial,
    maximum,
    tableType
  );
}

//Provides: caml_binaryen_add_active_element_segment
//Requires: caml_jsstring_of_string, caml_list_to_js_array
function caml_binaryen_add_active_element_segment(
  wasm_mod,
  table,
  name,
  funcnames,
  offset
) {
  return wasm_mod.addActiveElementSegment(
    caml_jsstring_of_string(table),
    caml_jsstring_of_string(name),
    caml_list_to_js_array(funcnames).map(caml_jsstring_of_string),
    offset
  );
}

//Provides: caml_binaryen_remove_element_segment
//Requires: caml_jsstring_of_string
function caml_binaryen_remove_element_segment(wasm_mod, name) {
  return wasm_mod.removeElementSegment(caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_get_num_element_segments
function caml_binaryen_get_num_element_segments(wasm_mod) {
  return wasm_mod.getNumElementSegments();
}

//Provides: caml_binaryen_get_element_segment
//Requires: caml_jsstring_of_string
function caml_binaryen_get_element_segment(wasm_mod, name) {
  return wasm_mod.getElementSegment(caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_get_element_segment_by_index
function caml_binaryen_get_element_segment_by_index(wasm_mod, index) {
  return wasm_mod.getElementSegmentByIndex(index);
}

//Provides: caml_binaryen_element_segment_get_name
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_element_segment_get_name(elem) {
  var element_segment_info = Binaryen.getElementSegmentInfo(elem);
  return caml_string_of_jsstring(element_segment_info.name);
}

// TODO: Implement caml_binaryen_element_segment_set_name

//Provides: caml_binaryen_element_segment_get_table
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_element_segment_get_table(elem) {
  var element_segment_info = Binaryen.getElementSegmentInfo(elem);
  return caml_string_of_jsstring(element_segment_info.table);
}

// TODO: Implement caml_binaryen_element_segment_set_table

//Provides: caml_binaryen_element_segment_get_offset
//Requires: Binaryen
function caml_binaryen_element_segment_get_offset(elem) {
  var element_segment_info = Binaryen.getElementSegmentInfo(elem);
  return element_segment_info.offset;
}

//Provides: caml_binaryen_element_segment_get_length
//Requires: Binaryen
function caml_binaryen_element_segment_get_length(elem) {
  return Binaryen._BinaryenElementSegmentGetLength(elem);
}

//Provides: caml_binaryen_element_segment_get_data
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_element_segment_get_data(elem, index) {
  var element_segment_info = Binaryen.getElementSegmentInfo(elem);
  return caml_string_of_jsstring(element_segment_info.data[index]);
}
