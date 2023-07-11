//Provides: caml_binaryen_type_system_nominal
//Requires: Binaryen
function caml_binaryen_type_system_nominal() {
  return Binaryen._BinaryenTypeSystemNominal();
}

//Provides: caml_binaryen_type_system_isorecursive
//Requires: Binaryen
function caml_binaryen_type_system_isorecursive() {
  return Binaryen._BinaryenTypeSystemIsorecursive();
}

//Provides: caml_binaryen_get_type_system
//Requires: Binaryen
function caml_binaryen_get_type_system() {
  return Binaryen._BinaryenGetTypeSystem();
}

//Provides: caml_binaryen_set_type_system
//Requires: Binaryen
function caml_binaryen_set_type_system(typeSystem) {
  Binaryen._BinaryenSetTypeSystem(typeSystem);
}
