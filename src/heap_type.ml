type t

external ext : unit -> t = "caml_binaryen_heap_type_ext"
external func : unit -> t = "caml_binaryen_heap_type_func"
external any : unit -> t = "caml_binaryen_heap_type_any"
external eq : unit -> t = "caml_binaryen_heap_type_eq"
external i31 : unit -> t = "caml_binaryen_heap_type_i31"
external struct_ : unit -> t = "caml_binaryen_heap_type_struct"
external array : unit -> t = "caml_binaryen_heap_type_array"
external string : unit -> t = "caml_binaryen_heap_type_string"
external none : unit -> t = "caml_binaryen_heap_type_none"
external noext : unit -> t = "caml_binaryen_heap_type_noext"
external nofunc : unit -> t = "caml_binaryen_heap_type_nofunc"
external is_basic : t -> bool = "caml_binaryen_heap_type_is_basic"
external is_signature : t -> bool = "caml_binaryen_heap_type_is_signature"
external is_struct : t -> bool = "caml_binaryen_heap_type_is_struct"
external is_array : t -> bool = "caml_binaryen_heap_type_is_array"
external is_bottom : t -> bool = "caml_binaryen_heap_type_is_bottom"
external get_bottom : t -> t = "caml_binaryen_heap_type_get_bottom"
external is_sub_type : t -> bool = "caml_binaryen_heap_type_is_sub_type"

external set_type_name : Module.t -> t -> string -> unit
  = "caml_binaryen_module_set_type_name"
(** Sets the textual name of a compound `heapType`. Has no effect if the type
    already has a canonical name. *)

external set_field_name : Module.t -> t -> int -> string -> unit
  = "caml_binaryen_module_set_field_name"
(** Sets the field name of a struct `heapType` at index `index`. *)
