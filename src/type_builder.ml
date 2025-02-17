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

external make : int -> t = "caml_type_builder_create"
external grow : t -> int -> unit = "caml_type_builder_grow"
external size : t -> int = "caml_type_builder_grow"

external set_signature_type : t -> int -> Type.t -> Type.t -> unit
  = "caml_type_builder_set_signature_type"

external set_struct_type :
  t -> int -> Type.t list -> Packed_type.t list -> bool list -> int -> unit
  = "caml_type_builder_set_struct_type__bytecode" "caml_type_builder_set_struct_type"

let set_struct_type builder index fields =
  let split_fields fields =
    List.fold_right
      (fun { type_; packed_type; mutable_ } (types, packed_types, mutables) ->
        (type_ :: types, packed_type :: packed_types, mutable_ :: mutables))
      fields ([], [], [])
  in
  let types, packed_types, mutables = split_fields fields in
  set_struct_type builder index types packed_types mutables (List.length types)

external set_array_type : t -> int -> Type.t -> Packed_type.t -> bool -> unit
  = "caml_type_builder_set_array_type"

external get_temp_heap_type : t -> int -> Heap_type.t
  = "caml_type_builder_get_temp_heap_type"

external get_temp_tuple_type : t -> Type.t list -> Type.t
  = "caml_type_builder_get_temp_tuple_type"

external get_temp_ref_type : t -> Heap_type.t -> bool -> Type.t
  = "caml_type_builder_get_temp_ref_type"

external set_sub_type : t -> int -> Type.t -> unit
  = "caml_type_builder_set_sub_type"

external set_open : t -> int -> unit = "caml_type_builder_set_open"

external create_rec_group : t -> int -> int -> unit
  = "caml_type_builder_create_rec_group"

external build_and_dispose : t -> (Type.t array, int * int) result
  = "caml_type_builder_build_and_dispose"

let build_and_dispose builder =
  match build_and_dispose builder with
  | Ok types -> Ok (Array.to_list types)
  | Error (idx, 0) -> Error (SelfSupertype idx)
  | Error (idx, 1) -> Error (InvalidSupertype idx)
  | Error (idx, 2) -> Error (ForwardSupertypeReference idx)
  | Error (idx, _) -> Error (ForwardChildReference idx)
