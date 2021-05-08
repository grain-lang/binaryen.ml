external get_optimize_level : unit -> int = "caml_binaryen_get_optimize_level"

external set_optimize_level : int -> unit = "caml_binaryen_set_optimize_level"

external get_shrink_level : unit -> int = "caml_binaryen_get_shrink_level"

external set_shrink_level : int -> unit = "caml_binaryen_set_shrink_level"

external get_debug_info : unit -> int = "caml_binaryen_get_debug_info"

external set_debug_info : int -> unit = "caml_binaryen_set_debug_info"

external get_low_memory_unused : unit -> int
  = "caml_binaryen_get_low_memory_unused"

external set_low_memory_unused : int -> unit
  = "caml_binaryen_set_low_memory_unused"

external get_pass_argument : string -> string
  = "caml_binaryen_get_pass_argument"

external set_pass_argument : string -> string -> unit
  = "caml_binaryen_set_pass_argument"

external get_always_inline_max_size : unit -> int
  = "caml_binaryen_get_always_inline_max_size"

external set_always_inline_max_size : int -> unit
  = "caml_binaryen_set_always_inline_max_size"

external get_flexible_inline_max_size : unit -> int
  = "caml_binaryen_get_flexible_inline_max_size"

external set_flexible_inline_max_size : int -> unit
  = "caml_binaryen_set_flexible_inline_max_size"

external get_one_caller_inline_max_size : unit -> int
  = "caml_binaryen_get_one_caller_inline_max_size"

external set_one_caller_inline_max_size : int -> unit
  = "caml_binaryen_set_one_caller_inline_max_size"

external set_colors_enabled : int -> unit = "caml_binaryen_set_colors_enabled"

external are_colors_enabled : unit -> int = "caml_binaryen_are_colors_enabled"
