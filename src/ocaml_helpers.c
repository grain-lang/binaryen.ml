#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/callback.h>

#include "ocaml_helpers.h"


CAMLprim value
caml_alloc_some(value v) {
  CAMLparam1(v);
  value some = caml_alloc_small(1, 0);
  Store_field(some, 0, v);
  CAMLreturn(some);
}

CAMLprim value
array_of_list(value list) {
  CAMLparam1(list);
  static const value *closure_f = NULL;
  if (closure_f == NULL) {
      /* First time around, look up by name */
      closure_f = caml_named_value("array_of_list");
  }
  CAMLreturn(caml_callback(*closure_f, list));
}

int array_length(value array) {
  CAMLparam1(array);
  static const value * closure_f = NULL;
  if (closure_f == NULL) {
    /* First time around, look up by name */
    closure_f = caml_named_value("array_length");
  }
  CAMLlocal1(res);
  res = caml_callback(*closure_f, array);
  CAMLreturnT(int, Int_val(res));
}
