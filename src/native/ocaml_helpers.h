#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <caml/alloc.h>
#include <caml/custom.h>

#include <string.h>

#include <binaryen-c.h>

static struct custom_operations binaryen_ops;

#define BinaryenModuleRef_val(v) (*((BinaryenModuleRef*) Data_custom_val(v)))
#define BinaryenType_val(v) (*((BinaryenType*) Data_custom_val(v)))
#define BinaryenExpressionRef_val(v) (*((BinaryenExpressionRef*) Data_custom_val(v)))
#define BinaryenOp_val(v) (*((BinaryenOp*) Data_custom_val(v)))
#define BinaryenLiteral_val(v) (*((struct BinaryenLiteral*) Data_custom_val(v)))
#define BinaryenFunctionRef_val(v) (*((BinaryenFunctionRef*) Data_custom_val(v)))
#define BinaryenGlobalRef_val(v) (*((BinaryenGlobalRef*) Data_custom_val(v)))
#define BinaryenExportRef_val(v) (*((BinaryenExportRef*) Data_custom_val(v)))

#define Val_none Val_int(0)
#define Some_val(v) Field(v, 0)
#define Tag_some 0
#define Is_none(v) ((v) == Val_none)
#define Is_some(v) Is_block(v)

#define Safe_String_val(v) strdup(String_val(v))

CAMLprim value
caml_alloc_some(value v);

CAMLprim value
array_of_list(value list);

int array_length(value array);
