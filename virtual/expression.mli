type t

val block : Module.t -> string -> t list -> t

val if_ : Module.t -> t -> t -> t -> t

val loop : Module.t -> string -> t -> t

val break : Module.t -> string -> t -> t -> t

val switch : Module.t -> string list -> string -> t -> t -> t

val call : Module.t -> string -> t list -> Type.t -> t

val call_indirect : Module.t -> t -> t list -> Type.t -> Type.t -> t

val return_call : Module.t -> string -> t list -> Type.t -> t

val return_call_indirect : Module.t -> t -> t list -> Type.t -> Type.t -> t

val local_get : Module.t -> int -> Type.t -> t

val local_set : Module.t -> int -> t -> t

val local_tee : Module.t -> int -> t -> Type.t -> t

val global_get : Module.t -> string -> Type.t -> t

val global_set : Module.t -> string -> t -> t

val load : Module.t -> int -> int -> int -> Type.t -> t -> t

val store : Module.t -> int -> int -> int -> t -> t -> Type.t -> t

val const : Module.t -> Literal.t -> t

val unary : Module.t -> Op.t -> t -> t

val binary : Module.t -> Op.t -> t -> t -> t

val select : Module.t -> t -> t -> t -> t

val drop : Module.t -> t -> t

val return : Module.t -> t -> t

val memory_grow : Module.t -> t -> t

val memory_size : Module.t -> t

val nop : Module.t -> t

val unreachable : Module.t -> t

val memory_copy : Module.t -> t -> t -> t -> t

val memory_fill : Module.t -> t -> t -> t -> t

val tuple_make : Module.t -> t list -> t

val tuple_extract : Module.t -> t -> int -> t

val pop : Module.t -> Type.t -> t

val null : unit -> t

val print : t -> unit
