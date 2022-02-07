type t

external get_name : t -> string = "caml_binaryen_element_segment_get_name"
external get_table : t -> string = "caml_binaryen_element_segment_get_table"

external get_offset : t -> Expression.t
  = "caml_binaryen_element_segment_get_offset"

external get_length : t -> int = "caml_binaryen_element_segment_get_length"

external get_data : t -> int -> string
  = "caml_binaryen_element_segment_get_data"
