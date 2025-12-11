type t

type struct_field = {
  type_ : Type.t;
  packed_type : Packed_type.t;
  mutable_ : bool;
}

type error =
  | SelfSupertype of int
  | InvalidSupertype of int
  | ForwardSupertypeReference of int
  | ForwardChildReference of int

val make : int -> t
val grow : t -> int -> unit
val size : t -> int
val set_signature_type : t -> int -> Type.t -> Type.t -> unit
val set_struct_type : t -> int -> struct_field list -> unit
val set_array_type : t -> int -> Type.t -> Packed_type.t -> bool -> unit
val get_temp_heap_type : t -> int -> Heap_type.t
val get_temp_tuple_type : t -> Type.t list -> Type.t
val get_temp_ref_type : t -> Heap_type.t -> bool -> Type.t
val set_sub_type : t -> int -> Type.t -> unit
val set_open : t -> int -> unit
val create_rec_group : t -> int -> int -> unit
val build_and_dispose : t -> (Type.t list, error) result
