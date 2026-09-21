//Provides: caml_binaryen_type_none
//Requires: Binaryen
function caml_binaryen_type_none() {
  return Binaryen.Type.none;
}

//Provides: caml_binaryen_type_int32
//Requires: Binaryen
function caml_binaryen_type_int32() {
  return Binaryen.Type.i32;
}

//Provides: caml_binaryen_type_int64
//Requires: Binaryen
function caml_binaryen_type_int64() {
  return Binaryen.Type.i64;
}

//Provides: caml_binaryen_type_float32
//Requires: Binaryen
function caml_binaryen_type_float32() {
  return Binaryen.Type.f32;
}

//Provides: caml_binaryen_type_float64
//Requires: Binaryen
function caml_binaryen_type_float64() {
  return Binaryen.Type.f64;
}

//Provides: caml_binaryen_type_vec128
//Requires: Binaryen
function caml_binaryen_type_vec128() {
  return Binaryen.Type.v128;
}

//Provides: caml_binaryen_type_funcref
//Requires: Binaryen
function caml_binaryen_type_funcref() {
  return Binaryen.Type.funcref;
}

//Provides: caml_binaryen_type_anyref
//Requires: Binaryen
function caml_binaryen_type_anyref() {
  return Binaryen.Type.anyref;
}

//Provides: caml_binaryen_type_eqref
//Requires: Binaryen
function caml_binaryen_type_eqref() {
  return Binaryen.Type.eqref;
}

//Provides: caml_binaryen_type_i31ref
//Requires: Binaryen
function caml_binaryen_type_i31ref() {
  return Binaryen.Type.i31ref;
}

//Provides: caml_binaryen_type_structref
//Requires: Binaryen
function caml_binaryen_type_structref() {
  return Binaryen.Type.structref;
}

//Provides: caml_binaryen_type_arrayref
//Requires: Binaryen
function caml_binaryen_type_arrayref() {
  return Binaryen.Type.arrayref;
}

//Provides: caml_binaryen_type_stringref
//Requires: Binaryen
function caml_binaryen_type_stringref() {
  return Binaryen.Type.stringref;
}

//Provides: caml_binaryen_type_nullref
//Requires: Binaryen
function caml_binaryen_type_nullref() {
  return Binaryen.Type.nullref;
}

//Provides: caml_binaryen_type_null_externref
//Requires: Binaryen
function caml_binaryen_type_null_externref() {
  return Binaryen.Type.nullexternref;
}

//Provides: caml_binaryen_type_null_funcref
//Requires: Binaryen
function caml_binaryen_type_null_funcref() {
  return Binaryen.Type.nullfuncref;
}

//Provides: caml_binaryen_type_exnref
//Requires: Binaryen
function caml_binaryen_type_exnref() {
  return Binaryen.Type.exnref;
}

//Provides: caml_binaryen_type_null_exnref
//Requires: Binaryen
function caml_binaryen_type_null_exnref() {
  return Binaryen.Type.nullexnref;
}

//Provides: caml_binaryen_type_unreachable
//Requires: Binaryen
function caml_binaryen_type_unreachable() {
  return Binaryen.Type.unreachable;
}

//Provides: caml_binaryen_type_auto
//Requires: Binaryen
function caml_binaryen_type_auto() {
  return Binaryen.Type.auto;
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