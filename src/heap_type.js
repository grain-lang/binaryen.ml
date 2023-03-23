//Provides: caml_binaryen_heap_type_ext
//Requires: Binaryen
function caml_binaryen_heap_type_ext() {
  return Binaryen._BinaryenHeapTypeExt();
}

//Provides: caml_binaryen_heap_type_func
//Requires: Binaryen
function caml_binaryen_heap_type_func() {
  return Binaryen._BinaryenHeapTypeFunc();
}

//Provides: caml_binaryen_heap_type_any
//Requires: Binaryen
function caml_binaryen_heap_type_any() {
  return Binaryen._BinaryenHeapTypeAny();
}

//Provides: caml_binaryen_heap_type_eq
//Requires: Binaryen
function caml_binaryen_heap_type_eq() {
  return Binaryen._BinaryenHeapTypeEq();
}

//Provides: caml_binaryen_heap_type_i31
//Requires: Binaryen
function caml_binaryen_heap_type_i31() {
  return Binaryen._BinaryenHeapTypeI31();
}

//Provides: caml_binaryen_heap_type_data
//Requires: Binaryen
function caml_binaryen_heap_type_data() {
  return Binaryen._BinaryenHeapTypeData();
}

//Provides: caml_binaryen_heap_type_array
//Requires: Binaryen
function caml_binaryen_heap_type_array() {
  return Binaryen._BinaryenHeapTypeArray();
}

//Provides: caml_binaryen_heap_type_string
//Requires: Binaryen
function caml_binaryen_heap_type_string() {
  return Binaryen._BinaryenHeapTypeString();
}

//Provides: caml_binaryen_heap_type_stringview_wtf8
//Requires: Binaryen
function caml_binaryen_heap_type_stringview_wtf8() {
  return Binaryen._BinaryenHeapTypeStringviewWTF8();
}

//Provides: caml_binaryen_heap_type_stringview_wtf16
//Requires: Binaryen
function caml_binaryen_heap_type_stringview_wtf16() {
  return Binaryen._BinaryenHeapTypeStringviewWTF16();
}

//Provides: caml_binaryen_heap_type_stringview_iter
//Requires: Binaryen
function caml_binaryen_heap_type_stringview_iter() {
  return Binaryen._BinaryenHeapTypeStringviewIter();
}

//Provides: caml_binaryen_heap_type_none
//Requires: Binaryen
function caml_binaryen_heap_type_none() {
  return Binaryen._BinaryenHeapTypeNone();
}

//Provides: caml_binaryen_heap_type_noext
//Requires: Binaryen
function caml_binaryen_heap_type_noext() {
  return Binaryen._BinaryenHeapTypeNoext();
}

//Provides: caml_binaryen_heap_type_nofunc
//Requires: Binaryen
function caml_binaryen_heap_type_nofunc() {
  return Binaryen._BinaryenHeapTypeNofunc();
}

//Provides: caml_binaryen_heap_type_is_basic
//Requires: Binaryen
function caml_binaryen_heap_type_is_basic(ty) {
  // TODO: Verify that binaryen returns an int which jsoo will understand as bool
  return Binaryen._BinaryenHeapTypeIsBasic(ty);
}

//Provides: caml_binaryen_heap_type_is_signature
//Requires: Binaryen
function caml_binaryen_heap_type_is_signature(ty) {
  // TODO: Verify that binaryen returns an int which jsoo will understand as bool
  return Binaryen._BinaryenHeapTypeIsSignature(ty);
}

//Provides: caml_binaryen_heap_type_is_struct
//Requires: Binaryen
function caml_binaryen_heap_type_is_struct(ty) {
  // TODO: Verify that binaryen returns an int which jsoo will understand as bool
  return Binaryen._BinaryenHeapTypeIsStruct(ty);
}

//Provides: caml_binaryen_heap_type_is_array
//Requires: Binaryen
function caml_binaryen_heap_type_is_array(ty) {
  // TODO: Verify that binaryen returns an int which jsoo will understand as bool
  return Binaryen._BinaryenHeapTypeIsArray(ty);
}

//Provides: caml_binaryen_heap_type_is_bottom
//Requires: Binaryen
function caml_binaryen_heap_type_is_bottom(ty) {
  // TODO: Verify that binaryen returns an int which jsoo will understand as bool
  return Binaryen._BinaryenHeapTypeIsBottom(ty);
}

//Provides: caml_binaryen_heap_type_get_bottom
//Requires: Binaryen
function caml_binaryen_heap_type_get_bottom(ty) {
  return Binaryen._BinaryenHeapTypeGetBottom(ty);
}

//Provides: caml_binaryen_heap_type_is_sub_type
//Requires: Binaryen
function caml_binaryen_heap_type_is_sub_type(left, right) {
  // TODO: Verify that binaryen returns an int which jsoo will understand as bool
  return Binaryen._BinaryenHeapTypeIsSubType(left, right);
}

//Provides: caml_binaryen_type_get_heap_type
//Requires: Binaryen
function caml_binaryen_type_get_heap_type(typ) {
  return Binaryen._BinaryenTypeGetHeapType(typ);
}
