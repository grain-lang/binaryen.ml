type t

val add_function_export : Module.t -> string -> string -> t

val add_table_export : Module.t -> string -> string -> t

val add_memory_export : Module.t -> string -> string -> t

val add_global_export : Module.t -> string -> string -> t

val remove_export : Module.t -> string -> unit
