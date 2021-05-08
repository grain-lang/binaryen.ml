type t

val get_name : t -> string

val get_table : t -> string

val get_offset : t -> Expression.t

val get_length : t -> int

val get_data : t -> int -> string
