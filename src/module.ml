let _ = Callback.register "array_of_list" Array.of_list
let _ = Callback.register "array_length" Array.length

type t

module Feature = struct
  type t = int

  external mvp : unit -> t = "caml_binaryen_feature_mvp"

  let mvp = mvp ()

  external atomics : unit -> t = "caml_binaryen_feature_atomics"

  let atomics = atomics ()

  external mutable_globals : unit -> t = "caml_binaryen_feature_mutable_globals"

  let mutable_globals = mutable_globals ()

  external nontrapping_fp_to_int : unit -> t
    = "caml_binaryen_feature_nontrapping_fp_to_int"

  let nontrapping_fp_to_int = nontrapping_fp_to_int ()

  external simd128 : unit -> t = "caml_binaryen_feature_simd128"

  let simd128 = simd128 ()

  external bulk_memory : unit -> t = "caml_binaryen_feature_bulk_memory"

  let bulk_memory = bulk_memory ()

  external sign_ext : unit -> t = "caml_binaryen_feature_sign_ext"

  let sign_ext = sign_ext ()

  external exception_handling : unit -> t
    = "caml_binaryen_feature_exception_handling"

  let exception_handling = exception_handling ()

  external tail_call : unit -> t = "caml_binaryen_feature_tail_call"

  let tail_call = tail_call ()

  external reference_types : unit -> t = "caml_binaryen_feature_reference_types"

  let reference_types = reference_types ()

  external multivalue : unit -> t = "caml_binaryen_feature_multivalue"

  let multivalue = multivalue ()

  external gc : unit -> t = "caml_binaryen_feature_gc"

  let gc = gc ()

  external memory64 : unit -> t = "caml_binaryen_feature_memory64"

  let memory64 = memory64 ()

  external relaxed_simd : unit -> t = "caml_binaryen_feature_relaxed_simd"

  let relaxed_simd = relaxed_simd ()

  external extended_const : unit -> t = "caml_binaryen_feature_extended_const"

  let extended_const = extended_const ()

  external strings : unit -> t = "caml_binaryen_feature_strings"

  let strings = strings ()

  external multi_memory : unit -> t = "caml_binaryen_feature_multi_memory"

  let multi_memory = multi_memory ()

  external stack_switching : unit -> t = "caml_binaryen_feature_stack_switching"

  let stack_switching = stack_switching ()

  external shared_everything : unit -> t
    = "caml_binaryen_feature_shared_everything"

  let shared_everything = shared_everything ()

  external fp16 : unit -> t = "caml_binaryen_feature_fp16"

  let fp16 = fp16 ()

  external bulk_memory_opt : unit -> t = "caml_binaryen_feature_bulk_memory_opt"

  let bulk_memory_opt = bulk_memory_opt ()

  external call_indirect_overlong : unit -> t
    = "caml_binaryen_feature_call_indirect_overlong"

  let call_indirect_overlong = call_indirect_overlong ()

  external all : unit -> t = "caml_binaryen_feature_all"

  let all = all ()
end

external create : unit -> t = "caml_binaryen_module_create"
external dispose : t -> unit = "caml_binaryen_module_dispose"

external add_custom_section : t -> string -> string -> unit
  = "caml_binaryen_add_custom_section"

external parse : string -> t = "caml_binaryen_module_parse"
external print : t -> unit = "caml_binaryen_module_print"
external print_asmjs : t -> unit = "caml_binaryen_module_print_asmjs"
external print_stack_ir : t -> unit = "caml_binaryen_module_print_stack_ir"
external validate : t -> int = "caml_binaryen_module_validate"
external optimize : t -> unit = "caml_binaryen_module_optimize"
external get_features : t -> int = "caml_binaryen_module_get_features"

let get_features wasm_mod =
  let features_int = get_features wasm_mod in
  let rec split_features = function
    | 0 -> []
    | feature when features_int land feature > 0 ->
        feature :: split_features (feature lsr 1)
    | feature -> split_features (feature lsr 1)
  in
  (* Support 32-bit OCaml where integers are 31 bits *)
  (* This supports up to 31 Binaryen features *)
  split_features 0x40000000

external set_features : t -> int -> unit = "caml_binaryen_module_set_features"

let set_features wasm_mod features =
  set_features wasm_mod (List.fold_left ( lor ) 0 features)

external run_passes : t -> Passes.t list -> unit
  = "caml_binaryen_module_run_passes"

external write : t -> string option -> bytes * string option
  = "caml_binaryen_module_write"

external write_text : t -> string = "caml_binaryen_module_write_text"
external write_stack_ir : t -> string = "caml_binaryen_module_write_stack_ir"
external read : bytes -> t = "caml_binaryen_module_read"
external interpret : t -> unit = "caml_binaryen_module_interpret"

external add_debug_info_filename : t -> string -> int
  = "caml_binaryen_module_add_debug_info_filename"

external get_debug_info_filename : t -> int -> string
  = "caml_binaryen_module_get_debug_info_filename"

external update_maps : t -> unit = "caml_binaryen_module_update_maps"
