external mvp : unit -> int = "caml_binaryen_feature_mvp"
let mvp = mvp ()

external atomics : unit -> int = "caml_binaryen_feature_atomics"
let atomics = atomics ()

external bulk_memory : unit -> int = "caml_binaryen_feature_bulk_memory"
let bulk_memory = bulk_memory ()

external mutable_globals : unit -> int = "caml_binaryen_feature_mutable_globals"
let mutable_globals = mutable_globals ()

external nontrapping_fp_to_int : unit -> int = "caml_binaryen_feature_nontrapping_fp_to_int"
let nontrapping_fp_to_int = nontrapping_fp_to_int ()

external sign_ext : unit -> int = "caml_binaryen_feature_sign_ext"
let sign_ext = sign_ext ()

external simd128 : unit -> int = "caml_binaryen_feature_simd128"
let simd128 = simd128 ()

external exception_handling : unit -> int = "caml_binaryen_feature_exception_handling"
let exception_handling = exception_handling ()

external tail_call : unit -> int = "caml_binaryen_feature_tail_call"
let tail_call = tail_call ()

external reference_types : unit -> int = "caml_binaryen_feature_reference_types"
let reference_types = reference_types ()

external multivalue : unit -> int = "caml_binaryen_feature_multivalue"
let multivalue = multivalue ()

external all : unit -> int = "caml_binaryen_feature_all"
let all = all ()

