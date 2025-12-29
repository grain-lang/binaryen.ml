val add_function_import :
  Module.t -> string -> string -> string -> Type.t -> Type.t -> unit

val add_table_import : Module.t -> string -> string -> string -> unit
val add_memory_import : Module.t -> string -> string -> string -> bool -> unit

val add_global_import :
  Module.t -> string -> string -> string -> Type.t -> bool -> unit

val add_tag_import :
  Module.t -> string -> string -> string -> Type.t -> Type.t -> unit

val function_import_get_module : Function.t -> string
val memory_import_get_module : Module.t -> string -> string
val global_import_get_module : Global.t -> string
val tag_import_get_module : Tag.t -> string
val function_import_get_base : Function.t -> string
val memory_import_get_base : Module.t -> string -> string
val global_import_get_base : Global.t -> string
val tag_import_get_base : Tag.t -> string
