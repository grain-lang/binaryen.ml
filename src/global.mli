type t

val add_global : Module.t -> string -> Type.t -> bool -> Expression.t -> t
val get_global : Module.t -> string -> t
val remove_global : Module.t -> string -> unit
val get_num_globals : Module.t -> int
val get_global_by_index : Module.t -> int -> t
val get_name : t -> string
val get_type : t -> Type.t
val is_mutable : t -> bool
val get_init_expr : t -> Expression.t
