#define CAML_NAME_SPACE
#include <caml/alloc.h>
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"

CAMLprim value
caml_type_builder_create(value _size) {
  CAMLparam1(_size);
  BinaryenIndex size = Int_val(_size);
  CAMLreturn(alloc_TypeBuilderRef(TypeBuilderCreate(size)));
}

CAMLprim value
caml_type_builder_grow(value _builder, value _count) {
  CAMLparam2(_builder, _count);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  BinaryenIndex count = Int_val(_count);
  TypeBuilderGrow(builder, count);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_type_builder_get_size(value _builder) {
  CAMLparam1(_builder);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  CAMLreturn(Val_int(TypeBuilderGetSize(builder)));
}

CAMLprim value
caml_type_builder_set_signature_type(value _builder, value _index, value _paramTypes, value _resultTypes) {
  CAMLparam4(_builder, _index, _paramTypes, _resultTypes);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  BinaryenIndex index = Int_val(_index);
  BinaryenType paramTypes = BinaryenType_val(_paramTypes);
  BinaryenType resultTypes = BinaryenType_val(_resultTypes);
  TypeBuilderSetSignatureType(builder, index, paramTypes, resultTypes);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_type_builder_set_struct_type(value _builder, value _index, value _fieldTypes, value _fieldPackedTypes, value _fieldMutables, value _numFields) {
  CAMLparam5(_builder, _index, _fieldTypes, _fieldPackedTypes, _fieldMutables);
  CAMLxparam1(_numFields);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  BinaryenIndex index = Int_val(_index);
  _fieldTypes = array_of_list(_fieldTypes);
  int fieldTypesLen = array_length(_fieldTypes);
  BinaryenType fieldTypes[fieldTypesLen];
  for (int i = 0; i < fieldTypesLen; i++) {
    fieldTypes[i] = BinaryenType_val(Field(_fieldTypes, i));
  }
  _fieldPackedTypes = array_of_list(_fieldPackedTypes);
  int fieldPackedTypesLen = array_length(_fieldPackedTypes);
  BinaryenPackedType fieldPackedTypes[fieldPackedTypesLen];
  for (int i = 0; i < fieldPackedTypesLen; i++) {
    fieldPackedTypes[i] = BinaryenPackedType_val(Field(_fieldPackedTypes, i));
  }
  _fieldMutables = array_of_list(_fieldMutables);
  int fieldMutablesLen = array_length(_fieldMutables);
  bool fieldMutables[fieldMutablesLen];
  for (int i = 0; i < fieldMutablesLen; i++) {
    fieldMutables[i] = Bool_val(Field(_fieldMutables, i));
  }
  int numFields = Int_val(_numFields);
  TypeBuilderSetStructType(builder, index, fieldTypes, fieldPackedTypes, fieldMutables, numFields);
  CAMLreturn(Val_unit);
}
CAMLprim value
caml_type_builder_set_struct_type__bytecode(value * argv) {
  return caml_type_builder_set_struct_type(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

CAMLprim value
caml_type_builder_set_array_type(value _builder, value _index, value _elementType, value _elementPackedType, value _elementMutable) {
  CAMLparam5(_builder, _index, _elementType, _elementPackedType, _elementMutable);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  BinaryenIndex index = Int_val(_index);
  BinaryenType elementType = BinaryenType_val(_elementType);
  BinaryenPackedType elementPackedType = BinaryenPackedType_val(_elementPackedType);
  bool elementMutable = Bool_val(_elementMutable);
  TypeBuilderSetArrayType(builder, index, elementType, elementPackedType, elementMutable);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_type_builder_get_temp_heap_type(value _builder, value _index) {
  CAMLparam2(_builder, _index);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  BinaryenIndex index = Int_val(_index);
  CAMLreturn(alloc_BinaryenHeapType(TypeBuilderGetTempHeapType(builder, index)));
}

CAMLprim value
caml_type_builder_get_temp_tuple_type(value _builder, value _types, value _numTypes) {
  CAMLparam3(_builder, _types, _numTypes);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  _types = array_of_list(_types);
  int typesLen = array_length(_types);
  BinaryenType types[typesLen];
  for (int i = 0; i < typesLen; i++) {
    types[i] = BinaryenType_val(Field(_types, i));
  }
  int numTypes = Int_val(_numTypes);
  CAMLreturn(alloc_BinaryenType(TypeBuilderGetTempTupleType(builder, types, numTypes)));
}

CAMLprim value
caml_type_builder_get_temp_ref_type(value _builder, value _heapType, value _nullable) {
  CAMLparam3(_builder, _heapType, _nullable);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  BinaryenHeapType heapType = BinaryenHeapType_val(_heapType);
  bool nullable = Bool_val(_nullable);
  CAMLreturn(alloc_BinaryenType(TypeBuilderGetTempRefType(builder, heapType, nullable)));
}

CAMLprim value
caml_type_builder_set_sub_type(value _builder, value _index, value _superType) {
  CAMLparam3(_builder, _index, _superType);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  BinaryenIndex index = Int_val(_index);
  BinaryenHeapType superType = BinaryenHeapType_val(_superType);
  TypeBuilderSetSubType(builder, index, superType);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_type_builder_set_open(value _builder, value _index) {
  CAMLparam2(_builder, _index);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  BinaryenIndex index = Int_val(_index);
  TypeBuilderSetOpen(builder, index);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_type_builder_create_rec_group(value _builder, value _index, value _length) {
  CAMLparam3(_builder, _index, _length);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  BinaryenIndex index = Int_val(_index);
  BinaryenIndex length = Int_val(_length);
  TypeBuilderCreateRecGroup(builder, index, length);
  CAMLreturn(Val_unit);
}

CAMLprim value
caml_conv_heap_type(BinaryenHeapType heapType) {
  return alloc_BinaryenHeapType(heapType);
}

CAMLprim value
caml_type_builder_build_and_dispose(value _builder) {
  CAMLparam1(_builder);
  TypeBuilderRef builder = TypeBuilderRef_val(_builder);
  BinaryenIndex size = TypeBuilderGetSize(builder);
  BinaryenHeapType heapTypes[size + 1];
  heapTypes[size] = (BinaryenHeapType) NULL;
  BinaryenIndex errorIndex;
  TypeBuilderErrorReason errorReason;
  bool success = TypeBuilderBuildAndDispose(builder, heapTypes, &errorIndex, &errorReason);
  if (success) {
    value ok = caml_alloc_small(1, 0);
    Field(ok, 0) = caml_alloc_array((void*)caml_conv_heap_type, (char const **)heapTypes);
    CAMLreturn(ok);
  } else {
    value error = caml_alloc_small(1, 1);
    value tuple = caml_alloc_small(2, 0);
    Field(tuple, 0) = Val_int(errorIndex);
    Field(tuple, 1) = Val_int(errorReason);
    Field(error, 0) = tuple;
    CAMLreturn(error);
  }
}
