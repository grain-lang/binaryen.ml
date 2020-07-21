external add_function_import :
  Module.t -> string -> string -> string -> Type.t -> Type.t -> unit
  = "caml_binaryen_add_function_import__bytecode" "caml_binaryen_add_function_import"
(** Module, internal name, external module name, external base name, params type, results type. *)

external add_table_import : Module.t -> string -> string -> string -> unit
  = "caml_binaryen_add_table_import"
(** Module, internal name, external module name, external base name. *)

external add_memory_import :
  Module.t -> string -> string -> string -> bool -> unit
  = "caml_binaryen_add_memory_import"
(** Module, internal name, external module name, external base name, shared. *)

external add_global_import :
  Module.t -> string -> string -> string -> Type.t -> bool -> unit
  = "caml_binaryen_add_global_import__bytecode" "caml_binaryen_add_global_import"
(** Module, internal name, external module name, external base name, type, mutable. *)
