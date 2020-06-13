type t

(** Module, name, params type, results type, locals types, body. *)
external add_function : Module.t -> string -> Type.t -> Type.t -> Type.t array -> Expression.t -> t = 
  "caml_binaryen_add_function__bytecode" "caml_binaryen_add_function"

external set_start : Module.t -> t -> unit = "caml_binaryen_set_start"

external set_debug_location : t -> Expression.t -> int -> int -> int -> unit = "caml_binaryen_function_set_debug_location"

external get_function : Module.t -> string -> t = "caml_binaryen_get_function"

external remove_function : Module.t -> string -> unit = "caml_binaryen_remove_function"

external get_num_functions : Module.t -> int = "caml_binaryen_get_num_functions"
