#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <caml/alloc.h>

#include "ocaml_helpers.h"

/* Allocating an OCaml custom block to hold the given BinaryenFunctionRef */
value alloc_BinaryenFunctionRef(BinaryenFunctionRef fun)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenFunctionRef), 0, 1);
  BinaryenFunctionRef_val(v) = fun;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenExpressionRef */
value alloc_BinaryenExpressionRef(BinaryenExpressionRef exp)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenExpressionRef), 0, 1);
  BinaryenExpressionRef_val(v) = exp;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenType */
value alloc_BinaryenType(BinaryenType typ)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenType), 0, 1);
  BinaryenType_val(v) = typ;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenGlobalRef */
value alloc_BinaryenGlobalRef(BinaryenGlobalRef exp)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenGlobalRef), 0, 1);
  BinaryenGlobalRef_val(v) = exp;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenTagRef */
value alloc_BinaryenTagRef(BinaryenTagRef exp)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenTagRef), 0, 1);
  BinaryenTagRef_val(v) = exp;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenExportRef */
value alloc_BinaryenExportRef(BinaryenExportRef exp)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenExportRef), 0, 1);
  BinaryenExportRef_val(v) = exp;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenHeapType */
value alloc_BinaryenHeapType(BinaryenHeapType typ)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenHeapType), 0, 1);
  BinaryenHeapType_val(v) = typ;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenLiteral */
value alloc_BinaryenLiteral(struct BinaryenLiteral op)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(struct BinaryenLiteral), 0, 1);
  BinaryenLiteral_val(v) = op;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenModuleRef */
value alloc_BinaryenModuleRef(BinaryenModuleRef typ)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenModuleRef), 0, 1);
  BinaryenModuleRef_val(v) = typ;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenOp */
value alloc_BinaryenOp(BinaryenOp op)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenOp), 0, 1);
  BinaryenOp_val(v) = op;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenTableRef */
value alloc_BinaryenTableRef(BinaryenTableRef table)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenTableRef), 0, 1);
  BinaryenTableRef_val(v) = table;
  return v;
}

/* Allocating an OCaml custom block to hold the given BinaryenElementSegmentRef */
value alloc_BinaryenElementSegmentRef(BinaryenElementSegmentRef elem)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(BinaryenElementSegmentRef), 0, 1);
  BinaryenElementSegmentRef_val(v) = elem;
  return v;
}

/* Allocating an OCaml custom block to hold the given TypeBuilderRef */
value alloc_TypeBuilderRef(TypeBuilderRef builder)
{
  value v = caml_alloc_custom(&binaryen_ops, sizeof(TypeBuilderRef), 0, 1);
  TypeBuilderRef_val(v) = builder;
  return v;
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
