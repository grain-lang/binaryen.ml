#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>

#include "binaryen-c.h"
#include "ocaml_helpers.h"


CAMLprim value
caml_binaryen_set_memory(value _module, value _initial, value _maximum, value _exportName, value _segments, value _segmentPassive, value _segmentOffsets, value _segmentSizes, value _shared, value _memory64, value _memoryName) {
  CAMLparam5(_module, _initial, _maximum, _exportName, _segments);
  CAMLxparam5(_segmentPassive, _segmentOffsets, _segmentSizes, _shared, _memory64);
  CAMLxparam1(_memoryName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenIndex initial = Int_val(_initial);
  BinaryenIndex maximum = Int_val(_maximum);
  char* exportName = Safe_String_val(_exportName);
  _segments = array_of_list(_segments);
  int segmentsLen = array_length(_segments);
  const char* segments[segmentsLen];
  for (int i = 0; i < segmentsLen; i++) {
    segments[i] = Safe_String_val(Field(_segments, i));
  }
  _segmentPassive = array_of_list(_segmentPassive);
  int segmentPassiveLen = array_length(_segmentPassive);
  bool segmentPassive[segmentPassiveLen];
  for (int i = 0; i < segmentPassiveLen; i++) {
    segmentPassive[i] = Bool_val(Field(_segmentPassive, i));
  }
  _segmentOffsets = array_of_list(_segmentOffsets);
  int segmentOffsetsLen = array_length(_segmentOffsets);
  BinaryenExpressionRef segmentOffsets[segmentOffsetsLen];
  for (int i = 0; i < segmentOffsetsLen; i++) {
    segmentOffsets[i] = BinaryenExpressionRef_val(Field(_segmentOffsets, i));
  }
  _segmentSizes = array_of_list(_segmentSizes);
  int segmentSizesLen = array_length(_segmentSizes);
  BinaryenIndex segmentSizes[segmentSizesLen];
  for (int i = 0; i < segmentSizesLen; i++) {
    segmentSizes[i] = Int_val(Field(_segmentSizes, i));
  }
  bool shared = Bool_val(_shared);
  bool memory64 = Bool_val(_memory64);
  char* memoryName = Safe_String_val(_memoryName);
  BinaryenSetMemory(module, initial, maximum, exportName, segments, segmentPassive, segmentOffsets, segmentSizes, segmentsLen, shared, memory64, memoryName);
  CAMLreturn(Val_unit);
}
CAMLprim value
caml_binaryen_set_memory__bytecode(value * argv) {
  return caml_binaryen_set_memory(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10]);
}

CAMLprim value
caml_binaryen_has_memory(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  CAMLreturn(Val_bool(BinaryenHasMemory(module)));
}

CAMLprim value
caml_binaryen_memory_get_initial(value _module, value _memoryName) {
  CAMLparam2(_module, _memoryName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* memoryName = Safe_String_val(_memoryName);
  CAMLreturn(Val_int(BinaryenMemoryGetInitial(module, memoryName)));
}

CAMLprim value
caml_binaryen_memory_has_max(value _module, value _memoryName) {
  CAMLparam2(_module, _memoryName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* memoryName = Safe_String_val(_memoryName);
  CAMLreturn(Val_bool(BinaryenMemoryHasMax(module, memoryName)));
}

CAMLprim value
caml_binaryen_memory_get_max(value _module, value _memoryName) {
  CAMLparam2(_module, _memoryName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* memoryName = Safe_String_val(_memoryName);
  if (BinaryenMemoryHasMax(module, memoryName)) {
    CAMLreturn(Val_int(BinaryenMemoryGetMax(module, memoryName)));
  } else {
    // This ensures that our return is equal to Memory.unlimited
    CAMLreturn(Val_int(-1));
  }
}

CAMLprim value
caml_binaryen_memory_is_shared(value _module, value _memoryName) {
  CAMLparam2(_module, _memoryName);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  char* memoryName = Safe_String_val(_memoryName);
  CAMLreturn(Val_bool(BinaryenMemoryIsShared(module, memoryName)));
}

CAMLprim value
caml_binaryen_get_num_memory_segments(value _module) {
  CAMLparam1(_module);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  CAMLreturn(Val_int(BinaryenGetNumMemorySegments(module)));
}

CAMLprim value
caml_binaryen_get_memory_segment_byte_offset(value _module, value _id) {
  CAMLparam2(_module, _id);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenIndex id = Int_val(_id);
  CAMLreturn(Val_int(BinaryenGetMemorySegmentByteOffset(module, id)));
}

CAMLprim value
caml_binaryen_get_memory_segment_passive(value _module, value _id) {
  CAMLparam2(_module, _id);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenIndex id = Int_val(_id);
  CAMLreturn(Val_bool(BinaryenGetMemorySegmentPassive(module, id)));
}

CAMLprim value
caml_binaryen_get_memory_segment_data(value _module, value _id) {
  CAMLparam2(_module, _id);
  BinaryenModuleRef module = BinaryenModuleRef_val(_module);
  BinaryenIndex id = Int_val(_id);
  size_t size = BinaryenGetMemorySegmentByteLength(module, id);
  CAMLprim value bytes = caml_alloc_string(size);
  BinaryenCopyMemorySegmentData(module, id, (char*)Bytes_val(bytes));
  CAMLreturn(bytes);
}
