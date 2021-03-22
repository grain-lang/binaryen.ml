type t

external add_global : Module.t -> string -> Type.t -> bool -> Expression.t -> t
  = "caml_binaryen_add_global"
(** Module, name, type, mutable, value. *)

external get_global : Module.t -> string -> t = "caml_binaryen_get_global"

external remove_global : Module.t -> string -> unit
  = "caml_binaryen_remove_global"

external get_num_globals : Module.t -> int = "caml_binaryen_get_num_globals"

external get_global_by_index : Module.t -> int -> t
  = "caml_binaryen_get_global_by_index"

external get_name : t -> string = "caml_binaryen_global_get_name"

external get_type : t -> Type.t = "caml_binaryen_global_get_type"

external is_mutable : t -> bool = "caml_binaryen_global_is_mutable"

external get_init_expr : t -> Expression.t
  = "caml_binaryen_global_get_init_expr"
