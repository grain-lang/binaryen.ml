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

external add_tag_import :
  Module.t -> string -> string -> string -> Type.t -> Type.t -> unit
  = "caml_binaryen_add_tag_import__bytecode" "caml_binaryen_add_tag_import"
(** Module, internal name, external module name, external base name, params type, results type. *)

external function_import_get_module : Function.t -> string
  = "caml_binaryen_function_import_get_module"

external memory_import_get_module : Module.t -> string -> string
  = "caml_binaryen_memory_import_get_module"

external global_import_get_module : Global.t -> string
  = "caml_binaryen_global_import_get_module"

external tag_import_get_module : Tag.t -> string
  = "caml_binaryen_tag_import_get_module"

external function_import_get_base : Function.t -> string
  = "caml_binaryen_function_import_get_base"

external memory_import_get_base : Module.t -> string -> string
  = "caml_binaryen_memory_import_get_base"

external global_import_get_base : Global.t -> string
  = "caml_binaryen_global_import_get_base"

external tag_import_get_base : Tag.t -> string
  = "caml_binaryen_tag_import_get_base"
