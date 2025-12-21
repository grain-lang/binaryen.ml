type t

val add_table : Module.t -> string -> int -> int -> Type.t -> t
(** Module, name, initial size, maximum size, table type *)

val add_active_element_segment :
  Module.t ->
  string ->
  string ->
  string list ->
  Expression.t ->
  Element_segment.t
(** Module, table, name, function names, offset. *)

val remove_element_segment : Module.t -> string -> unit
val get_num_element_segments : Module.t -> int
val get_element_segment : Module.t -> string -> Element_segment.t
val get_element_segment_by_index : Module.t -> int -> Element_segment.t
