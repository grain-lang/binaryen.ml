//Provides: caml_binaryen_array_type_get_element_type
//Requires: Binaryen
function caml_binaryen_array_type_get_element_type(heapType) {
  return Binaryen._BinaryenArrayTypeGetElementType(heapType);
}

//Provides: caml_binaryen_array_type_get_element_packed_type
//Requires: Binaryen
function caml_binaryen_array_type_get_element_packed_type(heapType) {
  return Binaryen._BinaryenArrayTypeGetElementPackedType(heapType);
}

//Provides: caml_binaryen_array_type_is_element_mutable
//Requires: Binaryen
function caml_binaryen_array_type_is_element_mutable(heapType) {
  // TODO: Verify that binaryen returns an int which jsoo will understand as bool
  return Binaryen._BinaryenArrayTypeIsElementMutable(heapType);
}
