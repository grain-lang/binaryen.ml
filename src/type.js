//Provides: caml_binaryen_type_none
//Requires: Binaryen
function caml_binaryen_type_none() {
  return Binaryen.none;
}

//Provides: caml_binaryen_type_int32
//Requires: Binaryen
function caml_binaryen_type_int32() {
  return Binaryen.i32;
}

//Provides: caml_binaryen_type_int64
//Requires: Binaryen
function caml_binaryen_type_int64() {
  return Binaryen.i64;
}

//Provides: caml_binaryen_type_float32
//Requires: Binaryen
function caml_binaryen_type_float32() {
  return Binaryen.f32;
}

//Provides: caml_binaryen_type_float64
//Requires: Binaryen
function caml_binaryen_type_float64() {
  return Binaryen.f64;
}

//Provides: caml_binaryen_type_vec128
//Requires: Binaryen
function caml_binaryen_type_vec128() {
  return Binaryen.v128;
}

//Provides: caml_binaryen_type_funcref
//Requires: Binaryen
function caml_binaryen_type_funcref() {
  return Binaryen.funcref;
}

//Provides: caml_binaryen_type_anyref
//Requires: Binaryen
function caml_binaryen_type_anyref() {
  return Binaryen.anyref;
}

//Provides: caml_binaryen_type_eqref
//Requires: Binaryen
function caml_binaryen_type_eqref() {
  return Binaryen.eqref;
}

//Provides: caml_binaryen_type_i31ref
//Requires: Binaryen
function caml_binaryen_type_i31ref() {
  return Binaryen.i31ref;
}

//Provides: caml_binaryen_type_structref
//Requires: Binaryen
function caml_binaryen_type_structref() {
  return Binaryen.structref;
}

//Provides: caml_binaryen_type_arrayref
//Requires: Binaryen
function caml_binaryen_type_arrayref() {
  // TODO: Binaryen v111 didn't expose this directly
  return Binaryen._BinaryenTypeArrayref();
}

//Provides: caml_binaryen_type_stringref
//Requires: Binaryen
function caml_binaryen_type_stringref() {
  return Binaryen.stringref;
}

//Provides: caml_binaryen_type_stringview_wtf8
//Requires: Binaryen
function caml_binaryen_type_stringview_wtf8() {
  return Binaryen.stringview_wtf8;
}

//Provides: caml_binaryen_type_stringview_wtf16
//Requires: Binaryen
function caml_binaryen_type_stringview_wtf16() {
  return Binaryen.stringview_wtf16;
}

//Provides: caml_binaryen_type_stringview_iter
//Requires: Binaryen
function caml_binaryen_type_stringview_iter() {
  return Binaryen.stringview_iter;
}

//Provides: caml_binaryen_type_nullref
//Requires: Binaryen
function caml_binaryen_type_nullref() {
  // TODO: Binaryen v111 didn't expose this directly
  return Binaryen._BinaryenTypeNullref();
}

//Provides: caml_binaryen_type_null_externref
//Requires: Binaryen
function caml_binaryen_type_null_externref() {
  // TODO: Binaryen v111 didn't expose this directly
  return Binaryen._BinaryenTypeNullExternref();
}

//Provides: caml_binaryen_type_null_funcref
//Requires: Binaryen
function caml_binaryen_type_null_funcref() {
  // TODO: Binaryen v111 didn't expose this directly
  return Binaryen._BinaryenTypeNullFuncref();
}

//Provides: caml_binaryen_type_unreachable
//Requires: Binaryen
function caml_binaryen_type_unreachable() {
  return Binaryen.unreachable;
}

//Provides: caml_binaryen_type_auto
//Requires: Binaryen
function caml_binaryen_type_auto() {
  return Binaryen.auto;
}

//Provides: caml_binaryen_type_create
//Requires: Binaryen
//Requires: caml_js_from_array
function caml_binaryen_type_create(typs) {
  return Binaryen.createType(caml_js_from_array(typs));
}

//Provides: caml_binaryen_type_expand
//Requires: Binaryen
//Requires: caml_js_to_array
function caml_binaryen_type_expand(typ) {
  return caml_js_to_array(Binaryen.expandType(typ));
}

//Provides: caml_binaryen_type_is_nullable
//Requires: Binaryen
function caml_binaryen_type_is_nullable(typ) {
  return Binaryen._BinaryenTypeIsNullable(typ);
}

//Provides: caml_binaryen_type_from_heap_type
//Requires: Binaryen
function caml_binaryen_type_from_heap_type(typ, nullable) {
  return Binaryen._BinaryenTypeFromHeapType(typ, nullable);
}
