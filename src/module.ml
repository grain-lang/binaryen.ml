let _ = Callback.register "array_of_list" Array.of_list

let _ = Callback.register "array_length" Array.length

type t

type bigstring = (char, Stdlib.Bigarray.int8_unsigned_elt, Stdlib.Bigarray.c_layout) Stdlib.Bigarray.Array1.t

external create : unit -> t = "caml_binaryen_module_create"

external dispose : t -> unit = "caml_binaryen_module_dispose"

external add_custom_section : t -> string -> bytes -> unit
  = "caml_binaryen_add_custom_section"
let add_custom_section wasm_mod name data =
  let size = Stdlib.Bigarray.Array1.dim data in
  let buf = Bytes.create size in
  for i = 0 to size - 1 do
    Bytes.set buf i (Stdlib.Bigarray.Array1.unsafe_get data i)
  done;
  add_custom_section wasm_mod name buf

external parse : string -> t = "caml_binaryen_module_parse"

external print : t -> unit = "caml_binaryen_module_print"

external print_asmjs : t -> unit = "caml_binaryen_module_print_asmjs"

external validate : t -> int = "caml_binaryen_module_validate"

external optimize : t -> unit = "caml_binaryen_module_optimize"

external set_features : t -> int -> unit = "caml_binaryen_module_set_features"

let set_features wasm_mod features =
  set_features wasm_mod (List.fold_left ( lor ) 0 features)

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

external run_passes : t -> string list -> unit
  = "caml_binaryen_module_run_passes"

external auto_drop : t -> unit = "caml_binaryen_module_auto_drop"

external write : t -> string option -> bytes * string option
  = "caml_binaryen_module_write"
let write wasm_mod source_map =
  let (data, source_map) = write wasm_mod source_map in
  let size = Bytes.length data in
  let buf = Stdlib.Bigarray.Array1.create Stdlib.Bigarray.char Stdlib.Bigarray.c_layout size in
  for i = 0 to size - 1 do
    buf.{i} <- Bytes.get data i
  done;
  (buf, source_map)

external write_text : t -> string = "caml_binaryen_module_write_text"

external read : bytes -> t = "caml_binaryen_module_read"
let read data =
  let size = Stdlib.Bigarray.Array1.dim data in
  let buf = Bytes.create size in
  for i = 0 to size - 1 do
    Bytes.set buf i (Stdlib.Bigarray.Array1.unsafe_get data i)
  done;
  read buf

external interpret : t -> unit = "caml_binaryen_module_interpret"

external add_debug_info_filename : t -> string -> int
  = "caml_binaryen_module_add_debug_info_filename"

external get_debug_info_filename : t -> int -> string
  = "caml_binaryen_module_get_debug_info_filename"
