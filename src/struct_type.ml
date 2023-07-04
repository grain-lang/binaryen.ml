external get_num_fields : Heap_type.t -> int
  = "caml_binaryen_struct_type_get_num_fields"

external get_field_type : Heap_type.t -> int -> Type.t
  = "caml_binaryen_struct_type_get_field_type"

external get_field_packed_type : Heap_type.t -> int -> Packed_type.t
  = "caml_binaryen_struct_type_get_field_packed_type"

external is_field_mutable : Heap_type.t -> int -> bool
  = "caml_binaryen_struct_type_is_field_mutable"
