#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

CAMLprim value
caml_binaryen_struct_type_get_num_fields(value _heapType) {
  CAMLparam1(_heapType);
  BinaryenHeapType heapType = BinaryenHeapType_val(_heapType);
  CAMLreturn(Val_int(BinaryenStructTypeGetNumFields(heapType)));
}

CAMLprim value
caml_binaryen_struct_type_get_field_type(value _heapType, value _index) {
  CAMLparam2(_heapType, _index);
  BinaryenHeapType heapType = BinaryenHeapType_val(_heapType);
  BinaryenIndex index = Int_val(_index);
  BinaryenType ty = BinaryenStructTypeGetFieldType(heapType, index);
  CAMLreturn(alloc_BinaryenType(ty));
}

CAMLprim value
caml_binaryen_struct_type_get_field_packed_type(value _heapType, value _index) {
  CAMLparam2(_heapType, _index);
  BinaryenHeapType heapType = BinaryenHeapType_val(_heapType);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(Val_int(BinaryenStructTypeGetFieldPackedType(heapType, index)));
}

CAMLprim value
caml_binaryen_struct_type_is_field_mutable(value _heapType, value _index) {
  CAMLparam2(_heapType, _index);
  BinaryenHeapType heapType = BinaryenHeapType_val(_heapType);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(Val_bool(BinaryenStructTypeIsFieldMutable(heapType, index)));
}
