#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

CAMLprim value
caml_binaryen_array_type_get_element_type(value _heapType) {
  CAMLparam1(_heapType);
  BinaryenHeapType heapType = BinaryenHeapType_val(_heapType);
  BinaryenType ty = BinaryenArrayTypeGetElementType(heapType);
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_array_type_get_element_packed_type(value _heapType) {
  CAMLparam1(_heapType);
  BinaryenHeapType heapType = BinaryenHeapType_val(_heapType);
  CAMLreturn(Val_int(BinaryenArrayTypeGetElementPackedType(heapType)));
}

CAMLprim value
caml_binaryen_array_type_is_element_mutable(value _heapType) {
  CAMLparam1(_heapType);
  BinaryenHeapType heapType = BinaryenHeapType_val(_heapType);
  CAMLreturn(Val_bool(BinaryenArrayTypeIsElementMutable(heapType)));
}
