type segment = { name : string; data : bytes; kind : segment_kind; size : int }
and segment_kind = Passive | Active of { offset : Expression.t }

val set_memory :
  Module.t ->
  int ->
  int ->
  string ->
  segment list ->
  bool ->
  bool ->
  string ->
  unit

val has_memory : Module.t -> bool
val get_initial : Module.t -> string -> int
val has_max : Module.t -> string -> bool
val get_max : Module.t -> string -> int
val is_shared : Module.t -> string -> bool
val is_64 : Module.t -> string -> bool
val unlimited : int
val get_num_segments : Module.t -> int
val get_segment_byte_offset : Module.t -> string -> int
val get_segment_passive : Module.t -> string -> bool
val get_segment_data : Module.t -> string -> bytes
