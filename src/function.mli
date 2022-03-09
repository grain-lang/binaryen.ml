type t

val add_function :
  Module.t -> string -> Type.t -> Type.t -> Type.t array -> Expression.t -> t

val set_start : Module.t -> t -> unit
val set_debug_location : t -> Expression.t -> int -> int -> int -> unit
val get_function : Module.t -> string -> t
val get_function_by_index : Module.t -> int -> t
val remove_function : Module.t -> string -> unit
val get_num_functions : Module.t -> int
val get_name : t -> string
val get_params : t -> Type.t
val get_results : t -> Type.t
val get_num_vars : t -> int
val get_var : t -> int -> Type.t
val get_body : t -> Expression.t
val set_body : t -> Expression.t -> unit
