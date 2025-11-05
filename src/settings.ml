external get_optimize_level : unit -> int = "caml_binaryen_get_optimize_level"
external set_optimize_level : int -> unit = "caml_binaryen_set_optimize_level"
external get_shrink_level : unit -> int = "caml_binaryen_get_shrink_level"
external set_shrink_level : int -> unit = "caml_binaryen_set_shrink_level"
external get_debug_info : unit -> bool = "caml_binaryen_get_debug_info"
external set_debug_info : bool -> unit = "caml_binaryen_set_debug_info"

external get_traps_never_happen : unit -> bool
  = "caml_binaryen_get_traps_never_happen"

external set_traps_never_happen : bool -> unit
  = "caml_binaryen_set_traps_never_happen"

external get_closed_world : unit -> bool = "caml_binaryen_get_closed_world"
external set_closed_world : bool -> unit = "caml_binaryen_set_closed_world"

external get_low_memory_unused : unit -> bool
  = "caml_binaryen_get_low_memory_unused"

external set_low_memory_unused : bool -> unit
  = "caml_binaryen_set_low_memory_unused"

external get_zero_filled_memory : unit -> bool
  = "caml_binaryen_get_zero_filled_memory"

external set_zero_filled_memory : bool -> unit
  = "caml_binaryen_set_zero_filled_memory"

external get_fast_math : unit -> bool = "caml_binaryen_get_fast_math"
external set_fast_math : bool -> unit = "caml_binaryen_set_fast_math"

external get_generate_stack_ir : unit -> bool
  = "caml_binaryen_get_generate_stack_ir"

external set_generate_stack_ir : bool -> unit
  = "caml_binaryen_set_generate_stack_ir"

external get_optimize_stack_ir : unit -> bool
  = "caml_binaryen_get_optimize_stack_ir"

external set_optimize_stack_ir : bool -> unit
  = "caml_binaryen_set_optimize_stack_ir"

external get_pass_argument : string -> string option
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

external get_allow_inlining_functions_with_loops : unit -> bool
  = "caml_binaryen_get_allow_inlining_functions_with_loops"

external set_allow_inlining_functions_with_loops : bool -> unit
  = "caml_binaryen_set_allow_inlining_functions_with_loops"

external set_colors_enabled : bool -> unit = "caml_binaryen_set_colors_enabled"
external are_colors_enabled : unit -> bool = "caml_binaryen_are_colors_enabled"
