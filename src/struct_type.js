//Provides: caml_binaryen_struct_type_get_num_fields
//Requires: Binaryen
function caml_binaryen_struct_type_get_num_fields(heapType) {
  return Binaryen._BinaryenStructTypeGetNumFields(heapType);
}

//Provides: caml_binaryen_struct_type_get_field_type
//Requires: Binaryen
function caml_binaryen_struct_type_get_field_type(heapType, index) {
  return Binaryen._BinaryenStructTypeGetFieldType(heapType, index);
}

//Provides: caml_binaryen_struct_type_get_field_packed_type
//Requires: Binaryen
function caml_binaryen_struct_type_get_field_packed_type(heapType, index) {
  return Binaryen._BinaryenStructTypeGetFieldPackedType(heapType, index);
}

//Provides: caml_binaryen_struct_type_is_field_mutable
//Requires: Binaryen
function caml_binaryen_struct_type_is_field_mutable(heapType, index) {
  return Binaryen._BinaryenStructTypeIsFieldMutable(heapType, index);
}
