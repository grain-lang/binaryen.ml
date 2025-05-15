#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


CAMLprim value
caml_binaryen_module_get_features(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  CAMLreturn(Val_int(BinaryenModuleGetFeatures(module)));
}

CAMLprim value
caml_binaryen_module_set_features(value _module, value _features) {
  CAMLparam2(_module, _features);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  uint32_t features = Int_val(_features);
  BinaryenModuleSetFeatures(module, features);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_binaryen_feature_mvp(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureMVP()));
}

CAMLprim value
caml_binaryen_feature_atomics(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureAtomics()));
}

CAMLprim value
caml_binaryen_feature_bulk_memory(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureBulkMemory()));
}

CAMLprim value
caml_binaryen_feature_mutable_globals(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureMutableGlobals()));
}

CAMLprim value
caml_binaryen_feature_nontrapping_fp_to_int(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureNontrappingFPToInt()));
}

CAMLprim value
caml_binaryen_feature_sign_ext(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureSignExt()));
}

CAMLprim value
caml_binaryen_feature_simd128(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureSIMD128()));
}

CAMLprim value
caml_binaryen_feature_exception_handling(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureExceptionHandling()));
}

CAMLprim value
caml_binaryen_feature_tail_call(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureTailCall()));
}

CAMLprim value
caml_binaryen_feature_reference_types(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureReferenceTypes()));
}

CAMLprim value
caml_binaryen_feature_multivalue(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureMultivalue()));
}

CAMLprim value
caml_binaryen_feature_gc(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureGC()));
}

CAMLprim value
caml_binaryen_feature_memory64(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureMemory64()));
}

CAMLprim value
caml_binaryen_feature_relaxed_simd(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureRelaxedSIMD()));
}

CAMLprim value
caml_binaryen_feature_extended_const(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureExtendedConst()));
}

CAMLprim value
caml_binaryen_feature_strings(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureStrings()));
}

CAMLprim value
caml_binaryen_feature_multi_memory(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureMultiMemory()));
}

CAMLprim value
caml_binaryen_feature_all(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenFeatureAll()));
}
