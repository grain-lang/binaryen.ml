//Provides: caml_type_builder_create
//Requires: Binaryen
function caml_type_builder_create(size) {
  return new Binaryen.TypeBuilder(size);
}

//Provides: caml_type_builder_grow
function caml_type_builder_grow(builder, count) {
  builder.grow(count);
}

//Provides: caml_type_builder_get_size
function caml_type_builder_get_size(builder) {
  return builder.getSize();
}

//Provides: caml_type_builder_set_signature_type
function caml_type_builder_set_signature_type(
  builder,
  index,
  paramTypes,
  resultTypes
) {
  builder.setSignatureType(index, paramTypes, resultTypes);
}

//Provides: caml_type_builder_set_struct_type
//Requires: caml_list_to_js_array
//Requires: caml_js_from_bool
function caml_type_builder_set_struct_type(
  builder,
  index,
  fieldTypes,
  fieldPackedTypes,
  fieldMutables,
  numFields
) {
  var types = caml_list_to_js_array(fieldTypes);
  var packedTypes = caml_list_to_js_array(fieldPackedTypes);
  var mutables = caml_list_to_js_array(fieldMutables);
  var fields = types.map(function (type, idx) {
    return {
      type,
      packedType: packedTypes[idx],
      mutable: caml_js_from_bool(mutables[idx]),
    };
  });
  builder.setStructType(index, fields);
}
//Provides: caml_type_builder_set_struct_type__bytecode
//Requires: caml_type_builder_set_struct_type
function caml_type_builder_set_struct_type__bytecode() {
  return caml_type_builder_set_struct_type(
    arguments[0],
    arguments[1],
    arguments[2],
    arguments[3],
    arguments[4],
    arguments[5]
  );
}

//Provides: caml_type_builder_set_array_type
function caml_type_builder_set_array_type(
  builder,
  index,
  elementType,
  elementPackedType,
  elementMutable
) {
  builder.setArrayType(index, elementType, elementPackedType, elementMutable);
}

//Provides: caml_type_builder_get_temp_heap_type
function caml_type_builder_get_temp_heap_type(builder, index) {
  return builder.getTempHeapType(index);
}

//Provides: caml_type_builder_get_temp_tuple_type
//Requires: caml_list_to_js_array
function caml_type_builder_get_temp_tuple_type(builder, types, numTypes) {
  var tupleTypes = caml_list_to_js_array(types);
  return builder.getTempTupleType(tupleTypes);
}

//Provides: caml_type_builder_get_temp_ref_type
//Requires: caml_js_from_bool
function caml_type_builder_get_temp_ref_type(builder, heapType, nullable) {
  return builder.getTempRefType(heapType, caml_js_from_bool(nullable));
}

//Provides: caml_type_builder_set_sub_type
function caml_type_builder_set_sub_type(builder, index, superType) {
  builder.setSubType(index, superType);
}

//Provides: caml_type_builder_set_open
function caml_type_builder_set_open(builder, index) {
  builder.setOpen(index);
}

//Provides: caml_type_builder_create_rec_group
function caml_type_builder_create_rec_group(builder, index, length) {
  builder.createRecGroup(index, length);
}

//Provides: caml_type_builder_build_and_dispose
//Requires: caml_js_to_array
function caml_type_builder_build_and_dispose(builder) {
  try {
    var types = builder.buildAndDispose();
    return [0, caml_js_to_array(types)];
  } catch (e) {
    return [1, [0, e.index, e.reason]];
  }
}
