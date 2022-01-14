type t

external add_table : Module.t -> string -> int -> int -> Type.t -> t
  = "caml_binaryen_add_table"
(** Module, name, initial size, maximum size, table type *)

external add_active_element_segment :
  Module.t ->
  string ->
  string ->
  string list ->
  Expression.t ->
  Element_segment.t = "caml_binaryen_add_active_element_segment"
(** Module, table, name, function names, offset. *)

external remove_element_segment : Module.t -> string -> unit
  = "caml_binaryen_remove_element_segment"

external get_num_element_segments : Module.t -> int
  = "caml_binaryen_get_num_element_segments"

external get_element_segment : Module.t -> string -> Element_segment.t
  = "caml_binaryen_get_element_segment"

external get_element_segment_by_index : Module.t -> int -> Element_segment.t
  = "caml_binaryen_get_element_segment_by_index"
