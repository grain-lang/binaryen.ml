external set_function_table :
  Module.t ->
  int -> int -> string list -> Expression.t -> unit
  = "caml_binaryen_set_function_table"
