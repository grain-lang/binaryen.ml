type segment = { data : bytes; kind : segment_kind; size : int }
and segment_kind = Passive | Active of { offset : Expression.t }

val set_memory :
  Module.t -> int -> int -> string -> segment list -> bool -> unit

val unlimited : int
