external get_element_type : Heap_type.t -> Type.t
  = "caml_binaryen_array_type_get_element_type"

external get_element_packed_type : Heap_type.t -> Packed_type.t
  = "caml_binaryen_array_type_get_element_packed_type"

external is_element_mutable : Heap_type.t -> bool
  = "caml_binaryen_array_type_is_element_mutable"
