val get_num_fields : Heap_type.t -> int
val get_field_type : Heap_type.t -> int -> Type.t
val get_field_packed_type : Heap_type.t -> int -> Packed_type.t
val is_field_mutable : Heap_type.t -> int -> bool
