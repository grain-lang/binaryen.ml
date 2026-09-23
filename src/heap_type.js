//Provides: caml_binaryen_heap_type_ext
//Requires: Binaryen
function caml_binaryen_heap_type_ext() {
  return Binaryen.HeapType.extern;
}

//Provides: caml_binaryen_heap_type_func
//Requires: Binaryen
function caml_binaryen_heap_type_func() {
  return Binaryen.HeapType.func;
}

//Provides: caml_binaryen_heap_type_any
//Requires: Binaryen
function caml_binaryen_heap_type_any() {
  return Binaryen.HeapType.any;
}

//Provides: caml_binaryen_heap_type_eq
//Requires: Binaryen
function caml_binaryen_heap_type_eq() {
  return Binaryen.HeapType.eq;
}

//Provides: caml_binaryen_heap_type_i31
//Requires: Binaryen
function caml_binaryen_heap_type_i31() {
  return Binaryen.HeapType.i31;
}

//Provides: caml_binaryen_heap_type_struct
//Requires: Binaryen
function caml_binaryen_heap_type_struct() {
  return Binaryen.HeapType.struct;
}

//Provides: caml_binaryen_heap_type_array
//Requires: Binaryen
function caml_binaryen_heap_type_array() {
  return Binaryen.HeapType.array;
}

//Provides: caml_binaryen_heap_type_string
//Requires: Binaryen
function caml_binaryen_heap_type_string() {
  return Binaryen.HeapType.string;
}

//Provides: caml_binaryen_heap_type_none
//Requires: Binaryen
function caml_binaryen_heap_type_none() {
  return Binaryen.HeapType.none;
}

//Provides: caml_binaryen_heap_type_noext
//Requires: Binaryen
function caml_binaryen_heap_type_noext() {
  return Binaryen.HeapType.noextern;
}

//Provides: caml_binaryen_heap_type_nofunc
//Requires: Binaryen
function caml_binaryen_heap_type_nofunc() {
  return Binaryen.HeapType.nofunc;
}

//Provides: caml_binaryen_heap_type_exn
//Requires: Binaryen
function caml_binaryen_heap_type_exn() {
  return Binaryen.HeapType.exn;
}

//Provides: caml_binaryen_heap_type_noexn
//Requires: Binaryen
function caml_binaryen_heap_type_noexn() {
  return Binaryen.HeapType.noexn;
}

//Provides: caml_binaryen_heap_type_is_basic
//Requires: Binaryen
function caml_binaryen_heap_type_is_basic(ty) {
  return Binaryen._BinaryenHeapTypeIsBasic(ty);
}

//Provides: caml_binaryen_heap_type_is_signature
//Requires: Binaryen
function caml_binaryen_heap_type_is_signature(ty) {
  return Binaryen._BinaryenHeapTypeIsSignature(ty);
}

//Provides: caml_binaryen_heap_type_is_struct
//Requires: Binaryen
function caml_binaryen_heap_type_is_struct(ty) {
  return Binaryen._BinaryenHeapTypeIsStruct(ty);
}

//Provides: caml_binaryen_heap_type_is_array
//Requires: Binaryen
function caml_binaryen_heap_type_is_array(ty) {
  return Binaryen._BinaryenHeapTypeIsArray(ty);
}

//Provides: caml_binaryen_heap_type_is_bottom
//Requires: Binaryen
function caml_binaryen_heap_type_is_bottom(ty) {
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
  return Binaryen._BinaryenHeapTypeIsSubType(left, right);
}

//Provides: caml_binaryen_type_get_heap_type
//Requires: Binaryen
function caml_binaryen_type_get_heap_type(typ) {
  return Binaryen._BinaryenTypeGetHeapType(typ);
}

//Provides: caml_binaryen_module_set_type_name
//Requires: caml_jsstring_of_string
function caml_binaryen_module_set_type_name(wasm_mod, heapType, name) {
  wasm_mod.setTypeName(heapType, caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_module_set_field_name
//Requires: caml_jsstring_of_string
function caml_binaryen_module_set_field_name(wasm_mod, heapType, index, name) {
  wasm_mod.setFieldName(heapType, index, caml_jsstring_of_string(name));
}