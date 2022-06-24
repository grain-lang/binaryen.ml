//Provides: caml_binaryen_type_none
//Requires: binaryen
function caml_binaryen_type_none() {
  return binaryen.none;
}

//Provides: caml_binaryen_type_int32
//Requires: binaryen
function caml_binaryen_type_int32() {
  return binaryen.i32;
}

//Provides: caml_binaryen_type_int64
//Requires: binaryen
function caml_binaryen_type_int64() {
  return binaryen.i64;
}

//Provides: caml_binaryen_type_float32
//Requires: binaryen
function caml_binaryen_type_float32() {
  return binaryen.f32;
}

//Provides: caml_binaryen_type_float64
//Requires: binaryen
function caml_binaryen_type_float64() {
  return binaryen.f64;
}

//Provides: caml_binaryen_type_vec128
//Requires: binaryen
function caml_binaryen_type_vec128() {
  return binaryen.v128;
}

//Provides: caml_binaryen_type_funcref
//Requires: binaryen
function caml_binaryen_type_funcref() {
  return binaryen.funcref;
}

//Provides: caml_binaryen_type_externref
//Requires: binaryen
function caml_binaryen_type_externref() {
  return binaryen.externref;
}

//Provides: caml_binaryen_type_eqref
//Requires: binaryen
function caml_binaryen_type_eqref() {
  return binaryen.eqref;
}

//Provides: caml_binaryen_type_i31ref
//Requires: binaryen
function caml_binaryen_type_i31ref() {
  return binaryen.i31ref;
}

//Provides: caml_binaryen_type_dataref
//Requires: binaryen
function caml_binaryen_type_dataref() {
  return binaryen.dataref;
}

//Provides: caml_binaryen_type_unreachable
//Requires: binaryen
function caml_binaryen_type_unreachable() {
  return binaryen.unreachable;
}

//Provides: caml_binaryen_type_auto
//Requires: binaryen
function caml_binaryen_type_auto() {
  return binaryen.auto;
}

//Provides: caml_binaryen_type_create
//Requires: binaryen
//Requires: caml_js_from_array
function caml_binaryen_type_create(typs) {
  return binaryen.createType(caml_js_from_array(typs));
}

//Provides: caml_binaryen_type_expand
//Requires: binaryen
//Requires: caml_js_to_array
function caml_binaryen_type_expand(typ) {
  return caml_js_to_array(binaryen.expandType(typ));
}
