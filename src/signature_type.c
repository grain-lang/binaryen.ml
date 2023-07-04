#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

CAMLprim value
caml_binaryen_signature_type_get_params(value _heapType) {
  CAMLparam1(_heapType);
  BinaryenHeapType heapType = BinaryenHeapType_val(_heapType);
  BinaryenType ty = BinaryenSignatureTypeGetParams(heapType);
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_signature_type_get_results(value _heapType) {
  CAMLparam1(_heapType);
  BinaryenHeapType heapType = BinaryenHeapType_val(_heapType);
  BinaryenType ty = BinaryenSignatureTypeGetResults(heapType);
  CAMLreturn(alloc_BinaryenType(ty));
}
