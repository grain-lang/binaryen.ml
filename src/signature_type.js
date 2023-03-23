//Provides: caml_binaryen_signature_type_get_params
//Requires: Binaryen
function caml_binaryen_signature_type_get_params(heapType) {
  return Binaryen._BinaryenSignatureTypeGetParams(heapType);
}

//Provides: caml_binaryen_signature_type_get_results
//Requires: Binaryen
function caml_binaryen_signature_type_get_results(heapType) {
  return Binaryen._BinaryenSignatureTypeGetResults(heapType);
}
