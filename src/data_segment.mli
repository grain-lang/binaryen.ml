type t

val get_num_segments : Module.t -> int
val get_segment : Module.t -> string -> t option
val get_segment_by_index : Module.t -> int -> t
val get_segment_name : Module.t -> t -> string
val get_segment_byte_offset : Module.t -> t -> int option
val get_segment_byte_length : t -> int
val get_segment_passive : t -> bool
val get_segment_data : Module.t -> t -> bytes