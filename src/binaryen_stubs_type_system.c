#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


CAMLprim value
caml_binaryen_type_system_equirecursive(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenTypeSystemEquirecursive()));
}

CAMLprim value
caml_binaryen_type_system_nominal(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenTypeSystemNominal()));
}

CAMLprim value
caml_binaryen_type_system_isorecursive(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenTypeSystemIsorecursive()));
}

CAMLprim value
caml_binaryen_get_type_system(value unit) {
  CAMLparam1(unit);
  CAMLreturn(Val_int(BinaryenGetTypeSystem()));
}

CAMLprim value
caml_binaryen_set_type_system(value _typeSystem) {
  CAMLparam1(_typeSystem);
  BinaryenTypeSystem typeSystem = Int_val(_typeSystem);
  BinaryenSetTypeSystem(typeSystem);
  CAMLreturn(Val_unit);
}
