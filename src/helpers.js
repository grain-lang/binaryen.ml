//Requires: Binaryen
//Provides: caml_alloc_string_on_heap
function caml_alloc_string_on_heap(str) {
  var len = str.length;
  var ptr = Binaryen._malloc(len + 1);
  var encoder = new TextEncoder();
  encoder.encodeInto(str, Binaryen.HEAPU8.subarray(ptr, ptr + len));
  Binaryen.HEAPU8[ptr + len] = 0;
  return ptr;
}
