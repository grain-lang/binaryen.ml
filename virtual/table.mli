type t

type element_segment

val add_table : Module.t -> string -> int -> int -> t

val add_active_element_segment :
  Module.t -> string -> string -> string list -> Expression.t -> element_segment

val remove_element_segment : Module.t -> string -> unit

val get_num_element_segments : Module.t -> int

val get_element_segment : Module.t -> string -> element_segment

val get_element_segment_by_index : Module.t -> int -> element_segment

val element_segment_get_name : element_segment -> string

val element_segment_get_table : element_segment -> string

val element_segment_get_offset : element_segment -> Expression.t

val element_segment_get_length : element_segment -> int

val element_segment_get_data : element_segment -> int -> string
