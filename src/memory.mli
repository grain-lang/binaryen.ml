type segment = { data : bytes; kind : segment_kind; size : int }
and segment_kind = Passive | Active of { offset : Expression.t }

val set_memory :
  Module.t -> int -> int -> string -> segment list -> bool -> unit

val has_memory : Module.t -> bool

val get_initial : Module.t -> int

val has_max : Module.t -> bool

val get_max : Module.t -> int

val is_shared : Module.t -> bool

val unlimited : int
