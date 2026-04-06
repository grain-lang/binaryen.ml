type t


external get_num_segments : Module.t -> int
  = "caml_binaryen_get_num_memory_segments"

external get_segment : Module.t -> string -> t option
  = "caml_binaryen_get_data_segment"

external get_segment_by_index: Module.t -> int -> t
  = "caml_binaryen_get_data_segment_by_index"

external get_segment_name : Module.t -> t -> string
  = "caml_binaryen_data_segment_get_name"

external get_segment_byte_offset : Module.t -> t -> int option
  = "caml_binaryen_get_memory_segment_byte_offset"

external get_segment_byte_length : t -> int
  = "caml_binaryen_get_memory_segment_byte_length"

external get_segment_passive : t -> bool
  = "caml_binaryen_get_memory_segment_passive"

external get_segment_data : Module.t -> t -> bytes
  = "caml_binaryen_get_memory_segment_data"