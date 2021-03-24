type t

type element_segment

val add_table : Module.t -> string -> int -> int -> t

val add_active_element_segment :
  Module.t -> string -> string -> string list -> Expression.t -> element_segment
