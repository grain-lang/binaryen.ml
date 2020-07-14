type t
external add_global :
  Module.t ->
  string -> Type.t -> bool -> Expression.t -> t
  = "caml_binaryen_add_global"
external get_global : Module.t -> string -> t
  = "caml_binaryen_get_global"
external remove_global : Module.t -> string -> unit
  = "caml_binaryen_remove_global"
