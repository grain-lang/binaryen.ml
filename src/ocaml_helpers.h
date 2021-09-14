#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <caml/alloc.h>
#include <caml/custom.h>

#include <string.h>

#include "binaryen-c.h"

static struct custom_operations binaryen_ops = {
  "com.binaryen.caml",
  custom_finalize_default,
  custom_compare_default,
  custom_hash_default,
  custom_serialize_default,
  custom_deserialize_default,
  custom_compare_ext_default,
  custom_fixed_length_default
};

#define BinaryenModuleRef_val(v) (*((BinaryenModuleRef*) Data_custom_val(v)))
#define BinaryenType_val(v) (*((BinaryenType*) Data_custom_val(v)))
#define BinaryenExpressionRef_val(v) (*((BinaryenExpressionRef*) Data_custom_val(v)))
#define BinaryenOp_val(v) (*((BinaryenOp*) Data_custom_val(v)))
#define BinaryenLiteral_val(v) (*((struct BinaryenLiteral*) Data_custom_val(v)))
#define BinaryenFunctionRef_val(v) (*((BinaryenFunctionRef*) Data_custom_val(v)))
#define BinaryenGlobalRef_val(v) (*((BinaryenGlobalRef*) Data_custom_val(v)))
#define BinaryenExportRef_val(v) (*((BinaryenExportRef*) Data_custom_val(v)))
#define BinaryenTableRef_val(v) (*((BinaryenTableRef*) Data_custom_val(v)))
#define BinaryenElementSegmentRef_val(v) (*((BinaryenElementSegmentRef*) Data_custom_val(v)))

#define Val_none Val_int(0)
#define Some_val(v) Field(v, 0)
#define Tag_some 0
#define Is_none(v) ((v) == Val_none)
#define Is_some(v) Is_block(v)

#define Safe_String_val(v) ((char *)memcpy(malloc(caml_string_length(v) + 1), String_val(v), caml_string_length(v) + 1))

CAMLprim value
array_of_list(value list);

int array_length(value array);
