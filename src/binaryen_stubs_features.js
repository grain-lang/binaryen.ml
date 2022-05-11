//Provides: caml_binaryen_module_get_features
function caml_binaryen_module_get_features(wasm_mod) {
  return wasm_mod.getFeatures();
}

//Provides: caml_binaryen_module_set_features
function caml_binaryen_module_set_features(wasm_mod, features) {
  return wasm_mod.setFeatures(features);
}

//Provides: caml_binaryen_feature_mvp
//Requires: binaryen
function caml_binaryen_feature_mvp() {
  return binaryen.Features.MVP;
}

//Provides: caml_binaryen_feature_atomics
//Requires: binaryen
function caml_binaryen_feature_atomics() {
  return binaryen.Features.Atomics;
}

//Provides: caml_binaryen_feature_bulk_memory
//Requires: binaryen
function caml_binaryen_feature_bulk_memory() {
  return binaryen.Features.BulkMemory;
}

//Provides: caml_binaryen_feature_mutable_globals
//Requires: binaryen
function caml_binaryen_feature_mutable_globals() {
  return binaryen.Features.MutableGlobals;
}

//Provides: caml_binaryen_feature_nontrapping_fp_to_int
//Requires: binaryen
function caml_binaryen_feature_nontrapping_fp_to_int() {
  return binaryen.Features.NontrappingFPToInt;
}

//Provides: caml_binaryen_feature_sign_ext
//Requires: binaryen
function caml_binaryen_feature_sign_ext() {
  return binaryen.Features.SignExt;
}

//Provides: caml_binaryen_feature_simd128
//Requires: binaryen
function caml_binaryen_feature_simd128() {
  return binaryen.Features.SIMD128;
}

//Provides: caml_binaryen_feature_exception_handling
//Requires: binaryen
function caml_binaryen_feature_exception_handling() {
  return binaryen.Features.ExceptionHandling;
}

//Provides: caml_binaryen_feature_tail_call
//Requires: binaryen
function caml_binaryen_feature_tail_call() {
  return binaryen.Features.TailCall;
}

//Provides: caml_binaryen_feature_reference_types
//Requires: binaryen
function caml_binaryen_feature_reference_types() {
  return binaryen.Features.ReferenceTypes;
}

//Provides: caml_binaryen_feature_multivalue
//Requires: binaryen
function caml_binaryen_feature_multivalue() {
  return binaryen.Features.Multivalue;
}

//Provides: caml_binaryen_feature_gc
//Requires: binaryen
function caml_binaryen_feature_gc() {
  return binaryen.Features.GC;
}

//Provides: caml_binaryen_feature_memory64
//Requires: binaryen
function caml_binaryen_feature_memory64() {
  return binaryen.Features.Memory64;
}

//Provides: caml_binaryen_feature_typed_function_references
//Requires: binaryen
function caml_binaryen_feature_typed_function_references() {
  return binaryen.Features.TypedFunctionReferences;
}

//Provides: caml_binaryen_feature_relaxed_simd
//Requires: binaryen
function caml_binaryen_feature_relaxed_simd() {
  return binaryen.Features.RelaxedSIMD;
}

//Provides: caml_binaryen_feature_extended_const
//Requires: binaryen
function caml_binaryen_feature_extended_const() {
  return binaryen.Features.ExtendedConst;
}

//Provides: caml_binaryen_feature_all
//Requires: binaryen
function caml_binaryen_feature_all() {
  return binaryen.Features.All;
}
