type t

type element_segment

external add_table : Module.t -> string -> int -> int -> t
  = "caml_binaryen_add_table"
(** Module, name, initial size, maximum size. *)

external add_active_element_segment :
  Module.t -> string -> string -> string list -> Expression.t -> element_segment
  = "caml_binaryen_add_active_element_segment"
(** Module, table, name, function names, offset. *)

external remove_element_segment : Module.t -> string -> unit
  = "caml_binaryen_remove_element_segment"

external get_num_element_segments : Module.t -> int
  = "caml_binaryen_get_num_element_segments"

external get_element_segment : Module.t -> string -> element_segment
  = "caml_binaryen_get_element_segment"

external get_element_segment_by_index : Module.t -> int -> element_segment
  = "caml_binaryen_get_element_segment_by_index"

external element_segment_get_name : element_segment -> string
  = "caml_binaryen_element_segment_get_name"

external element_segment_set_name : element_segment -> string -> unit
  = "caml_binaryen_element_segment_set_name"

external element_segment_get_table : element_segment -> string
  = "caml_binaryen_element_segment_get_table"

external element_segment_set_table : element_segment -> string -> unit
  = "caml_binaryen_element_segment_set_table"

external element_segment_get_offset : element_segment -> Expression.t
  = "caml_binaryen_element_segment_get_offset"

external element_segment_get_length : element_segment -> int
  = "caml_binaryen_element_segment_get_length"

external element_segment_get_data : element_segment -> int -> string
  = "caml_binaryen_element_segment_get_data"
