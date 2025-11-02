type t

external add_function :
  Module.t -> string -> Type.t -> Type.t -> Type.t array -> Expression.t -> t
  = "caml_binaryen_add_function__bytecode" "caml_binaryen_add_function"
(** Module, name, params type, results type, locals types, body. *)

external set_start : Module.t -> t -> unit = "caml_binaryen_set_start"

external get_start : Module.t -> t = "caml_binaryen_get_start"

external set_debug_location : t -> Expression.t -> int -> int -> int -> unit
  = "caml_binaryen_function_set_debug_location"

external get_function : Module.t -> string -> t = "caml_binaryen_get_function"

external get_function_by_index : Module.t -> int -> t
  = "caml_binaryen_get_function_by_index"

external remove_function : Module.t -> string -> unit
  = "caml_binaryen_remove_function"

external get_num_functions : Module.t -> int = "caml_binaryen_get_num_functions"
external get_name : t -> string = "caml_binaryen_function_get_name"
external get_params : t -> Type.t = "caml_binaryen_function_get_params"
external get_results : t -> Type.t = "caml_binaryen_function_get_results"
external get_num_vars : t -> int = "caml_binaryen_function_get_num_vars"
external get_var : t -> int -> Type.t = "caml_binaryen_function_get_var"
external get_body : t -> Expression.t = "caml_binaryen_function_get_body"

external set_body : t -> Expression.t -> unit
  = "caml_binaryen_function_set_body"
