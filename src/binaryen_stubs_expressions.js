//Provides: to_option
function to_option(x) {
  if (x) {
    return [0, x];
  } else {
    return 0;
  }
}

//Provides: caml_binaryen_expression_get_id
//Requires: binaryen
function caml_binaryen_expression_get_id(expr) {
  return binaryen.getExpressionId(expr);
}

//Provides: caml_binaryen_null_expression
function caml_binaryen_null_expression() {
  return null;
}

//Provides: caml_binaryen_block
//Requires: caml_jsstring_of_string
//Requires: caml_list_to_js_array
function caml_binaryen_block(wasm_mod, name, children, return_type) {
  return wasm_mod.block(
    caml_jsstring_of_string(name),
    caml_list_to_js_array(children),
    return_type
  );
}

//Provides: caml_binaryen_if
function caml_binaryen_if(wasm_mod, cond, if_true, if_false) {
  return wasm_mod.if(cond, if_true, if_false);
}

//Provides: caml_binaryen_loop
//Requires: caml_jsstring_of_string
function caml_binaryen_loop(wasm_mod, name, body) {
  return wasm_mod.loop(
    caml_jsstring_of_string(name),
    body
  );
}

//Provides: caml_binaryen_break
//Requires: caml_jsstring_of_string
function caml_binaryen_break(wasm_mod, name, cond, res) {
  return wasm_mod.br(
    caml_jsstring_of_string(name),
    cond,
    res
  );
}

//Provides: caml_binaryen_switch
//Requires: caml_jsstring_of_string
//Requires: caml_list_to_js_array
function caml_binaryen_switch(wasm_mod, names, default_name, cond, value) {
  return wasm_mod.switch(
    caml_list_to_js_array(names).map(caml_jsstring_of_string),
    caml_jsstring_of_string(default_name),
    cond,
    value
  );
}

//Provides: caml_binaryen_call
//Requires: caml_jsstring_of_string
//Requires: caml_list_to_js_array
function caml_binaryen_call(wasm_mod, name, params, return_typ) {
  return wasm_mod.call(
    caml_jsstring_of_string(name),
    caml_list_to_js_array(params),
    return_typ
  );
}

//Provides: caml_binaryen_call_indirect
//Requires: caml_jsstring_of_string
//Requires: caml_list_to_js_array
function caml_binaryen_call_indirect(wasm_mod, table, target, params, params_typ, return_typ) {
  return wasm_mod.call_indirect(
    caml_jsstring_of_string(table),
    target,
    caml_list_to_js_array(params),
    params_typ,
    return_typ
  );
}
//Provides: caml_binaryen_call_indirect__bytecode
//Requires: caml_binaryen_call_indirect
function caml_binaryen_call_indirect__bytecode() {
  return caml_binaryen_call_indirect(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
}

//Provides: caml_binaryen_return_call
//Requires: caml_jsstring_of_string
//Requires: caml_list_to_js_array
function caml_binaryen_return_call(wasm_mod, name, params, return_typ) {
  return wasm_mod.return_call(
    caml_jsstring_of_string(name),
    caml_list_to_js_array(params),
    return_typ
  );
}

//Provides: caml_binaryen_return_call_indirect
//Requires: caml_jsstring_of_string
//Requires: caml_list_to_js_array
function caml_binaryen_return_call_indirect(wasm_mod, table, target, params, params_typ, return_typ) {
  return wasm_mod.return_call_indirect(
    caml_jsstring_of_string(table),
    target,
    caml_list_to_js_array(params),
    params_typ,
    return_typ
  );
}
//Provides: caml_binaryen_return_call_indirect__bytecode
//Requires: caml_binaryen_return_call_indirect
function caml_binaryen_return_call_indirect__bytecode() {
  return caml_binaryen_return_call_indirect(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
}

//Provides: caml_binaryen_local_get
function caml_binaryen_local_get(wasm_mod, slot, typ) {
  return wasm_mod.local.get(slot, typ);
}

//Provides: caml_binaryen_local_set
function caml_binaryen_local_set(wasm_mod, slot, value) {
  return wasm_mod.local.set(slot, value);
}

//Provides: caml_binaryen_local_tee
function caml_binaryen_local_tee(wasm_mod, slot, value, typ) {
  return wasm_mod.local.tee(slot, value, typ);
}

//Provides: caml_binaryen_global_get
//Requires: caml_jsstring_of_string
function caml_binaryen_global_get(wasm_mod, name, typ) {
  return wasm_mod.global.get(
    caml_jsstring_of_string(name),
    typ
  );
}

//Provides: caml_binaryen_global_set
//Requires: caml_jsstring_of_string
function caml_binaryen_global_set(wasm_mod, name, value) {
  return wasm_mod.global.set(
    caml_jsstring_of_string(name),
    value
  );
}

//Provides: caml_binaryen_load
//Requires: binaryen
function caml_binaryen_load(wasm_mod, bytes, signed, offset, align, typ, ptr) {
  return binaryen._BinaryenLoad(
    wasm_mod,
    bytes,
    signed,
    offset,
    align,
    typ,
    ptr
  );
}
//Provides: caml_binaryen_load__bytecode
//Requires: caml_binaryen_load
function caml_binaryen_load__bytecode() {
  return caml_binaryen_load(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6]);
}

//Provides: caml_binaryen_store
//Requires: binaryen
function caml_binaryen_store(wasm_mod, bytes, offset, align, ptr, value, typ) {
  return binaryen._BinaryenStore(
    wasm_mod,
    bytes,
    offset,
    align,
    ptr,
    value,
    typ
  );
}
//Provides: caml_binaryen_store__bytecode
//Requires: caml_binaryen_store
function caml_binaryen_store__bytecode() {
  return caml_binaryen_store(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6]);
}

//Provides: caml_binaryen_const
//Requires: caml_int64_lo32, caml_int64_hi32
//Requires: caml_failwith
function caml_binaryen_const(wasm_mod, lit) {
  if (lit.type === 'int32') {
    return wasm_mod.i32.const(lit.value);
  }

  if (lit.type === 'int64') {
    return wasm_mod.i64.const(
      caml_int64_lo32(lit.value),
      caml_int64_hi32(lit.value)
    );
  }

  if (lit.type === 'float64') {
    return wasm_mod.f64.const(lit.value);
  }

  if (lit.type === 'float32_bits') {
    return wasm_mod.f32.const_bits(lit.value);
  }

  if (lit.type === 'float64_bits') {
    return wasm_mod.f64.const_bits(
      caml_int64_lo32(lit.value),
      caml_int64_hi32(lit.value)
    );
  }

  caml_failwith('invalid Literal for Binaryen.Const.make');
}

//Provides: caml_binaryen_unary
//Requires: binaryen
function caml_binaryen_unary(wasm_mod, op, p) {
  return binaryen._BinaryenUnary(wasm_mod, op, p);
}

//Provides: caml_binaryen_binary
//Requires: binaryen
function caml_binaryen_binary(wasm_mod, op, p1, p2) {
  return binaryen._BinaryenBinary(wasm_mod, op, p1, p2);
}

//Provides: caml_binaryen_select
function caml_binaryen_select(wasm_mod, cond, if_true, if_false, typ) {
  return wasm_mod.select(cond, if_true, if_false, typ);
}

//Provides: caml_binaryen_drop
function caml_binaryen_drop(wasm_mod, value) {
  return wasm_mod.drop(value);
}

//Provides: caml_binaryen_return
function caml_binaryen_return(wasm_mod, value) {
  return wasm_mod.return(value);
}

//Provides: caml_binaryen_memory_size
function caml_binaryen_memory_size(wasm_mod) {
  return wasm_mod.memory.size();
}

//Provides: caml_binaryen_memory_grow
function caml_binaryen_memory_grow(wasm_mod, value) {
  return wasm_mod.memory.grow(value);
}

//Provides: caml_binaryen_nop
function caml_binaryen_nop(wasm_mod) {
  return wasm_mod.nop();
}

//Provides: caml_binaryen_unreachable
function caml_binaryen_unreachable(wasm_mod) {
  return wasm_mod.unreachable();
}

//Provides: caml_binaryen_memory_init
function caml_binaryen_memory_init(wasm_mod, segment, dest, offset, size) {
  return wasm_mod.memory.init(segment, dest, offset, size);
}

//Provides: caml_binaryen_data_drop
function caml_binaryen_data_drop(wasm_mod, segment) {
  return wasm_mod.data.drop(segment);
}

//Provides: caml_binaryen_memory_copy
function caml_binaryen_memory_copy(wasm_mod, dest, source, size) {
  return wasm_mod.memory.copy(dest, source, size);
}

//Provides: caml_binaryen_memory_fill
function caml_binaryen_memory_fill(wasm_mod, dest, value, size) {
  return wasm_mod.memory.fill(dest, value, size);
}

//Provides: caml_binaryen_tuple_make
//Requires: caml_list_to_js_array
function caml_binaryen_tuple_make(wasm_mod, operands) {
  return wasm_mod.tuple.make(caml_list_to_js_array(operands));
}

//Provides: caml_binaryen_tuple_extract
function caml_binaryen_tuple_extract(wasm_mod, tuple, index) {
  return wasm_mod.tuple.extract(tuple, index);
}

//Provides: caml_binaryen_pop
//Requires: binaryen
function caml_binaryen_pop(wasm_mod, typ) {
  return binaryen._BinaryenPop(wasm_mod, typ);
}

//Provides: caml_binaryen_expression_id_invalid
//Requires: binaryen
function caml_binaryen_expression_id_invalid() {
  return binaryen.InvalidId;
}

//Provides: caml_binaryen_expression_id_nop
//Requires: binaryen
function caml_binaryen_expression_id_nop() {
  return binaryen.NopId;
}
//Provides: caml_binaryen_expression_id_block
//Requires: binaryen
function caml_binaryen_expression_id_block() {
  return binaryen.BlockId;
}
//Provides: caml_binaryen_expression_id_if
//Requires: binaryen
function caml_binaryen_expression_id_if() {
  return binaryen.IfId;
}
//Provides: caml_binaryen_expression_id_loop
//Requires: binaryen
function caml_binaryen_expression_id_loop() {
  return binaryen.LoopId;
}
//Provides: caml_binaryen_expression_id_break
//Requires: binaryen
function caml_binaryen_expression_id_break() {
  return binaryen.BreakId;
}
//Provides: caml_binaryen_expression_id_switch
//Requires: binaryen
function caml_binaryen_expression_id_switch() {
  return binaryen.SwitchId;
}
//Provides: caml_binaryen_expression_id_call
//Requires: binaryen
function caml_binaryen_expression_id_call() {
  return binaryen.CallId;
}
//Provides: caml_binaryen_expression_id_call_indirect
//Requires: binaryen
function caml_binaryen_expression_id_call_indirect() {
  return binaryen.CallIndirectId;
}
//Provides: caml_binaryen_expression_id_local_get
//Requires: binaryen
function caml_binaryen_expression_id_local_get() {
  return binaryen.LocalGetId;
}
//Provides: caml_binaryen_expression_id_local_set
//Requires: binaryen
function caml_binaryen_expression_id_local_set() {
  return binaryen.LocalSetId;
}
//Provides: caml_binaryen_expression_id_global_get
//Requires: binaryen
function caml_binaryen_expression_id_global_get() {
  return binaryen.GlobalGetId;
}
//Provides: caml_binaryen_expression_id_global_set
//Requires: binaryen
function caml_binaryen_expression_id_global_set() {
  return binaryen.GlobalSetId;
}
//Provides: caml_binaryen_expression_id_load
//Requires: binaryen
function caml_binaryen_expression_id_load() {
  return binaryen.LoadId;
}
//Provides: caml_binaryen_expression_id_store
//Requires: binaryen
function caml_binaryen_expression_id_store() {
  return binaryen.StoreId;
}
//Provides: caml_binaryen_expression_id_atomic_rmw
//Requires: binaryen
function caml_binaryen_expression_id_atomic_rmw() {
  return binaryen.AtomicRMWId;
}
//Provides: caml_binaryen_expression_id_atomic_cmpxchg
//Requires: binaryen
function caml_binaryen_expression_id_atomic_cmpxchg() {
  return binaryen.AtomicCmpxchgId;
}
//Provides: caml_binaryen_expression_id_atomic_wait
//Requires: binaryen
function caml_binaryen_expression_id_atomic_wait() {
  return binaryen.AtomicWaitId;
}
//Provides: caml_binaryen_expression_id_atomic_notify
//Requires: binaryen
function caml_binaryen_expression_id_atomic_notify() {
  return binaryen.AtomicNotifyId;
}
//Provides: caml_binaryen_expression_id_atomic_fence
//Requires: binaryen
function caml_binaryen_expression_id_atomic_fence() {
  return binaryen.AtomicFenceId;
}
//Provides: caml_binaryen_expression_id_simd_extract
//Requires: binaryen
function caml_binaryen_expression_id_simd_extract() {
  return binaryen.SIMDExtractId;
}
//Provides: caml_binaryen_expression_id_simd_replace
//Requires: binaryen
function caml_binaryen_expression_id_simd_replace() {
  return binaryen.SIMDReplaceId;
}
//Provides: caml_binaryen_expression_id_simd_shuffle
//Requires: binaryen
function caml_binaryen_expression_id_simd_shuffle() {
  return binaryen.SIMDShuffleId;
}
//Provides: caml_binaryen_expression_id_simd_ternary
//Requires: binaryen
function caml_binaryen_expression_id_simd_ternary() {
  return binaryen.SIMDTernaryId;
}
//Provides: caml_binaryen_expression_id_simd_shift
//Requires: binaryen
function caml_binaryen_expression_id_simd_shift() {
  return binaryen.SIMDShiftId;
}
//Provides: caml_binaryen_expression_id_simd_load
//Requires: binaryen
function caml_binaryen_expression_id_simd_load() {
  return binaryen.SIMDLoadId;
}
//Provides: caml_binaryen_expression_id_simd_load_store_lane
//Requires: binaryen
function caml_binaryen_expression_id_simd_load_store_lane() {
  return binaryen.SIMDLoadStoreLaneId;
}
//Provides: caml_binaryen_expression_id_memory_init
//Requires: binaryen
function caml_binaryen_expression_id_memory_init() {
  return binaryen.MemoryInitId;
}
//Provides: caml_binaryen_expression_id_data_drop
//Requires: binaryen
function caml_binaryen_expression_id_data_drop() {
  return binaryen.DataDropId;
}
//Provides: caml_binaryen_expression_id_memory_copy
//Requires: binaryen
function caml_binaryen_expression_id_memory_copy() {
  return binaryen.MemoryCopyId;
}
//Provides: caml_binaryen_expression_id_memory_fill
//Requires: binaryen
function caml_binaryen_expression_id_memory_fill() {
  return binaryen.MemoryFillId;
}
//Provides: caml_binaryen_expression_id_const
//Requires: binaryen
function caml_binaryen_expression_id_const() {
  return binaryen.ConstId;
}
//Provides: caml_binaryen_expression_id_unary
//Requires: binaryen
function caml_binaryen_expression_id_unary() {
  return binaryen.UnaryId;
}
//Provides: caml_binaryen_expression_id_binary
//Requires: binaryen
function caml_binaryen_expression_id_binary() {
  return binaryen.BinaryId;
}
//Provides: caml_binaryen_expression_id_select
//Requires: binaryen
function caml_binaryen_expression_id_select() {
  return binaryen.SelectId;
}
//Provides: caml_binaryen_expression_id_drop
//Requires: binaryen
function caml_binaryen_expression_id_drop() {
  return binaryen.DropId;
}
//Provides: caml_binaryen_expression_id_return
//Requires: binaryen
function caml_binaryen_expression_id_return() {
  return binaryen.ReturnId;
}
//Provides: caml_binaryen_expression_id_memory_size
//Requires: binaryen
function caml_binaryen_expression_id_memory_size() {
  return binaryen.MemorySizeId;
}
//Provides: caml_binaryen_expression_id_memory_grow
//Requires: binaryen
function caml_binaryen_expression_id_memory_grow() {
  return binaryen.MemoryGrowId;
}
//Provides: caml_binaryen_expression_id_unreachable
//Requires: binaryen
function caml_binaryen_expression_id_unreachable() {
  return binaryen.UnreachableId;
}
//Provides: caml_binaryen_expression_id_pop
//Requires: binaryen
function caml_binaryen_expression_id_pop() {
  return binaryen.PopId;
}
//Provides: caml_binaryen_expression_id_ref_null
//Requires: binaryen
function caml_binaryen_expression_id_ref_null() {
  return binaryen.RefNullId;
}
//Provides: caml_binaryen_expression_id_ref_is
//Requires: binaryen
function caml_binaryen_expression_id_ref_is() {
  return binaryen.RefIsId;
}
//Provides: caml_binaryen_expression_id_ref_as
//Requires: binaryen
function caml_binaryen_expression_id_ref_as() {
  return binaryen.RefAsId;
}
//Provides: caml_binaryen_expression_id_ref_func
//Requires: binaryen
function caml_binaryen_expression_id_ref_func() {
  return binaryen.RefFuncId;
}
//Provides: caml_binaryen_expression_id_ref_eq
//Requires: binaryen
function caml_binaryen_expression_id_ref_eq() {
  return binaryen.RefEqId;
}
//Provides: caml_binaryen_expression_id_try
//Requires: binaryen
function caml_binaryen_expression_id_try() {
  return binaryen.TryId;
}
//Provides: caml_binaryen_expression_id_throw
//Requires: binaryen
function caml_binaryen_expression_id_throw() {
  return binaryen.ThrowId;
}
//Provides: caml_binaryen_expression_id_rethrow
//Requires: binaryen
function caml_binaryen_expression_id_rethrow() {
  return binaryen.RethrowId;
}
//Provides: caml_binaryen_expression_id_tuple_make
//Requires: binaryen
function caml_binaryen_expression_id_tuple_make() {
  return binaryen.TupleMakeId;
}
//Provides: caml_binaryen_expression_id_tuple_extract
//Requires: binaryen
function caml_binaryen_expression_id_tuple_extract() {
  return binaryen.TupleExtractId;
}
//Provides: caml_binaryen_expression_id_i31_new
//Requires: binaryen
function caml_binaryen_expression_id_i31_new() {
  return binaryen.I31NewId;
}
//Provides: caml_binaryen_expression_id_i31_get
//Requires: binaryen
function caml_binaryen_expression_id_i31_get() {
  return binaryen.I31GetId;
}
//Provides: caml_binaryen_expression_id_call_ref
//Requires: binaryen
function caml_binaryen_expression_id_call_ref() {
  return binaryen.CallRefId;
}
//Provides: caml_binaryen_expression_id_ref_test
//Requires: binaryen
function caml_binaryen_expression_id_ref_test() {
  return binaryen.RefTestId;
}
//Provides: caml_binaryen_expression_id_ref_cast
//Requires: binaryen
function caml_binaryen_expression_id_ref_cast() {
  return binaryen.RefCastId;
}
//Provides: caml_binaryen_expression_id_br_on
//Requires: binaryen
function caml_binaryen_expression_id_br_on() {
  return binaryen.BrOnId;
}
//Provides: caml_binaryen_expression_id_rtt_canon
//Requires: binaryen
function caml_binaryen_expression_id_rtt_canon() {
  return binaryen.RttCanonId;
}
//Provides: caml_binaryen_expression_id_rtt_sub
//Requires: binaryen
function caml_binaryen_expression_id_rtt_sub() {
  return binaryen.RttSubId;
}
//Provides: caml_binaryen_expression_id_struct_new
//Requires: binaryen
function caml_binaryen_expression_id_struct_new() {
  return binaryen.StructNewId;
}
//Provides: caml_binaryen_expression_id_struct_get
//Requires: binaryen
function caml_binaryen_expression_id_struct_get() {
  return binaryen.StructGetId;
}
//Provides: caml_binaryen_expression_id_struct_set
//Requires: binaryen
function caml_binaryen_expression_id_struct_set() {
  return binaryen.StructSetId;
}
//Provides: caml_binaryen_expression_id_array_new
//Requires: binaryen
function caml_binaryen_expression_id_array_new() {
  return binaryen.ArrayNewId;
}
//Provides: caml_binaryen_expression_id_array_get
//Requires: binaryen
function caml_binaryen_expression_id_array_get() {
  return binaryen.ArrayGetId;
}
//Provides: caml_binaryen_expression_id_array_set
//Requires: binaryen
function caml_binaryen_expression_id_array_set() {
  return binaryen.ArraySetId;
}
//Provides: caml_binaryen_expression_id_array_len
//Requires: binaryen
function caml_binaryen_expression_id_array_len() {
  return binaryen.ArrayLenId;
}

// Expression operations

//Provides: caml_binaryen_expression_print
//Requires: binaryen
//Requires: caml_string_of_jsstring
//Requires: caml_ml_output, caml_ml_string_length
function caml_binaryen_expression_print(expr) {
  var text = binaryen.emitText(expr);
  var chanid = 1; // stdout
  var s = caml_string_of_jsstring(text);
  caml_ml_output(chanid, s, 0, caml_ml_string_length(s));
}

//Provides: caml_binaryen_expression_finalize
//Requires: binaryen
function caml_binaryen_expression_finalize(exp) {
  binaryen.Expression.finalize(exp);
}

//Provides: caml_binaryen_expression_copy
function caml_binaryen_expression_copy(exp, wasm_mod) {
  return wasm_mod.copyExpression(exp);
}

// Block operations

//Provides: caml_binaryen_block_get_name
//Requires: binaryen
//Requires: to_option
//Requires: caml_string_of_jsstring
function caml_binaryen_block_get_name(exp) {
  var name = binaryen.Block.getName(exp);
  var str = name != null ? caml_string_of_jsstring(name) : null;
  return to_option(str);
}

//Provides: caml_binaryen_block_set_name
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_block_set_name(exp, name) {
  return binaryen.Block.setName(
    exp,
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_block_get_num_children
//Requires: binaryen
function caml_binaryen_block_get_num_children(exp) {
  return binaryen.Block.getNumChildren(exp);
}

//Provides: caml_binaryen_block_get_child_at
//Requires: binaryen
function caml_binaryen_block_get_child_at(exp, index) {
  return binaryen.Block.getChildAt(exp, index);
}

//Provides: caml_binaryen_block_set_child_at
//Requires: binaryen
function caml_binaryen_block_set_child_at(exp, index, child) {
  return binaryen.Block.setChildAt(exp, index, child);
}

//Provides: caml_binaryen_block_append_child
//Requires: binaryen
function caml_binaryen_block_append_child(exp, child) {
  return binaryen.Block.appendChild(exp, child);
}

//Provides: caml_binaryen_block_insert_child_at
//Requires: binaryen
function caml_binaryen_block_insert_child_at(exp, index, child) {
  return binaryen.Block.insertChildAt(exp, index, child);
}

//Provides: caml_binaryen_block_remove_child_at
//Requires: binaryen
function caml_binaryen_block_remove_child_at(exp, index) {
  return binaryen.Block.removeChildAt(exp, index);
}

// If operations

//Provides: caml_binaryen_if_get_condition
//Requires: binaryen
function caml_binaryen_if_get_condition(exp) {
  return binaryen.If.getCondition(exp);
}

//Provides: caml_binaryen_if_set_condition
//Requires: binaryen
function caml_binaryen_if_set_condition(exp, cond) {
  return binaryen.If.setCondition(exp, cond);
}

//Provides: caml_binaryen_if_get_if_true
//Requires: binaryen
function caml_binaryen_if_get_if_true(exp) {
  return binaryen.If.getIfTrue(exp);
}

//Provides: caml_binaryen_if_set_if_true
//Requires: binaryen
function caml_binaryen_if_set_if_true(exp, child) {
  return binaryen.If.setIfTrue(exp, child);
}

//Provides: caml_binaryen_if_get_if_false
//Requires: binaryen
//Requires: to_option
function caml_binaryen_if_get_if_false(exp) {
  return to_option(binaryen.If.getIfFalse(exp));
}

//Provides: caml_binaryen_if_set_if_false
//Requires: binaryen
function caml_binaryen_if_set_if_false(exp, child) {
  return binaryen.If.setIfFalse(exp, child);
}

// Loop operations

//Provides: caml_binaryen_loop_get_name
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_loop_get_name(exp) {
  return caml_string_of_jsstring(binaryen.Loop.getName(exp));
}

//Provides: caml_binaryen_loop_set_name
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_loop_set_name(exp, name) {
  return binaryen.Loop.setName(
    exp,
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_loop_get_body
//Requires: binaryen
function caml_binaryen_loop_get_body(exp) {
  return binaryen.Loop.getBody(exp);
}

//Provides: caml_binaryen_loop_set_body
//Requires: binaryen
function caml_binaryen_loop_set_body(exp, child) {
  return binaryen.Loop.setBody(exp, child);
}

// Break operations

//Provides: caml_binaryen_break_get_name
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_break_get_name(exp) {
  return caml_string_of_jsstring(binaryen.Break.getName(exp));
}

//Provides: caml_binaryen_break_set_name
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_break_set_name(exp, name) {
  return binaryen.Break.setName(
    exp,
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_break_get_condition
//Requires: binaryen
//Requires: to_option
function caml_binaryen_break_get_condition(exp) {
  return to_option(binaryen.Break.getCondition(exp))
}

//Provides: caml_binaryen_break_set_condition
//Requires: binaryen
function caml_binaryen_break_set_condition(exp, child) {
  return binaryen.Break.setCondition(exp, child);
}

//Provides: caml_binaryen_break_get_value
//Requires: binaryen
//Requires: to_option
function caml_binaryen_break_get_value(exp) {
  return to_option(binaryen.Break.getValue(exp));
}

//Provides: caml_binaryen_break_set_value
//Requires: binaryen
function caml_binaryen_break_set_value(exp, child) {
  return binaryen.Break.setValue(exp, child);
}

// Switch operations

//Provides: caml_binaryen_switch_get_num_names
//Requires: binaryen
function caml_binaryen_switch_get_num_names(exp) {
  return binaryen.Switch.getNumNames(exp);
}

//Provides: caml_binaryen_switch_get_name_at
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_switch_get_name_at(exp, index) {
  return caml_string_of_jsstring(binaryen.Switch.getNameAt(exp, index));
}

//Provides: caml_binaryen_switch_set_name_at
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_switch_set_name_at(exp, index, name) {
  return binaryen.Switch.setNameAt(
    exp,
    index,
    caml_jsstring_of_string(name)
  )
}

//Provides: caml_binaryen_switch_append_name
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_switch_append_name(exp, name) {
  return binaryen.Switch.appendName(
    exp,
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_switch_insert_name_at
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_switch_insert_name_at(exp, index, name) {
  return binaryen.Switch.insertNameAt(
    exp,
    index,
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_switch_remove_name_at
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_switch_remove_name_at(exp, index) {
  return caml_string_of_jsstring(binaryen.Switch.removeNameAt(exp, index));
}

//Provides: caml_binaryen_switch_get_default_name
//Requires: binaryen
//Requires: to_option
//Requires: caml_string_of_jsstring
function caml_binaryen_switch_get_default_name(exp) {
  var name = binaryen.Switch.getDefaultName(exp);
  var str = name != null ? caml_string_of_jsstring(name) : null;
  return to_option(str);
}

//Provides: caml_binaryen_switch_set_default_name
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_switch_set_default_name(exp, name) {
  return binaryen.Switch.setDefaultName(
    exp,
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_switch_get_condition
//Requires: binaryen
function caml_binaryen_switch_get_condition(exp) {
  return binaryen.Switch.getCondition(exp);
}

//Provides: caml_binaryen_switch_set_condition
//Requires: binaryen
function caml_binaryen_switch_set_condition(exp, child) {
  return binaryen.Switch.setCondition(exp, child);
}

//Provides: caml_binaryen_switch_get_value
//Requires: binaryen
//Requires: to_option
function caml_binaryen_switch_get_value(exp) {
  return to_option(binaryen.Switch.getValue(exp));
}

//Provides: caml_binaryen_switch_set_value
//Requires: binaryen
function caml_binaryen_switch_set_value(exp, child) {
  return binaryen.Switch.setValue(exp, child);
}

//Provides: caml_binaryen_call_get_target
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_call_get_target(exp) {
  return caml_string_of_jsstring(binaryen.Call.getTarget(exp));
}

//Provides: caml_binaryen_call_set_target
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_call_set_target(exp, name) {
  return binaryen.Call.setTarget(
    exp,
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_call_get_num_operands
//Requires: binaryen
function caml_binaryen_call_get_num_operands(exp) {
  return binaryen.Call.getNumOperands(exp);
}

//Provides: caml_binaryen_call_get_operand_at
//Requires: binaryen
function caml_binaryen_call_get_operand_at(exp, index) {
  return binaryen.Call.getOperandAt(exp, index);
}

//Provides: caml_binaryen_call_set_operand_at
//Requires: binaryen
function caml_binaryen_call_set_operand_at(exp, index, operand) {
  return binaryen.Call.setOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_call_append_operand
//Requires: binaryen
function caml_binaryen_call_append_operand(exp, operand) {
  return binaryen.Call.appendOperand(exp, operand);
}

//Provides: caml_binaryen_call_insert_operand_at
//Requires: binaryen
function caml_binaryen_call_insert_operand_at(exp, index, operand) {
  return binaryen.Call.insertOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_call_remove_operand_at
//Requires: binaryen
function caml_binaryen_call_remove_operand_at(exp, index) {
  return binaryen.Call.removeOperandAt(exp, index);
}

//Provides: caml_binaryen_call_is_return
//Requires: binaryen
//Requires: caml_js_to_bool
function caml_binaryen_call_is_return(exp) {
  return caml_js_to_bool(binaryen.Call.isReturn(exp));
}

//Provides: caml_binaryen_call_set_return
//Requires: binaryen
//Requires: caml_js_from_bool
function caml_binaryen_call_set_return(exp, isReturn) {
  return binaryen.Call.setReturn(
    exp,
    caml_js_from_bool(isReturn)
  );
}

//Provides: caml_binaryen_call_indirect_get_target
//Requires: binaryen
function caml_binaryen_call_indirect_get_target(exp) {
  return binaryen.CallIndirect.getTarget(exp);
}

//Provides: caml_binaryen_call_indirect_set_target
//Requires: binaryen
function caml_binaryen_call_indirect_set_target(exp, target) {
  return binaryen.CallIndirect.setTarget(exp, target);
}

//Provides: caml_binaryen_call_indirect_get_table
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_call_indirect_get_table(exp) {
  return caml_string_of_jsstring(binaryen.CallIndirect.getTable(exp));
}

//Provides: caml_binaryen_call_indirect_set_table
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_call_indirect_set_table(exp, name) {
  return binaryen.CallIndirect.setTable(
    exp,
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_call_indirect_get_num_operands
//Requires: binaryen
function caml_binaryen_call_indirect_get_num_operands(exp) {
  return binaryen.CallIndirect.getNumOperands(exp);
}

//Provides: caml_binaryen_call_indirect_get_operand_at
//Requires: binaryen
function caml_binaryen_call_indirect_get_operand_at(exp, index) {
  return binaryen.CallIndirect.getOperandAt(exp, index);
}

//Provides: caml_binaryen_call_indirect_set_operand_at
//Requires: binaryen
function caml_binaryen_call_indirect_set_operand_at(exp, index, operand) {
  return binaryen.CallIndirect.setOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_call_indirect_append_operand
//Requires: binaryen
function caml_binaryen_call_indirect_append_operand(exp, operand) {
  return binaryen.CallIndirect.appendOperand(exp, operand);
}

//Provides: caml_binaryen_call_indirect_insert_operand_at
//Requires: binaryen
function caml_binaryen_call_indirect_insert_operand_at(exp, index, operand) {
  return binaryen.CallIndirect.insertOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_call_indirect_remove_operand_at
//Requires: binaryen
function caml_binaryen_call_indirect_remove_operand_at(exp, index) {
  return binaryen.CallIndirect.removeOperandAt(exp, index);
}

//Provides: caml_binaryen_call_indirect_is_return
//Requires: binaryen
//Requires: caml_js_to_bool
function caml_binaryen_call_indirect_is_return(exp) {
  return caml_js_to_bool(binaryen.CallIndirect.isReturn(exp));
}

//Provides: caml_binaryen_call_indirect_set_return
//Requires: binaryen
//Requires: caml_js_from_bool
function caml_binaryen_call_indirect_set_return(exp, isReturn) {
  return binaryen.CallIndirect.setReturn(
    exp,
    caml_js_from_bool(isReturn)
  );
}

//Provides: caml_binaryen_local_set_get_value
//Requires: binaryen
function caml_binaryen_local_set_get_value(exp) {
  return binaryen.LocalSet.getValue(exp);
}

//Provides: caml_binaryen_local_set_set_value
//Requires: binaryen
function caml_binaryen_local_set_set_value(exp, value) {
  return binaryen.LocalSet.setValue(exp, value);
}

//Provides: caml_binaryen_global_get_get_name
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_global_get_get_name(exp) {
  return caml_string_of_jsstring(binaryen.GlobalGet.getName(exp));
}

//Provides: caml_binaryen_global_get_set_name
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_global_get_set_name(exp, name) {
  return binaryen.GlobalGet.setName(
    exp,
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_global_set_get_name
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_global_set_get_name(exp) {
  return caml_string_of_jsstring(binaryen.GlobalSet.getName(exp));
}

//Provides: caml_binaryen_global_set_set_name
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_global_set_set_name(exp, name) {
  return binaryen.GlobalSet.setName(
    exp,
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_global_set_get_value
//Requires: binaryen
function caml_binaryen_global_set_get_value(exp) {
  return binaryen.GlobalSet.getValue(exp);
}

//Provides: caml_binaryen_global_set_set_value
//Requires: binaryen
function caml_binaryen_global_set_set_value(exp, value) {
  return binaryen.GlobalSet.setValue(exp, value);
}

//Provides: caml_binaryen_memory_grow_get_delta
//Requires: binaryen
function caml_binaryen_memory_grow_get_delta(exp) {
  return binaryen.MemoryGrow.getDelta(exp);
}

//Provides: caml_binaryen_memory_grow_set_delta
//Requires: binaryen
function caml_binaryen_memory_grow_set_delta(exp, delta) {
  return binaryen.MemoryGrow.setDelta(exp, delta);
}

//Provides: caml_binaryen_load_get_ptr
//Requires: binaryen
function caml_binaryen_load_get_ptr(exp) {
  return binaryen.Load.getPtr(exp);
}

//Provides: caml_binaryen_load_set_ptr
//Requires: binaryen
function caml_binaryen_load_set_ptr(exp, ptr) {
  return binaryen.Load.setPtr(exp, ptr);
}

//Provides: caml_binaryen_store_get_ptr
//Requires: binaryen
function caml_binaryen_store_get_ptr(exp) {
  return binaryen.Store.getPtr(exp);
}

//Provides: caml_binaryen_store_set_ptr
//Requires: binaryen
function caml_binaryen_store_set_ptr(exp, ptr) {
  return binaryen.Store.setPtr(exp, ptr);
}

//Provides: caml_binaryen_store_get_value
//Requires: binaryen
function caml_binaryen_store_get_value(exp) {
  return binaryen.Store.getValue(exp);
}

//Provides: caml_binaryen_store_set_value
//Requires: binaryen
function caml_binaryen_store_set_value(exp, value) {
  return binaryen.Store.setValue(exp, value);
}

//Provides: caml_binaryen_unary_get_value
//Requires: binaryen
function caml_binaryen_unary_get_value(exp) {
  return binaryen.Unary.getValue(exp);
}

//Provides: caml_binaryen_unary_set_value
//Requires: binaryen
function caml_binaryen_unary_set_value(exp, value) {
  return binaryen.Unary.setValue(exp, value);
}

//Provides: caml_binaryen_binary_get_left
//Requires: binaryen
function caml_binaryen_binary_get_left(exp) {
  return binaryen.Binary.getLeft(exp);
}

//Provides: caml_binaryen_binary_set_left
//Requires: binaryen
function caml_binaryen_binary_set_left(exp, value) {
  return binaryen.Binary.setLeft(exp, value);
}

//Provides: caml_binaryen_binary_get_right
//Requires: binaryen
function caml_binaryen_binary_get_right(exp) {
  return binaryen.Binary.getRight(exp);
}

//Provides: caml_binaryen_binary_set_right
//Requires: binaryen
function caml_binaryen_binary_set_right(exp, value) {
  return binaryen.Binary.setRight(exp, value);
}

//Provides: caml_binaryen_select_get_if_true
//Requires: binaryen
function caml_binaryen_select_get_if_true(exp) {
  return binaryen.Select.getIfTrue(exp);
}

//Provides: caml_binaryen_select_set_if_true
//Requires: binaryen
function caml_binaryen_select_set_if_true(exp, value) {
  return binaryen.Select.setIfTrue(exp, value);
}

//Provides: caml_binaryen_select_get_if_false
//Requires: binaryen
function caml_binaryen_select_get_if_false(exp) {
  return binaryen.Select.getIfFalse(exp);
}

//Provides: caml_binaryen_select_set_if_false
//Requires: binaryen
function caml_binaryen_select_set_if_false(exp, value) {
  return binaryen.Select.setIfFalse(exp, value);
}

//Provides: caml_binaryen_select_get_condition
//Requires: binaryen
function caml_binaryen_select_get_condition(exp) {
  return binaryen.Select.getCondition(exp);
}

//Provides: caml_binaryen_select_set_condition
//Requires: binaryen
function caml_binaryen_select_set_condition(exp, value) {
  return binaryen.Select.setCondition(exp, value);
}

//Provides: caml_binaryen_drop_get_value
//Requires: binaryen
function caml_binaryen_drop_get_value(exp) {
  return binaryen.Drop.getValue(exp);
}

//Provides: caml_binaryen_drop_set_value
//Requires: binaryen
function caml_binaryen_drop_set_value(exp, value) {
  return binaryen.Drop.setValue(exp, value);
}

//Provides: caml_binaryen_return_get_value
//Requires: binaryen
//Requires: to_option
function caml_binaryen_return_get_value(exp) {
  return to_option(binaryen.Return.getValue(exp));
}

//Provides: caml_binaryen_return_set_value
//Requires: binaryen
function caml_binaryen_return_set_value(exp, value) {
  return binaryen.Return.setValue(exp, value);
}

//Provides: caml_binaryen_memory_init_get_segment
//Requires: binaryen
function caml_binaryen_memory_init_get_segment(exp) {
  return binaryen.MemoryInit.getSegment(exp);
}

//Provides: caml_binaryen_memory_init_set_segment
//Requires: binaryen
function caml_binaryen_memory_init_set_segment(exp, value) {
  return binaryen.MemoryInit.setSegment(exp, value);
}

//Provides: caml_binaryen_memory_init_get_dest
//Requires: binaryen
function caml_binaryen_memory_init_get_dest(exp) {
  return binaryen.MemoryInit.getDest(exp);
}

//Provides: caml_binaryen_memory_init_set_dest
//Requires: binaryen
function caml_binaryen_memory_init_set_dest(exp, value) {
  return binaryen.MemoryInit.setDest(exp, value);
}

//Provides: caml_binaryen_memory_init_get_offset
//Requires: binaryen
function caml_binaryen_memory_init_get_offset(exp) {
  return binaryen.MemoryInit.getOffset(exp);
}

//Provides: caml_binaryen_memory_init_set_offset
//Requires: binaryen
function caml_binaryen_memory_init_set_offset(exp, value) {
  return binaryen.MemoryInit.setOffset(exp, value);
}

//Provides: caml_binaryen_memory_init_get_size
//Requires: binaryen
function caml_binaryen_memory_init_get_size(exp) {
  return binaryen.MemoryInit.getSize(exp);
}

//Provides: caml_binaryen_memory_init_set_size
//Requires: binaryen
function caml_binaryen_memory_init_set_size(exp, value) {
  return binaryen.MemoryInit.setSize(exp, value);
}

//Provides: caml_binaryen_data_drop_get_segment
//Requires: binaryen
function caml_binaryen_data_drop_get_segment(exp) {
  return binaryen.DataDrop.getSegment(exp);
}

//Provides: caml_binaryen_data_drop_set_segment
//Requires: binaryen
function caml_binaryen_data_drop_set_segment(exp, value) {
  return binaryen.DataDrop.setSegment(exp, value);
}

//Provides: caml_binaryen_memory_copy_get_dest
//Requires: binaryen
function caml_binaryen_memory_copy_get_dest(exp) {
  return binaryen.MemoryCopy.getDest(exp);
}

//Provides: caml_binaryen_memory_copy_set_dest
//Requires: binaryen
function caml_binaryen_memory_copy_set_dest(exp, value) {
  return binaryen.MemoryCopy.setDest(exp, value);
}

//Provides: caml_binaryen_memory_copy_get_source
//Requires: binaryen
function caml_binaryen_memory_copy_get_source(exp) {
  return binaryen.MemoryCopy.getSource(exp);
}

//Provides: caml_binaryen_memory_copy_set_source
//Requires: binaryen
function caml_binaryen_memory_copy_set_source(exp, value) {
  return binaryen.MemoryCopy.setSource(exp, value);
}

//Provides: caml_binaryen_memory_copy_get_size
//Requires: binaryen
function caml_binaryen_memory_copy_get_size(exp) {
  return binaryen.MemoryCopy.getSize(exp);
}

//Provides: caml_binaryen_memory_copy_set_size
//Requires: binaryen
function caml_binaryen_memory_copy_set_size(exp, value) {
  return binaryen.MemoryCopy.setSize(exp, value);
}

//Provides: caml_binaryen_memory_fill_get_dest
//Requires: binaryen
function caml_binaryen_memory_fill_get_dest(exp) {
  return binaryen.MemoryFill.getDest(exp);
}

//Provides: caml_binaryen_memory_fill_set_dest
//Requires: binaryen
function caml_binaryen_memory_fill_set_dest(exp, value) {
  return binaryen.MemoryFill.setDest(exp, value);
}

//Provides: caml_binaryen_memory_fill_get_value
//Requires: binaryen
function caml_binaryen_memory_fill_get_value(exp) {
  return binaryen.MemoryFill.getValue(exp);
}

//Provides: caml_binaryen_memory_fill_set_value
//Requires: binaryen
function caml_binaryen_memory_fill_set_value(exp, value) {
  return binaryen.MemoryFill.setValue(exp, value);
}

//Provides: caml_binaryen_memory_fill_get_size
//Requires: binaryen
function caml_binaryen_memory_fill_get_size(exp) {
  return binaryen.MemoryFill.getSize(exp);
}

//Provides: caml_binaryen_memory_fill_set_size
//Requires: binaryen
function caml_binaryen_memory_fill_set_size(exp, value) {
  return binaryen.MemoryFill.setSize(exp, value);
}

//Provides: caml_binaryen_tuple_make_get_num_operands
//Requires: binaryen
function caml_binaryen_tuple_make_get_num_operands(exp) {
  return binaryen.TupleMake.getNumOperands(exp);
}

//Provides: caml_binaryen_tuple_make_get_operand_at
//Requires: binaryen
function caml_binaryen_tuple_make_get_operand_at(exp, index) {
  return binaryen.TupleMake.getOperandAt(exp, index);
}

//Provides: caml_binaryen_tuple_make_set_operand_at
//Requires: binaryen
function caml_binaryen_tuple_make_set_operand_at(exp, index, operand) {
  return binaryen.TupleMake.setOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_tuple_make_append_operand
//Requires: binaryen
function caml_binaryen_tuple_make_append_operand(exp, operand) {
  return binaryen.TupleMake.appendOperand(exp, operand);
}

//Provides: caml_binaryen_tuple_make_insert_operand_at
//Requires: binaryen
function caml_binaryen_tuple_make_insert_operand_at(exp, index, operand) {
  return binaryen.TupleMake.insertOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_tuple_make_remove_operand_at
//Requires: binaryen
function caml_binaryen_tuple_make_remove_operand_at(exp, index) {
  return binaryen.TupleMake.removeOperandAt(exp, index);
}

//Provides: caml_binaryen_tuple_extract_get_tuple
//Requires: binaryen
function caml_binaryen_tuple_extract_get_tuple(exp) {
  return binaryen.TupleExtract.getTuple(exp);
}

//Provides: caml_binaryen_tuple_extract_set_tuple
//Requires: binaryen
function caml_binaryen_tuple_extract_set_tuple(exp, value) {
  return binaryen.TupleExtract.setTuple(exp, value);
}

// Ref operations

//Provides: caml_binaryen_ref_null
function caml_binaryen_ref_null(wasm_mod, typ) {
  return wasm_mod.ref.null(typ);
}

//Provides: caml_binaryen_ref_is
//Requires: binaryen
function caml_binaryen_ref_is(wasm_mod, op, value) {
  return binaryen._BinaryenRefIs(wasm_mod, op, value);
}

//Provides: caml_binaryen_ref_as
//Requires: binaryen
function caml_binaryen_ref_as(wasm_mod, op, value) {
  return binaryen._BinaryenRefAs(wasm_mod, op, value);
}

//Provides: caml_binaryen_ref_func
//Requires: caml_jsstring_of_string
function caml_binaryen_ref_func(wasm_mod, name, typ) {
  return wasm_mod.ref.func(
    caml_jsstring_of_string(name),
    typ
  );
}

//Provides: caml_binaryen_ref_eq
function caml_binaryen_ref_eq(wasm_mod, left, right) {
  return wasm_mod.ref.func(left, right);
}

// Table operations

//Provides: caml_binaryen_table_get
//Requires: caml_jsstring_of_string
function caml_binaryen_table_get(wasm_mod, name, index, typ) {
  return wasm_mod.table.get(
    caml_jsstring_of_string(name),
    index,
    typ
  );
}

//Provides: caml_binaryen_table_set
//Requires: caml_jsstring_of_string
function caml_binaryen_table_set(wasm_mod, name, index, value) {
  return wasm_mod.table.set(
    caml_jsstring_of_string(name),
    index,
    value
  );
}

//Provides: caml_binaryen_table_size
//Requires: caml_jsstring_of_string
function caml_binaryen_table_size(wasm_mod, name) {
  return wasm_mod.table.size(
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_table_grow
//Requires: caml_jsstring_of_string
function caml_binaryen_table_grow(wasm_mod, name, value, delta) {
  return wasm_mod.table.grow(
    caml_jsstring_of_string(name),
    value,
    delta
  );
}

// TableGet operations

//Provides: caml_binaryen_tableget_get_table
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_tableget_get_table(exp) {
  return caml_string_of_jsstring(binaryen.TableGet.getTable(exp));
}

//Provides: caml_binaryen_tableget_set_table
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_tableget_set_table(exp, table) {
  return binaryen.TableGet.setTable(
    exp,
    caml_jsstring_of_string(table)
  );
}

//Provides: caml_binaryen_tableget_get_index
//Requires: binaryen
function caml_binaryen_tableget_get_index(exp) {
  return binaryen.TableGet.getIndex(exp);
}

//Provides: caml_binaryen_tableget_set_index
//Requires: binaryen
function caml_binaryen_tableget_set_index(exp, index) {
  return binaryen.TableGet.setIndex(exp, index);
}

// TableSet operations

//Provides: caml_binaryen_tableset_get_table
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_tableset_get_table(exp) {
  return caml_string_of_jsstring(binaryen.TableSet.getTable(exp));
}

//Provides: caml_binaryen_tableset_set_table
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_tableset_set_table(exp, table) {
  return binaryen.TableSet.setTable(
    exp,
    caml_jsstring_of_string(table)
  );
}

//Provides: caml_binaryen_tableset_get_index
//Requires: binaryen
function caml_binaryen_tableset_get_index(exp) {
  return binaryen.TableSet.getIndex(exp);
}

//Provides: caml_binaryen_tableset_set_index
//Requires: binaryen
function caml_binaryen_tableset_set_index(exp, index) {
  return binaryen.TableSet.setIndex(exp, index);
}

//Provides: caml_binaryen_tableset_get_value
//Requires: binaryen
function caml_binaryen_tableset_get_value(exp) {
  return binaryen.TableSet.getValue(exp);
}

//Provides: caml_binaryen_tableset_set_value
//Requires: binaryen
function caml_binaryen_tableset_set_value(exp, value) {
  return binaryen.TableSet.setValue(exp, value);
}

// TableSize operations

//Provides: caml_binaryen_tablesize_get_table
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_tablesize_get_table(exp) {
  return caml_string_of_jsstring(binaryen.TableSize.getTable(exp));
}

//Provides: caml_binaryen_tablesize_set_table
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_tablesize_set_table(exp, table) {
  return binaryen.TableSize.setTable(
    exp,
    caml_jsstring_of_string(table)
  );
}

// TableGrow operations

//Provides: caml_binaryen_tablegrow_get_table
//Requires: binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_tablegrow_get_table(exp) {
  return caml_string_of_jsstring(binaryen.TableGrow.getTable(exp));
}

//Provides: caml_binaryen_tablegrow_set_table
//Requires: binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_tablegrow_set_table(exp, table) {
  return binaryen.TableGrow.setTable(
    exp,
    caml_jsstring_of_string(table)
  );
}

//Provides: caml_binaryen_tablegrow_get_value
//Requires: binaryen
function caml_binaryen_tablegrow_get_value(exp) {
  return binaryen.TableGrow.getValue(exp);
}

//Provides: caml_binaryen_tablegrow_set_value
//Requires: binaryen
function caml_binaryen_tablegrow_set_value(exp, value) {
  return binaryen.TableGrow.setValue(exp, value);
}

//Provides: caml_binaryen_tablegrow_get_delta
//Requires: binaryen
function caml_binaryen_tablegrow_get_delta(exp) {
  return binaryen.TableGrow.getDelta(exp);
}

//Provides: caml_binaryen_tablegrow_set_delta
//Requires: binaryen
function caml_binaryen_tablegrow_set_delta(exp, delta) {
  return binaryen.TableGrow.setDelta(exp, delta);
}
