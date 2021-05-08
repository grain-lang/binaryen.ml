open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

type t = int

type element_segment = int

let add_table wasm_mod name initial maximum =
  meth_call wasm_mod "addTable"
    [| inject (string name); inject initial; inject maximum |]

let add_active_element_segment wasm_mod table name funcnames offset =
  meth_call wasm_mod "addActiveElementSegment"
    [|
      inject (string table);
      inject (string name);
      inject (array (Array.of_list (List.map string funcnames)));
      inject offset;
    |]

let remove_element_segment wasm_mod name =
  meth_call wasm_mod "removeElementSegment" [| inject (string name) |]

let get_num_element_segments wasm_mod =
  meth_call wasm_mod "getNumElementSegments" [||]

let get_element_segment wasm_mod name =
  meth_call wasm_mod "getElementSegment" [| inject (string name) |]

let get_element_segment_by_index wasm_mod index =
  meth_call wasm_mod "getElementSegmentByIndex" [| inject index |]

let element_segment_get_name elem =
  let element_segment_info =
    meth_call global##.binaryen "getElementSegmentInfo" [| inject elem |]
  in
  to_string (get element_segment_info "name")

let element_segment_get_table elem =
  let element_segment_info =
    meth_call global##.binaryen "getElementSegmentInfo" [| inject elem |]
  in
  to_string (get element_segment_info "table")

let element_segment_get_offset elem =
  let element_segment_info =
    meth_call global##.binaryen "getElementSegmentInfo" [| inject elem |]
  in
  get element_segment_info "offset"

let element_segment_get_length elem =
  meth_call global##.binaryen "_BinaryenElementSegmentGetLength"
    [| inject elem |]

let element_segment_get_data elem index =
  let element_segment_info =
    meth_call global##.binaryen "getElementSegmentInfo" [| inject elem |]
  in
  let data_js_array = get element_segment_info "data" in
  to_string (get data_js_array index)
