open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

type t = int

let get_name elem =
  let element_segment_info =
    meth_call global##.binaryen "getElementSegmentInfo" [| inject elem |]
  in
  to_string (get element_segment_info "name")

let get_table elem =
  let element_segment_info =
    meth_call global##.binaryen "getElementSegmentInfo" [| inject elem |]
  in
  to_string (get element_segment_info "table")

let get_offset elem =
  let element_segment_info =
    meth_call global##.binaryen "getElementSegmentInfo" [| inject elem |]
  in
  get element_segment_info "offset"

let get_length elem =
  meth_call global##.binaryen "_BinaryenElementSegmentGetLength"
    [| inject elem |]

let get_data elem index =
  let element_segment_info =
    meth_call global##.binaryen "getElementSegmentInfo" [| inject elem |]
  in
  let data_js_array = get element_segment_info "data" in
  to_string (get data_js_array index)
