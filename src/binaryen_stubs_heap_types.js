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

//Provides: caml_binaryen_type_get_heap_type
//Requires: Binaryen
function caml_binaryen_type_get_heap_type(typ) {
  return Binaryen._BinaryenTypeGetHeapType(typ);
}