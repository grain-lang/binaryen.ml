//Provides: caml_binaryen_module_get_features
function caml_binaryen_module_get_features(wasm_mod) {
  return wasm_mod.getFeatures();
}

//Provides: caml_binaryen_module_set_features
function caml_binaryen_module_set_features(wasm_mod, features) {
  return wasm_mod.setFeatures(features);
}

//Provides: caml_binaryen_feature_mvp
//Requires: Binaryen
function caml_binaryen_feature_mvp() {
  return Binaryen.Features.MVP;
}

//Provides: caml_binaryen_feature_atomics
//Requires: Binaryen
function caml_binaryen_feature_atomics() {
  return Binaryen.Features.Atomics;
}

//Provides: caml_binaryen_feature_bulk_memory
//Requires: Binaryen
function caml_binaryen_feature_bulk_memory() {
  return Binaryen.Features.BulkMemory;
}

//Provides: caml_binaryen_feature_mutable_globals
//Requires: Binaryen
function caml_binaryen_feature_mutable_globals() {
  return Binaryen.Features.MutableGlobals;
}

//Provides: caml_binaryen_feature_nontrapping_fp_to_int
//Requires: Binaryen
function caml_binaryen_feature_nontrapping_fp_to_int() {
  return Binaryen.Features.NontrappingFPToInt;
}

//Provides: caml_binaryen_feature_sign_ext
//Requires: Binaryen
function caml_binaryen_feature_sign_ext() {
  return Binaryen.Features.SignExt;
}

//Provides: caml_binaryen_feature_simd128
//Requires: Binaryen
function caml_binaryen_feature_simd128() {
  return Binaryen.Features.SIMD128;
}

//Provides: caml_binaryen_feature_exception_handling
//Requires: Binaryen
function caml_binaryen_feature_exception_handling() {
  return Binaryen.Features.ExceptionHandling;
}

//Provides: caml_binaryen_feature_tail_call
//Requires: Binaryen
function caml_binaryen_feature_tail_call() {
  return Binaryen.Features.TailCall;
}

//Provides: caml_binaryen_feature_reference_types
//Requires: Binaryen
function caml_binaryen_feature_reference_types() {
  return Binaryen.Features.ReferenceTypes;
}

//Provides: caml_binaryen_feature_multivalue
//Requires: Binaryen
function caml_binaryen_feature_multivalue() {
  return Binaryen.Features.Multivalue;
}

//Provides: caml_binaryen_feature_gc
//Requires: Binaryen
function caml_binaryen_feature_gc() {
  return Binaryen.Features.GC;
}

//Provides: caml_binaryen_feature_memory64
//Requires: Binaryen
function caml_binaryen_feature_memory64() {
  return Binaryen.Features.Memory64;
}

//Provides: caml_binaryen_feature_typed_function_references
//Requires: Binaryen
function caml_binaryen_feature_typed_function_references() {
  return Binaryen.Features.TypedFunctionReferences;
}

//Provides: caml_binaryen_feature_relaxed_simd
//Requires: Binaryen
function caml_binaryen_feature_relaxed_simd() {
  return Binaryen.Features.RelaxedSIMD;
}

//Provides: caml_binaryen_feature_extended_const
//Requires: Binaryen
function caml_binaryen_feature_extended_const() {
  return Binaryen.Features.ExtendedConst;
}

//Provides: caml_binaryen_feature_all
//Requires: Binaryen
function caml_binaryen_feature_all() {
  return Binaryen.Features.All;
}
