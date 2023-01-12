#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


CAMLprim value
caml_binaryen_packed_type_not_packed(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenPackedTypeNotPacked()));
}

CAMLprim value
caml_binaryen_packed_type_int8(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenPackedTypeInt8()));
}

CAMLprim value
caml_binaryen_packed_type_int16(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenPackedTypeInt16()));
}
