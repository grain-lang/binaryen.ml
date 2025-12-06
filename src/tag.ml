type t

external add_tag : Module.t -> string -> Type.t -> Type.t -> t
  = "caml_binaryen_add_tag"
(** Module, name, params, result *)

external get_tag : Module.t -> string -> t = "caml_binaryen_get_tag"
external remove_tag : Module.t -> string -> unit = "caml_binaryen_remove_tag"
external get_name : t -> string = "caml_binaryen_tag_get_name"
external get_params : t -> Type.t = "caml_binaryen_tag_get_params"
external get_results : t -> Type.t = "caml_binaryen_tag_get_results"
