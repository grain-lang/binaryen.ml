external add_function_import :
  Module.t ->
  string -> string -> string -> Type.t -> Type.t -> unit
  = "caml_binaryen_add_function_import__bytecode"
  "caml_binaryen_add_function_import"
external add_table_import :
  Module.t -> string -> string -> string -> unit
  = "caml_binaryen_add_table_import"
external add_memory_import :
  Module.t -> string -> string -> string -> bool -> unit
  = "caml_binaryen_add_memory_import"
external add_global_import :
  Module.t ->
  string -> string -> string -> Type.t -> bool -> unit
  = "caml_binaryen_add_global_import__bytecode"
  "caml_binaryen_add_global_import"
