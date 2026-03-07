type t

val ext : unit -> t
val func : unit -> t
val any : unit -> t
val eq : unit -> t
val i31 : unit -> t
val struct_ : unit -> t
val array : unit -> t
val string : unit -> t
val none : unit -> t
val noext : unit -> t
val nofunc : unit -> t
val is_basic : t -> bool
val is_signature : t -> bool
val is_struct : t -> bool
val is_array : t -> bool
val is_bottom : t -> bool
val get_bottom : t -> t
val is_sub_type : t -> bool

val set_type_name : Module.t -> t -> string -> unit
(** Sets the textual name of a compound `heapType`. Has no effect if the type
    already has a canonical name. *)

val set_field_name : Module.t -> t -> int -> string -> unit
(** Sets the field name of a struct `heapType` at index `index`. *)
