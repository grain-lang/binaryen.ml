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

//Provides: caml_binaryen_type_externref
//Requires: Binaryen
function caml_binaryen_type_externref() {
  return Binaryen.externref;
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

//Provides: caml_binaryen_type_dataref
//Requires: Binaryen
function caml_binaryen_type_dataref() {
  return Binaryen.dataref;
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
