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
  to_string
    (meth_call global##.binaryen "_BinaryenElementSegmentGetName"
       [| inject elem |])

let element_segment_set_name elem name =
  meth_call global##.binaryen "_BinaryenElementSegmentSetName"
    [| inject elem; inject (string name) |]

let element_segment_get_table elem =
  to_string
    (meth_call global##.binaryen "_BinaryenElementSegmentGetTable"
       [| inject elem |])

let element_segment_set_table elem table =
  meth_call global##.binaryen "_BinaryenElementSegmentSetTable"
    [| inject elem; inject (string table) |]

let element_segment_get_offset elem =
  meth_call global##.binaryen "_BinaryenElementSegmentGetOffset"
    [| inject elem |]

let element_segment_get_length elem =
  meth_call global##.binaryen "_BinaryenElementSegmentGetLength"
    [| inject elem |]

let element_segment_get_data elem index =
  to_string
    (meth_call global##.binaryen "_BinaryenElementSegmentGetData"
       [| inject elem; inject index |])
