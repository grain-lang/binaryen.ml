#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/alloc.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


CAMLprim value
caml_binaryen_get_num_memory_segments(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  CAMLreturn(Val_int(BinaryenGetNumMemorySegments(module)));
}

CAMLprim value caml_binaryen_get_data_segment(value _module, value _name) {
  CAMLparam2(_module, _name);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* name = Safe_String_val(_name);
  BinaryenDataSegmentRef segment = BinaryenGetDataSegment(module, name);
  if (segment == NULL) {
    CAMLreturn(Val_none);
  } else {
    CAMLreturn(caml_alloc_some(alloc_BinaryenDataSegmentRef(segment)));
  }
}

CAMLprim value caml_binaryen_get_data_segment_by_index(value _module, value _index) {
  CAMLparam2(_module, _index);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  int index = Int_val(_index);
  BinaryenDataSegmentRef segment = BinaryenGetDataSegmentByIndex(module, index);
  CAMLreturn(alloc_BinaryenDataSegmentRef(segment));
}

CAMLprim value caml_binaryen_data_segment_get_name(value _module, value _segment) {
  CAMLparam2(_module, _segment);
  BinaryenDataSegmentRef segment = BinaryenDataSegmentRef_val(_segment);
  const char* name = BinaryenDataSegmentGetName(segment);
  CAMLreturn(caml_copy_string(name));
}

CAMLprim value
caml_binaryen_get_memory_segment_byte_offset(value _module, value _segment) {
  CAMLparam2(_module, _segment);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenDataSegmentRef segment = BinaryenDataSegmentRef_val(_segment);
  if (BinaryenGetMemorySegmentPassive(segment)) {
    CAMLreturn(Val_none);
  } else {
    int offset = BinaryenGetMemorySegmentByteOffset(module, segment);
    CAMLreturn(caml_alloc_some(Val_int(offset)));
  }
}

CAMLprim value
caml_binaryen_get_memory_segment_byte_length(value _segment) {
  CAMLparam1(_segment);
  BinaryenDataSegmentRef segment = BinaryenDataSegmentRef_val(_segment);
  int length = BinaryenGetMemorySegmentByteLength(segment);
  CAMLreturn(Val_int(length));
}

CAMLprim value
caml_binaryen_get_memory_segment_passive(value _segment) {
  CAMLparam1(_segment);
  BinaryenDataSegmentRef segment = BinaryenDataSegmentRef_val(_segment);
  CAMLreturn(Val_bool(BinaryenGetMemorySegmentPassive(segment)));
}

CAMLprim value
caml_binaryen_get_memory_segment_data(value _module, value _segment) {
  CAMLparam2(_module, _segment);
  BinaryenDataSegmentRef segment = BinaryenDataSegmentRef_val(_segment);
  size_t size = BinaryenGetMemorySegmentByteLength(segment);
  CAMLprim value bytes = caml_alloc_string(size);
  BinaryenCopyMemorySegmentData(segment, (char*)Bytes_val(bytes));
  CAMLreturn(bytes);
}
