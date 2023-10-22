type t

val add_tag : Module.t -> string -> Type.t -> Type.t -> t
val get_tag : Module.t -> string -> t
val remove_tag : Module.t -> string -> unit
val get_name : t -> string
val get_params : t -> Type.t
val get_results : t -> Type.t

