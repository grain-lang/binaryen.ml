//Provides: to_option
function to_option(x) {
  if (x) {
    return [0, x];
  } else {
    return 0;
  }
}

//Provides: caml_binaryen_expression_get_id
//Requires: Binaryen
function caml_binaryen_expression_get_id(expr) {
  return Binaryen.getExpressionId(expr);
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
  return wasm_mod.loop(caml_jsstring_of_string(name), body);
}

//Provides: caml_binaryen_break
//Requires: caml_jsstring_of_string
function caml_binaryen_break(wasm_mod, name, cond, res) {
  return wasm_mod.br(caml_jsstring_of_string(name), cond, res);
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
function caml_binaryen_call_indirect(
  wasm_mod,
  table,
  target,
  params,
  params_typ,
  return_typ
) {
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
  return caml_binaryen_call_indirect(
    arguments[0],
    arguments[1],
    arguments[2],
    arguments[3],
    arguments[4],
    arguments[5]
  );
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
function caml_binaryen_return_call_indirect(
  wasm_mod,
  table,
  target,
  params,
  params_typ,
  return_typ
) {
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
  return caml_binaryen_return_call_indirect(
    arguments[0],
    arguments[1],
    arguments[2],
    arguments[3],
    arguments[4],
    arguments[5]
  );
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
  return wasm_mod.global.get(caml_jsstring_of_string(name), typ);
}

//Provides: caml_binaryen_global_set
//Requires: caml_jsstring_of_string
function caml_binaryen_global_set(wasm_mod, name, value) {
  return wasm_mod.global.set(caml_jsstring_of_string(name), value);
}

//Provides: caml_binaryen_load
//Requires: Binaryen
//Requires: caml_jsstring_of_string
//Requires: caml_failwith
function caml_binaryen_load(
  wasm_mod,
  bytes,
  signed,
  offset,
  align,
  typ,
  ptr,
  memoryName
) {
  var name = caml_jsstring_of_string(memoryName);

  switch (typ) {
    case Binaryen.i32: {
      // Using four bytes doesn't matter if it is signed or unsigned
      if (bytes === 4) {
        return wasm_mod.i32.load(offset, align, ptr, name);
      }

      if (signed) {
        if (bytes === 1) {
          return wasm_mod.i32.load8_s(offset, align, ptr, name);
        }

        if (bytes === 2) {
          return wasm_mod.i32.load16_s(offset, align, ptr, name);
        }
      } else {
        if (bytes === 1) {
          return wasm_mod.i32.load8_u(offset, align, ptr, name);
        }

        if (bytes === 2) {
          return wasm_mod.i32.load16_u(offset, align, ptr, name);
        }
      }

      break;
    }
    case Binaryen.i64: {
      // Using eight bytes doesn't matter if it is signed or unsigned
      if (bytes === 8) {
        return wasm_mod.i64.load(offset, align, ptr, name);
      }

      if (signed) {
        if (bytes === 1) {
          return wasm_mod.i64.load8_s(offset, align, ptr, name);
        }

        if (bytes === 2) {
          return wasm_mod.i64.load16_s(offset, align, ptr, name);
        }

        if (bytes === 4) {
          return wasm_mod.i64.load32_s(offset, align, ptr, name);
        }
      } else {
        if (bytes === 1) {
          return wasm_mod.i64.load8_u(offset, align, ptr, name);
        }

        if (bytes === 2) {
          return wasm_mod.i64.load16_u(offset, align, ptr, name);
        }

        if (bytes === 4) {
          return wasm_mod.i64.load32_u(offset, align, ptr, name);
        }
      }

      break;
    }
    case Binaryen.f32: {
      return wasm_mod.f32.load(offset, align, ptr, name);
    }
    case Binaryen.f64: {
      return wasm_mod.f64.load(offset, align, ptr, name);
    }
    case Binaryen.v128: {
      return wasm_mod.v128.load(offset, align, ptr, name);
    }
    default: {
      caml_failwith("Invalid arguments to BinaryenLoad");
    }
  }
}
//Provides: caml_binaryen_load__bytecode
//Requires: caml_binaryen_load
function caml_binaryen_load__bytecode() {
  return caml_binaryen_load(
    arguments[0],
    arguments[1],
    arguments[2],
    arguments[3],
    arguments[4],
    arguments[5],
    arguments[6],
    arguments[7]
  );
}

//Provides: caml_binaryen_store
//Requires: Binaryen
//Requires: caml_jsstring_of_string
//Requires: caml_failwith
function caml_binaryen_store(
  wasm_mod,
  bytes,
  offset,
  align,
  ptr,
  value,
  typ,
  memoryName
) {
  var name = caml_jsstring_of_string(memoryName);

  switch (typ) {
    case Binaryen.i32: {
      if (bytes === 4) {
        return wasm_mod.i32.store(offset, align, ptr, value, name);
      }

      if (bytes === 1) {
        return wasm_mod.i32.store8(offset, align, ptr, value, name);
      }

      if (bytes === 2) {
        return wasm_mod.i32.store16(offset, align, ptr, value, name);
      }

      break;
    }
    case Binaryen.i64: {
      if (bytes === 8) {
        return wasm_mod.i64.store(offset, align, ptr, value, name);
      }

      if (bytes === 1) {
        return wasm_mod.i64.store8(offset, align, ptr, value, name);
      }

      if (bytes === 2) {
        return wasm_mod.i64.store16(offset, align, ptr, value, name);
      }

      if (bytes === 4) {
        return wasm_mod.i64.store32(offset, align, ptr, value, name);
      }

      break;
    }
    case Binaryen.f32: {
      return wasm_mod.f32.store(offset, align, ptr, value, name);
    }
    case Binaryen.f64: {
      return wasm_mod.f64.store(offset, align, ptr, value, name);
    }
    case Binaryen.v128: {
      return wasm_mod.v128.store(offset, align, ptr, value, name);
    }
    default: {
      caml_failwith("Invalid arguments to BinaryenStore");
    }
  }
}
//Provides: caml_binaryen_store__bytecode
//Requires: caml_binaryen_store
function caml_binaryen_store__bytecode() {
  return caml_binaryen_store(
    arguments[0],
    arguments[1],
    arguments[2],
    arguments[3],
    arguments[4],
    arguments[5],
    arguments[6],
    arguments[7]
  );
}

//Provides: caml_binaryen_const
//Requires: caml_int64_lo32, caml_int64_hi32
//Requires: caml_failwith
function caml_binaryen_const(wasm_mod, lit) {
  if (lit.type === "int32") {
    return wasm_mod.i32.const(lit.value);
  }

  if (lit.type === "int64") {
    return wasm_mod.i64.const(
      caml_int64_lo32(lit.value),
      caml_int64_hi32(lit.value)
    );
  }

  if (lit.type === "float64") {
    return wasm_mod.f64.const(lit.value);
  }

  if (lit.type === "float32_bits") {
    return wasm_mod.f32.const_bits(lit.value);
  }

  if (lit.type === "float64_bits") {
    return wasm_mod.f64.const_bits(
      caml_int64_lo32(lit.value),
      caml_int64_hi32(lit.value)
    );
  }

  caml_failwith("invalid Literal for Binaryen.Const.make");
}

//Provides: caml_binaryen_unary
//Requires: Binaryen
function caml_binaryen_unary(wasm_mod, op, p) {
  return Binaryen._BinaryenUnary(wasm_mod, op, p);
}

//Provides: caml_binaryen_binary
//Requires: Binaryen
function caml_binaryen_binary(wasm_mod, op, p1, p2) {
  return Binaryen._BinaryenBinary(wasm_mod, op, p1, p2);
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
//Requires: caml_jsstring_of_string, caml_js_from_bool
function caml_binaryen_memory_size(wasm_mod, memoryName, memoryIs64) {
  return wasm_mod.memory.size(
    caml_jsstring_of_string(memoryName),
    caml_js_from_bool(memoryIs64)
  );
}

//Provides: caml_binaryen_memory_grow
//Requires: caml_jsstring_of_string, caml_js_from_bool
function caml_binaryen_memory_grow(wasm_mod, value, memoryName, memoryIs64) {
  return wasm_mod.memory.grow(
    value,
    caml_jsstring_of_string(memoryName),
    caml_js_from_bool(memoryIs64)
  );
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
//Requires: caml_jsstring_of_string
function caml_binaryen_memory_init(
  wasm_mod,
  segment,
  dest,
  offset,
  size,
  memoryName
) {
  return wasm_mod.memory.init(
    caml_jsstring_of_string(segment),
    dest,
    offset,
    size,
    caml_jsstring_of_string(memoryName)
  );
}
//Provides: caml_binaryen_memory_init__bytecode
//Requires: caml_binaryen_memory_init
function caml_binaryen_memory_init__bytecode() {
  return caml_binaryen_memory_init(
    arguments[0],
    arguments[1],
    arguments[2],
    arguments[3],
    arguments[4],
    arguments[5]
  );
}

//Provides: caml_binaryen_data_drop
//Requires: caml_jsstring_of_string
function caml_binaryen_data_drop(wasm_mod, segment) {
  return wasm_mod.data.drop(caml_jsstring_of_string(segment));
}

//Provides: caml_binaryen_memory_copy
//Requires: caml_jsstring_of_string
function caml_binaryen_memory_copy(
  wasm_mod,
  dest,
  source,
  size,
  dest_memory,
  source_memory
) {
  return wasm_mod.memory.copy(
    dest,
    source,
    size,
    caml_jsstring_of_string(dest_memory),
    caml_jsstring_of_string(source_memory)
  );
}
//Provides: caml_binaryen_memory_copy__bytecode
//Requires: caml_binaryen_memory_copy
function caml_binaryen_memory_copy__bytecode() {
  return caml_binaryen_memory_copy(
    arguments[0],
    arguments[1],
    arguments[2],
    arguments[3],
    arguments[4],
    arguments[5]
  );
}

//Provides: caml_binaryen_memory_fill
//Requires: caml_jsstring_of_string
function caml_binaryen_memory_fill(wasm_mod, dest, value, size, memoryName) {
  return wasm_mod.memory.fill(
    dest,
    value,
    size,
    caml_jsstring_of_string(memoryName)
  );
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
//Requires: Binaryen
function caml_binaryen_pop(wasm_mod, typ) {
  return Binaryen._BinaryenPop(wasm_mod, typ);
}

//Provides: caml_binaryen_i31_new
function caml_binaryen_i31_new(wasm_mod, typ) {
  return wasm_mod.i31.new(typ);
}

//Provides: caml_binaryen_i31_get
function caml_binaryen_i31_get(wasm_mod, typ, signed) {
  if (signed) {
    return wasm_mod.i31.get_s(typ);
  } else {
    return wasm_mod.i31.get_u(typ);
  }
}

//Provides: caml_binaryen_expression_id_invalid
//Requires: Binaryen
function caml_binaryen_expression_id_invalid() {
  return Binaryen.InvalidId;
}

//Provides: caml_binaryen_expression_id_nop
//Requires: Binaryen
function caml_binaryen_expression_id_nop() {
  return Binaryen.NopId;
}
//Provides: caml_binaryen_expression_id_block
//Requires: Binaryen
function caml_binaryen_expression_id_block() {
  return Binaryen.BlockId;
}
//Provides: caml_binaryen_expression_id_if
//Requires: Binaryen
function caml_binaryen_expression_id_if() {
  return Binaryen.IfId;
}
//Provides: caml_binaryen_expression_id_loop
//Requires: Binaryen
function caml_binaryen_expression_id_loop() {
  return Binaryen.LoopId;
}
//Provides: caml_binaryen_expression_id_break
//Requires: Binaryen
function caml_binaryen_expression_id_break() {
  return Binaryen.BreakId;
}
//Provides: caml_binaryen_expression_id_switch
//Requires: Binaryen
function caml_binaryen_expression_id_switch() {
  return Binaryen.SwitchId;
}
//Provides: caml_binaryen_expression_id_call
//Requires: Binaryen
function caml_binaryen_expression_id_call() {
  return Binaryen.CallId;
}
//Provides: caml_binaryen_expression_id_call_indirect
//Requires: Binaryen
function caml_binaryen_expression_id_call_indirect() {
  return Binaryen.CallIndirectId;
}
//Provides: caml_binaryen_expression_id_local_get
//Requires: Binaryen
function caml_binaryen_expression_id_local_get() {
  return Binaryen.LocalGetId;
}
//Provides: caml_binaryen_expression_id_local_set
//Requires: Binaryen
function caml_binaryen_expression_id_local_set() {
  return Binaryen.LocalSetId;
}
//Provides: caml_binaryen_expression_id_global_get
//Requires: Binaryen
function caml_binaryen_expression_id_global_get() {
  return Binaryen.GlobalGetId;
}
//Provides: caml_binaryen_expression_id_global_set
//Requires: Binaryen
function caml_binaryen_expression_id_global_set() {
  return Binaryen.GlobalSetId;
}
//Provides: caml_binaryen_expression_id_load
//Requires: Binaryen
function caml_binaryen_expression_id_load() {
  return Binaryen.LoadId;
}
//Provides: caml_binaryen_expression_id_store
//Requires: Binaryen
function caml_binaryen_expression_id_store() {
  return Binaryen.StoreId;
}
//Provides: caml_binaryen_expression_id_atomic_rmw
//Requires: Binaryen
function caml_binaryen_expression_id_atomic_rmw() {
  return Binaryen.AtomicRMWId;
}
//Provides: caml_binaryen_expression_id_atomic_cmpxchg
//Requires: Binaryen
function caml_binaryen_expression_id_atomic_cmpxchg() {
  return Binaryen.AtomicCmpxchgId;
}
//Provides: caml_binaryen_expression_id_atomic_wait
//Requires: Binaryen
function caml_binaryen_expression_id_atomic_wait() {
  return Binaryen.AtomicWaitId;
}
//Provides: caml_binaryen_expression_id_atomic_notify
//Requires: Binaryen
function caml_binaryen_expression_id_atomic_notify() {
  return Binaryen.AtomicNotifyId;
}
//Provides: caml_binaryen_expression_id_atomic_fence
//Requires: Binaryen
function caml_binaryen_expression_id_atomic_fence() {
  return Binaryen.AtomicFenceId;
}
//Provides: caml_binaryen_expression_id_simd_extract
//Requires: Binaryen
function caml_binaryen_expression_id_simd_extract() {
  return Binaryen.SIMDExtractId;
}
//Provides: caml_binaryen_expression_id_simd_replace
//Requires: Binaryen
function caml_binaryen_expression_id_simd_replace() {
  return Binaryen.SIMDReplaceId;
}
//Provides: caml_binaryen_expression_id_simd_shuffle
//Requires: Binaryen
function caml_binaryen_expression_id_simd_shuffle() {
  return Binaryen.SIMDShuffleId;
}
//Provides: caml_binaryen_expression_id_simd_ternary
//Requires: Binaryen
function caml_binaryen_expression_id_simd_ternary() {
  return Binaryen.SIMDTernaryId;
}
//Provides: caml_binaryen_expression_id_simd_shift
//Requires: Binaryen
function caml_binaryen_expression_id_simd_shift() {
  return Binaryen.SIMDShiftId;
}
//Provides: caml_binaryen_expression_id_simd_load
//Requires: Binaryen
function caml_binaryen_expression_id_simd_load() {
  return Binaryen.SIMDLoadId;
}
//Provides: caml_binaryen_expression_id_simd_load_store_lane
//Requires: Binaryen
function caml_binaryen_expression_id_simd_load_store_lane() {
  return Binaryen.SIMDLoadStoreLaneId;
}
//Provides: caml_binaryen_expression_id_memory_init
//Requires: Binaryen
function caml_binaryen_expression_id_memory_init() {
  return Binaryen.MemoryInitId;
}
//Provides: caml_binaryen_expression_id_data_drop
//Requires: Binaryen
function caml_binaryen_expression_id_data_drop() {
  return Binaryen.DataDropId;
}
//Provides: caml_binaryen_expression_id_memory_copy
//Requires: Binaryen
function caml_binaryen_expression_id_memory_copy() {
  return Binaryen.MemoryCopyId;
}
//Provides: caml_binaryen_expression_id_memory_fill
//Requires: Binaryen
function caml_binaryen_expression_id_memory_fill() {
  return Binaryen.MemoryFillId;
}
//Provides: caml_binaryen_expression_id_const
//Requires: Binaryen
function caml_binaryen_expression_id_const() {
  return Binaryen.ConstId;
}
//Provides: caml_binaryen_expression_id_unary
//Requires: Binaryen
function caml_binaryen_expression_id_unary() {
  return Binaryen.UnaryId;
}
//Provides: caml_binaryen_expression_id_binary
//Requires: Binaryen
function caml_binaryen_expression_id_binary() {
  return Binaryen.BinaryId;
}
//Provides: caml_binaryen_expression_id_select
//Requires: Binaryen
function caml_binaryen_expression_id_select() {
  return Binaryen.SelectId;
}
//Provides: caml_binaryen_expression_id_drop
//Requires: Binaryen
function caml_binaryen_expression_id_drop() {
  return Binaryen.DropId;
}
//Provides: caml_binaryen_expression_id_return
//Requires: Binaryen
function caml_binaryen_expression_id_return() {
  return Binaryen.ReturnId;
}
//Provides: caml_binaryen_expression_id_memory_size
//Requires: Binaryen
function caml_binaryen_expression_id_memory_size() {
  return Binaryen.MemorySizeId;
}
//Provides: caml_binaryen_expression_id_memory_grow
//Requires: Binaryen
function caml_binaryen_expression_id_memory_grow() {
  return Binaryen.MemoryGrowId;
}
//Provides: caml_binaryen_expression_id_unreachable
//Requires: Binaryen
function caml_binaryen_expression_id_unreachable() {
  return Binaryen.UnreachableId;
}
//Provides: caml_binaryen_expression_id_pop
//Requires: Binaryen
function caml_binaryen_expression_id_pop() {
  return Binaryen.PopId;
}
//Provides: caml_binaryen_expression_id_ref_null
//Requires: Binaryen
function caml_binaryen_expression_id_ref_null() {
  return Binaryen.RefNullId;
}
//Provides: caml_binaryen_expression_id_ref_is_null
//Requires: Binaryen
function caml_binaryen_expression_id_ref_is_null() {
  return Binaryen.RefIsNullId;
}
//Provides: caml_binaryen_expression_id_ref_as
//Requires: Binaryen
function caml_binaryen_expression_id_ref_as() {
  return Binaryen.RefAsId;
}
//Provides: caml_binaryen_expression_id_ref_func
//Requires: Binaryen
function caml_binaryen_expression_id_ref_func() {
  return Binaryen.RefFuncId;
}
//Provides: caml_binaryen_expression_id_ref_eq
//Requires: Binaryen
function caml_binaryen_expression_id_ref_eq() {
  return Binaryen.RefEqId;
}
//Provides: caml_binaryen_expression_id_try
//Requires: Binaryen
function caml_binaryen_expression_id_try() {
  return Binaryen.TryId;
}
//Provides: caml_binaryen_expression_id_throw
//Requires: Binaryen
function caml_binaryen_expression_id_throw() {
  return Binaryen.ThrowId;
}
//Provides: caml_binaryen_expression_id_rethrow
//Requires: Binaryen
function caml_binaryen_expression_id_rethrow() {
  return Binaryen.RethrowId;
}
//Provides: caml_binaryen_expression_id_tuple_make
//Requires: Binaryen
function caml_binaryen_expression_id_tuple_make() {
  return Binaryen.TupleMakeId;
}
//Provides: caml_binaryen_expression_id_tuple_extract
//Requires: Binaryen
function caml_binaryen_expression_id_tuple_extract() {
  return Binaryen.TupleExtractId;
}
//Provides: caml_binaryen_expression_id_i31_new
//Requires: Binaryen
function caml_binaryen_expression_id_i31_new() {
  return Binaryen.I31NewId;
}
//Provides: caml_binaryen_expression_id_i31_get
//Requires: Binaryen
function caml_binaryen_expression_id_i31_get() {
  return Binaryen.I31GetId;
}
//Provides: caml_binaryen_expression_id_call_ref
//Requires: Binaryen
function caml_binaryen_expression_id_call_ref() {
  return Binaryen.CallRefId;
}
//Provides: caml_binaryen_expression_id_ref_test
//Requires: Binaryen
function caml_binaryen_expression_id_ref_test() {
  return Binaryen.RefTestId;
}
//Provides: caml_binaryen_expression_id_ref_cast
//Requires: Binaryen
function caml_binaryen_expression_id_ref_cast() {
  return Binaryen.RefCastId;
}
//Provides: caml_binaryen_expression_id_br_on
//Requires: Binaryen
function caml_binaryen_expression_id_br_on() {
  return Binaryen.BrOnId;
}
//Provides: caml_binaryen_expression_id_struct_new
//Requires: Binaryen
function caml_binaryen_expression_id_struct_new() {
  return Binaryen.StructNewId;
}
//Provides: caml_binaryen_expression_id_struct_get
//Requires: Binaryen
function caml_binaryen_expression_id_struct_get() {
  return Binaryen.StructGetId;
}
//Provides: caml_binaryen_expression_id_struct_set
//Requires: Binaryen
function caml_binaryen_expression_id_struct_set() {
  return Binaryen.StructSetId;
}
//Provides: caml_binaryen_expression_id_array_new
//Requires: Binaryen
function caml_binaryen_expression_id_array_new() {
  return Binaryen.ArrayNewId;
}
//Provides: caml_binaryen_expression_id_array_get
//Requires: Binaryen
function caml_binaryen_expression_id_array_get() {
  return Binaryen.ArrayGetId;
}
//Provides: caml_binaryen_expression_id_array_set
//Requires: Binaryen
function caml_binaryen_expression_id_array_set() {
  return Binaryen.ArraySetId;
}
//Provides: caml_binaryen_expression_id_array_len
//Requires: Binaryen
function caml_binaryen_expression_id_array_len() {
  return Binaryen.ArrayLenId;
}

// Expression operations

//Provides: caml_binaryen_expression_print
//Requires: Binaryen
//Requires: caml_string_of_jsstring
//Requires: caml_ml_output, caml_ml_string_length
function caml_binaryen_expression_print(expr) {
  var text = Binaryen.emitText(expr);
  var chanid = 1; // stdout
  var s = caml_string_of_jsstring(text);
  caml_ml_output(chanid, s, 0, caml_ml_string_length(s));
}

//Provides: caml_binaryen_expression_finalize
//Requires: Binaryen
function caml_binaryen_expression_finalize(exp) {
  Binaryen.Expression.finalize(exp);
}

//Provides: caml_binaryen_expression_copy
function caml_binaryen_expression_copy(exp, wasm_mod) {
  return wasm_mod.copyExpression(exp);
}

// Block operations

//Provides: caml_binaryen_block_get_name
//Requires: Binaryen
//Requires: to_option
//Requires: caml_string_of_jsstring
function caml_binaryen_block_get_name(exp) {
  var name = Binaryen.Block.getName(exp);
  var str = name != null ? caml_string_of_jsstring(name) : null;
  return to_option(str);
}

//Provides: caml_binaryen_block_set_name
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_block_set_name(exp, name) {
  return Binaryen.Block.setName(exp, caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_block_get_num_children
//Requires: Binaryen
function caml_binaryen_block_get_num_children(exp) {
  return Binaryen.Block.getNumChildren(exp);
}

//Provides: caml_binaryen_block_get_child_at
//Requires: Binaryen
function caml_binaryen_block_get_child_at(exp, index) {
  return Binaryen.Block.getChildAt(exp, index);
}

//Provides: caml_binaryen_block_set_child_at
//Requires: Binaryen
function caml_binaryen_block_set_child_at(exp, index, child) {
  return Binaryen.Block.setChildAt(exp, index, child);
}

//Provides: caml_binaryen_block_append_child
//Requires: Binaryen
function caml_binaryen_block_append_child(exp, child) {
  return Binaryen.Block.appendChild(exp, child);
}

//Provides: caml_binaryen_block_insert_child_at
//Requires: Binaryen
function caml_binaryen_block_insert_child_at(exp, index, child) {
  return Binaryen.Block.insertChildAt(exp, index, child);
}

//Provides: caml_binaryen_block_remove_child_at
//Requires: Binaryen
function caml_binaryen_block_remove_child_at(exp, index) {
  return Binaryen.Block.removeChildAt(exp, index);
}

// If operations

//Provides: caml_binaryen_if_get_condition
//Requires: Binaryen
function caml_binaryen_if_get_condition(exp) {
  return Binaryen.If.getCondition(exp);
}

//Provides: caml_binaryen_if_set_condition
//Requires: Binaryen
function caml_binaryen_if_set_condition(exp, cond) {
  return Binaryen.If.setCondition(exp, cond);
}

//Provides: caml_binaryen_if_get_if_true
//Requires: Binaryen
function caml_binaryen_if_get_if_true(exp) {
  return Binaryen.If.getIfTrue(exp);
}

//Provides: caml_binaryen_if_set_if_true
//Requires: Binaryen
function caml_binaryen_if_set_if_true(exp, child) {
  return Binaryen.If.setIfTrue(exp, child);
}

//Provides: caml_binaryen_if_get_if_false
//Requires: Binaryen
//Requires: to_option
function caml_binaryen_if_get_if_false(exp) {
  return to_option(Binaryen.If.getIfFalse(exp));
}

//Provides: caml_binaryen_if_set_if_false
//Requires: Binaryen
function caml_binaryen_if_set_if_false(exp, child) {
  return Binaryen.If.setIfFalse(exp, child);
}

// Loop operations

//Provides: caml_binaryen_loop_get_name
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_loop_get_name(exp) {
  return caml_string_of_jsstring(Binaryen.Loop.getName(exp));
}

//Provides: caml_binaryen_loop_set_name
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_loop_set_name(exp, name) {
  return Binaryen.Loop.setName(exp, caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_loop_get_body
//Requires: Binaryen
function caml_binaryen_loop_get_body(exp) {
  return Binaryen.Loop.getBody(exp);
}

//Provides: caml_binaryen_loop_set_body
//Requires: Binaryen
function caml_binaryen_loop_set_body(exp, child) {
  return Binaryen.Loop.setBody(exp, child);
}

// Break operations

//Provides: caml_binaryen_break_get_name
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_break_get_name(exp) {
  return caml_string_of_jsstring(Binaryen.Break.getName(exp));
}

//Provides: caml_binaryen_break_set_name
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_break_set_name(exp, name) {
  return Binaryen.Break.setName(exp, caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_break_get_condition
//Requires: Binaryen
//Requires: to_option
function caml_binaryen_break_get_condition(exp) {
  return to_option(Binaryen.Break.getCondition(exp));
}

//Provides: caml_binaryen_break_set_condition
//Requires: Binaryen
function caml_binaryen_break_set_condition(exp, child) {
  return Binaryen.Break.setCondition(exp, child);
}

//Provides: caml_binaryen_break_get_value
//Requires: Binaryen
//Requires: to_option
function caml_binaryen_break_get_value(exp) {
  return to_option(Binaryen.Break.getValue(exp));
}

//Provides: caml_binaryen_break_set_value
//Requires: Binaryen
function caml_binaryen_break_set_value(exp, child) {
  return Binaryen.Break.setValue(exp, child);
}

// Switch operations

//Provides: caml_binaryen_switch_get_num_names
//Requires: Binaryen
function caml_binaryen_switch_get_num_names(exp) {
  return Binaryen.Switch.getNumNames(exp);
}

//Provides: caml_binaryen_switch_get_name_at
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_switch_get_name_at(exp, index) {
  return caml_string_of_jsstring(Binaryen.Switch.getNameAt(exp, index));
}

//Provides: caml_binaryen_switch_set_name_at
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_switch_set_name_at(exp, index, name) {
  return Binaryen.Switch.setNameAt(exp, index, caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_switch_append_name
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_switch_append_name(exp, name) {
  return Binaryen.Switch.appendName(exp, caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_switch_insert_name_at
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_switch_insert_name_at(exp, index, name) {
  return Binaryen.Switch.insertNameAt(
    exp,
    index,
    caml_jsstring_of_string(name)
  );
}

//Provides: caml_binaryen_switch_remove_name_at
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_switch_remove_name_at(exp, index) {
  return caml_string_of_jsstring(Binaryen.Switch.removeNameAt(exp, index));
}

//Provides: caml_binaryen_switch_get_default_name
//Requires: Binaryen
//Requires: to_option
//Requires: caml_string_of_jsstring
function caml_binaryen_switch_get_default_name(exp) {
  var name = Binaryen.Switch.getDefaultName(exp);
  var str = name != null ? caml_string_of_jsstring(name) : null;
  return to_option(str);
}

//Provides: caml_binaryen_switch_set_default_name
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_switch_set_default_name(exp, name) {
  return Binaryen.Switch.setDefaultName(exp, caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_switch_get_condition
//Requires: Binaryen
function caml_binaryen_switch_get_condition(exp) {
  return Binaryen.Switch.getCondition(exp);
}

//Provides: caml_binaryen_switch_set_condition
//Requires: Binaryen
function caml_binaryen_switch_set_condition(exp, child) {
  return Binaryen.Switch.setCondition(exp, child);
}

//Provides: caml_binaryen_switch_get_value
//Requires: Binaryen
//Requires: to_option
function caml_binaryen_switch_get_value(exp) {
  return to_option(Binaryen.Switch.getValue(exp));
}

//Provides: caml_binaryen_switch_set_value
//Requires: Binaryen
function caml_binaryen_switch_set_value(exp, child) {
  return Binaryen.Switch.setValue(exp, child);
}

//Provides: caml_binaryen_call_get_target
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_call_get_target(exp) {
  return caml_string_of_jsstring(Binaryen.Call.getTarget(exp));
}

//Provides: caml_binaryen_call_set_target
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_call_set_target(exp, name) {
  return Binaryen.Call.setTarget(exp, caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_call_get_num_operands
//Requires: Binaryen
function caml_binaryen_call_get_num_operands(exp) {
  return Binaryen.Call.getNumOperands(exp);
}

//Provides: caml_binaryen_call_get_operand_at
//Requires: Binaryen
function caml_binaryen_call_get_operand_at(exp, index) {
  return Binaryen.Call.getOperandAt(exp, index);
}

//Provides: caml_binaryen_call_set_operand_at
//Requires: Binaryen
function caml_binaryen_call_set_operand_at(exp, index, operand) {
  return Binaryen.Call.setOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_call_append_operand
//Requires: Binaryen
function caml_binaryen_call_append_operand(exp, operand) {
  return Binaryen.Call.appendOperand(exp, operand);
}

//Provides: caml_binaryen_call_insert_operand_at
//Requires: Binaryen
function caml_binaryen_call_insert_operand_at(exp, index, operand) {
  return Binaryen.Call.insertOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_call_remove_operand_at
//Requires: Binaryen
function caml_binaryen_call_remove_operand_at(exp, index) {
  return Binaryen.Call.removeOperandAt(exp, index);
}

//Provides: caml_binaryen_call_is_return
//Requires: Binaryen
//Requires: caml_js_to_bool
function caml_binaryen_call_is_return(exp) {
  return caml_js_to_bool(Binaryen.Call.isReturn(exp));
}

//Provides: caml_binaryen_call_set_return
//Requires: Binaryen
//Requires: caml_js_from_bool
function caml_binaryen_call_set_return(exp, isReturn) {
  return Binaryen.Call.setReturn(exp, caml_js_from_bool(isReturn));
}

//Provides: caml_binaryen_call_indirect_get_target
//Requires: Binaryen
function caml_binaryen_call_indirect_get_target(exp) {
  return Binaryen.CallIndirect.getTarget(exp);
}

//Provides: caml_binaryen_call_indirect_set_target
//Requires: Binaryen
function caml_binaryen_call_indirect_set_target(exp, target) {
  return Binaryen.CallIndirect.setTarget(exp, target);
}

//Provides: caml_binaryen_call_indirect_get_table
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_call_indirect_get_table(exp) {
  return caml_string_of_jsstring(Binaryen.CallIndirect.getTable(exp));
}

//Provides: caml_binaryen_call_indirect_set_table
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_call_indirect_set_table(exp, name) {
  return Binaryen.CallIndirect.setTable(exp, caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_call_indirect_get_num_operands
//Requires: Binaryen
function caml_binaryen_call_indirect_get_num_operands(exp) {
  return Binaryen.CallIndirect.getNumOperands(exp);
}

//Provides: caml_binaryen_call_indirect_get_operand_at
//Requires: Binaryen
function caml_binaryen_call_indirect_get_operand_at(exp, index) {
  return Binaryen.CallIndirect.getOperandAt(exp, index);
}

//Provides: caml_binaryen_call_indirect_set_operand_at
//Requires: Binaryen
function caml_binaryen_call_indirect_set_operand_at(exp, index, operand) {
  return Binaryen.CallIndirect.setOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_call_indirect_append_operand
//Requires: Binaryen
function caml_binaryen_call_indirect_append_operand(exp, operand) {
  return Binaryen.CallIndirect.appendOperand(exp, operand);
}

//Provides: caml_binaryen_call_indirect_insert_operand_at
//Requires: Binaryen
function caml_binaryen_call_indirect_insert_operand_at(exp, index, operand) {
  return Binaryen.CallIndirect.insertOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_call_indirect_remove_operand_at
//Requires: Binaryen
function caml_binaryen_call_indirect_remove_operand_at(exp, index) {
  return Binaryen.CallIndirect.removeOperandAt(exp, index);
}

//Provides: caml_binaryen_call_indirect_is_return
//Requires: Binaryen
//Requires: caml_js_to_bool
function caml_binaryen_call_indirect_is_return(exp) {
  return caml_js_to_bool(Binaryen.CallIndirect.isReturn(exp));
}

//Provides: caml_binaryen_call_indirect_set_return
//Requires: Binaryen
//Requires: caml_js_from_bool
function caml_binaryen_call_indirect_set_return(exp, isReturn) {
  return Binaryen.CallIndirect.setReturn(exp, caml_js_from_bool(isReturn));
}

//Provides: caml_binaryen_local_set_get_value
//Requires: Binaryen
function caml_binaryen_local_set_get_value(exp) {
  return Binaryen.LocalSet.getValue(exp);
}

//Provides: caml_binaryen_local_set_set_value
//Requires: Binaryen
function caml_binaryen_local_set_set_value(exp, value) {
  return Binaryen.LocalSet.setValue(exp, value);
}

//Provides: caml_binaryen_global_get_get_name
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_global_get_get_name(exp) {
  return caml_string_of_jsstring(Binaryen.GlobalGet.getName(exp));
}

//Provides: caml_binaryen_global_get_set_name
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_global_get_set_name(exp, name) {
  return Binaryen.GlobalGet.setName(exp, caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_global_set_get_name
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_global_set_get_name(exp) {
  return caml_string_of_jsstring(Binaryen.GlobalSet.getName(exp));
}

//Provides: caml_binaryen_global_set_set_name
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_global_set_set_name(exp, name) {
  return Binaryen.GlobalSet.setName(exp, caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_global_set_get_value
//Requires: Binaryen
function caml_binaryen_global_set_get_value(exp) {
  return Binaryen.GlobalSet.getValue(exp);
}

//Provides: caml_binaryen_global_set_set_value
//Requires: Binaryen
function caml_binaryen_global_set_set_value(exp, value) {
  return Binaryen.GlobalSet.setValue(exp, value);
}

//Provides: caml_binaryen_memory_grow_get_delta
//Requires: Binaryen
function caml_binaryen_memory_grow_get_delta(exp) {
  return Binaryen.MemoryGrow.getDelta(exp);
}

//Provides: caml_binaryen_memory_grow_set_delta
//Requires: Binaryen
function caml_binaryen_memory_grow_set_delta(exp, delta) {
  return Binaryen.MemoryGrow.setDelta(exp, delta);
}

//Provides: caml_binaryen_load_get_ptr
//Requires: Binaryen
function caml_binaryen_load_get_ptr(exp) {
  return Binaryen.Load.getPtr(exp);
}

//Provides: caml_binaryen_load_set_ptr
//Requires: Binaryen
function caml_binaryen_load_set_ptr(exp, ptr) {
  return Binaryen.Load.setPtr(exp, ptr);
}

//Provides: caml_binaryen_store_get_ptr
//Requires: Binaryen
function caml_binaryen_store_get_ptr(exp) {
  return Binaryen.Store.getPtr(exp);
}

//Provides: caml_binaryen_store_set_ptr
//Requires: Binaryen
function caml_binaryen_store_set_ptr(exp, ptr) {
  return Binaryen.Store.setPtr(exp, ptr);
}

//Provides: caml_binaryen_store_get_value
//Requires: Binaryen
function caml_binaryen_store_get_value(exp) {
  return Binaryen.Store.getValue(exp);
}

//Provides: caml_binaryen_store_set_value
//Requires: Binaryen
function caml_binaryen_store_set_value(exp, value) {
  return Binaryen.Store.setValue(exp, value);
}

//Provides: caml_binaryen_unary_get_value
//Requires: Binaryen
function caml_binaryen_unary_get_value(exp) {
  return Binaryen.Unary.getValue(exp);
}

//Provides: caml_binaryen_unary_set_value
//Requires: Binaryen
function caml_binaryen_unary_set_value(exp, value) {
  return Binaryen.Unary.setValue(exp, value);
}

//Provides: caml_binaryen_binary_get_left
//Requires: Binaryen
function caml_binaryen_binary_get_left(exp) {
  return Binaryen.Binary.getLeft(exp);
}

//Provides: caml_binaryen_binary_set_left
//Requires: Binaryen
function caml_binaryen_binary_set_left(exp, value) {
  return Binaryen.Binary.setLeft(exp, value);
}

//Provides: caml_binaryen_binary_get_right
//Requires: Binaryen
function caml_binaryen_binary_get_right(exp) {
  return Binaryen.Binary.getRight(exp);
}

//Provides: caml_binaryen_binary_set_right
//Requires: Binaryen
function caml_binaryen_binary_set_right(exp, value) {
  return Binaryen.Binary.setRight(exp, value);
}

//Provides: caml_binaryen_select_get_if_true
//Requires: Binaryen
function caml_binaryen_select_get_if_true(exp) {
  return Binaryen.Select.getIfTrue(exp);
}

//Provides: caml_binaryen_select_set_if_true
//Requires: Binaryen
function caml_binaryen_select_set_if_true(exp, value) {
  return Binaryen.Select.setIfTrue(exp, value);
}

//Provides: caml_binaryen_select_get_if_false
//Requires: Binaryen
function caml_binaryen_select_get_if_false(exp) {
  return Binaryen.Select.getIfFalse(exp);
}

//Provides: caml_binaryen_select_set_if_false
//Requires: Binaryen
function caml_binaryen_select_set_if_false(exp, value) {
  return Binaryen.Select.setIfFalse(exp, value);
}

//Provides: caml_binaryen_select_get_condition
//Requires: Binaryen
function caml_binaryen_select_get_condition(exp) {
  return Binaryen.Select.getCondition(exp);
}

//Provides: caml_binaryen_select_set_condition
//Requires: Binaryen
function caml_binaryen_select_set_condition(exp, value) {
  return Binaryen.Select.setCondition(exp, value);
}

//Provides: caml_binaryen_drop_get_value
//Requires: Binaryen
function caml_binaryen_drop_get_value(exp) {
  return Binaryen.Drop.getValue(exp);
}

//Provides: caml_binaryen_drop_set_value
//Requires: Binaryen
function caml_binaryen_drop_set_value(exp, value) {
  return Binaryen.Drop.setValue(exp, value);
}

//Provides: caml_binaryen_return_get_value
//Requires: Binaryen
//Requires: to_option
function caml_binaryen_return_get_value(exp) {
  return to_option(Binaryen.Return.getValue(exp));
}

//Provides: caml_binaryen_return_set_value
//Requires: Binaryen
function caml_binaryen_return_set_value(exp, value) {
  return Binaryen.Return.setValue(exp, value);
}

//Provides: caml_binaryen_memory_init_get_segment
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_memory_init_get_segment(expr) {
  return caml_string_of_jsstring(Binaryen.MemoryInit.getSegment(expr));
}

//Provides: caml_binaryen_memory_init_set_segment
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_memory_init_set_segment(expr, segment) {
  return Binaryen.MemoryInit.setSegment(expr, caml_jsstring_of_string(segment));
}

//Provides: caml_binaryen_memory_init_get_dest
//Requires: Binaryen
function caml_binaryen_memory_init_get_dest(exp) {
  return Binaryen.MemoryInit.getDest(exp);
}

//Provides: caml_binaryen_memory_init_set_dest
//Requires: Binaryen
function caml_binaryen_memory_init_set_dest(exp, value) {
  return Binaryen.MemoryInit.setDest(exp, value);
}

//Provides: caml_binaryen_memory_init_get_offset
//Requires: Binaryen
function caml_binaryen_memory_init_get_offset(exp) {
  return Binaryen.MemoryInit.getOffset(exp);
}

//Provides: caml_binaryen_memory_init_set_offset
//Requires: Binaryen
function caml_binaryen_memory_init_set_offset(exp, value) {
  return Binaryen.MemoryInit.setOffset(exp, value);
}

//Provides: caml_binaryen_memory_init_get_size
//Requires: Binaryen
function caml_binaryen_memory_init_get_size(exp) {
  return Binaryen.MemoryInit.getSize(exp);
}

//Provides: caml_binaryen_memory_init_set_size
//Requires: Binaryen
function caml_binaryen_memory_init_set_size(exp, value) {
  return Binaryen.MemoryInit.setSize(exp, value);
}

//Provides: caml_binaryen_data_drop_get_segment
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_data_drop_get_segment(expr) {
  return caml_string_of_jsstring(Binaryen.DataDrop.getSegment(expr));
}

//Provides: caml_binaryen_data_drop_set_segment
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_data_drop_set_segment(expr, segment) {
  return Binaryen.DataDrop.setSegment(expr, caml_jsstring_of_string(segment));
}

//Provides: caml_binaryen_memory_copy_get_dest
//Requires: Binaryen
function caml_binaryen_memory_copy_get_dest(exp) {
  return Binaryen.MemoryCopy.getDest(exp);
}

//Provides: caml_binaryen_memory_copy_set_dest
//Requires: Binaryen
function caml_binaryen_memory_copy_set_dest(exp, value) {
  return Binaryen.MemoryCopy.setDest(exp, value);
}

//Provides: caml_binaryen_memory_copy_get_source
//Requires: Binaryen
function caml_binaryen_memory_copy_get_source(exp) {
  return Binaryen.MemoryCopy.getSource(exp);
}

//Provides: caml_binaryen_memory_copy_set_source
//Requires: Binaryen
function caml_binaryen_memory_copy_set_source(exp, value) {
  return Binaryen.MemoryCopy.setSource(exp, value);
}

//Provides: caml_binaryen_memory_copy_get_size
//Requires: Binaryen
function caml_binaryen_memory_copy_get_size(exp) {
  return Binaryen.MemoryCopy.getSize(exp);
}

//Provides: caml_binaryen_memory_copy_set_size
//Requires: Binaryen
function caml_binaryen_memory_copy_set_size(exp, value) {
  return Binaryen.MemoryCopy.setSize(exp, value);
}

//Provides: caml_binaryen_memory_fill_get_dest
//Requires: Binaryen
function caml_binaryen_memory_fill_get_dest(exp) {
  return Binaryen.MemoryFill.getDest(exp);
}

//Provides: caml_binaryen_memory_fill_set_dest
//Requires: Binaryen
function caml_binaryen_memory_fill_set_dest(exp, value) {
  return Binaryen.MemoryFill.setDest(exp, value);
}

//Provides: caml_binaryen_memory_fill_get_value
//Requires: Binaryen
function caml_binaryen_memory_fill_get_value(exp) {
  return Binaryen.MemoryFill.getValue(exp);
}

//Provides: caml_binaryen_memory_fill_set_value
//Requires: Binaryen
function caml_binaryen_memory_fill_set_value(exp, value) {
  return Binaryen.MemoryFill.setValue(exp, value);
}

//Provides: caml_binaryen_memory_fill_get_size
//Requires: Binaryen
function caml_binaryen_memory_fill_get_size(exp) {
  return Binaryen.MemoryFill.getSize(exp);
}

//Provides: caml_binaryen_memory_fill_set_size
//Requires: Binaryen
function caml_binaryen_memory_fill_set_size(exp, value) {
  return Binaryen.MemoryFill.setSize(exp, value);
}

//Provides: caml_binaryen_tuple_make_get_num_operands
//Requires: Binaryen
function caml_binaryen_tuple_make_get_num_operands(exp) {
  return Binaryen.TupleMake.getNumOperands(exp);
}

//Provides: caml_binaryen_tuple_make_get_operand_at
//Requires: Binaryen
function caml_binaryen_tuple_make_get_operand_at(exp, index) {
  return Binaryen.TupleMake.getOperandAt(exp, index);
}

//Provides: caml_binaryen_tuple_make_set_operand_at
//Requires: Binaryen
function caml_binaryen_tuple_make_set_operand_at(exp, index, operand) {
  return Binaryen.TupleMake.setOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_tuple_make_append_operand
//Requires: Binaryen
function caml_binaryen_tuple_make_append_operand(exp, operand) {
  return Binaryen.TupleMake.appendOperand(exp, operand);
}

//Provides: caml_binaryen_tuple_make_insert_operand_at
//Requires: Binaryen
function caml_binaryen_tuple_make_insert_operand_at(exp, index, operand) {
  return Binaryen.TupleMake.insertOperandAt(exp, index, operand);
}

//Provides: caml_binaryen_tuple_make_remove_operand_at
//Requires: Binaryen
function caml_binaryen_tuple_make_remove_operand_at(exp, index) {
  return Binaryen.TupleMake.removeOperandAt(exp, index);
}

//Provides: caml_binaryen_tuple_extract_get_tuple
//Requires: Binaryen
function caml_binaryen_tuple_extract_get_tuple(exp) {
  return Binaryen.TupleExtract.getTuple(exp);
}

//Provides: caml_binaryen_tuple_extract_set_tuple
//Requires: Binaryen
function caml_binaryen_tuple_extract_set_tuple(exp, value) {
  return Binaryen.TupleExtract.setTuple(exp, value);
}

// Ref operations

//Provides: caml_binaryen_ref_null
function caml_binaryen_ref_null(wasm_mod, typ) {
  return wasm_mod.ref.null(typ);
}

//Provides: caml_binaryen_ref_is_null
//Requires: Binaryen
function caml_binaryen_ref_is_null(wasm_mod, value) {
  return Binaryen.ExpressionIds.RefIsNull(wasm_mod, value);
}

//Provides: caml_binaryen_ref_as
//Requires: Binaryen
function caml_binaryen_ref_as(wasm_mod, op, value) {
  return Binaryen._BinaryenRefAs(wasm_mod, op, value);
}

//Provides: caml_binaryen_ref_func
//Requires: caml_jsstring_of_string
function caml_binaryen_ref_func(wasm_mod, name, typ) {
  return wasm_mod.ref.func(caml_jsstring_of_string(name), typ);
}

//Provides: caml_binaryen_ref_eq
function caml_binaryen_ref_eq(wasm_mod, left, right) {
  return wasm_mod.ref.func(left, right);
}

// Exception handling operations

//Provides: caml_binaryen_try_native
//Requires: caml_jsstring_of_string, caml_list_to_js_array
function caml_binaryen_try_native(wasm_mod, name, body, catch_tags, catch_bodies, delegate_target) {
  return wasm_mod.try(
    caml_jsstring_of_string(name),
    body,
    caml_list_to_js_array(catch_tags).map(caml_jsstring_of_string),
    caml_list_to_js_array(catch_bodies),
    delegate_target ? caml_jsstring_of_string(delegate_target[1]) : null,
  );
}

//Provides: caml_binaryen_try_bytecode
//Requires: caml_binaryen_try_native
function caml_binaryen_try_bytecode() {
  return caml_binaryen_try_native(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
}

//Provides: caml_binaryen_trycatch
//Requires: caml_jsstring_of_string, caml_list_to_js_array
function caml_binaryen_trycatch(wasm_mod, name, body, catch_tags, catch_bodies) {
  return wasm_mod.try(
    caml_jsstring_of_string(name),
    body,
    caml_list_to_js_array(catch_tags).map(caml_jsstring_of_string),
    caml_list_to_js_array(catch_bodies),
    null,
  );
}

//Provides: caml_binaryen_trydelegate
//Requires: caml_jsstring_of_string, caml_list_to_js_array
function caml_binaryen_trydelegate(wasm_mod, name, body, delegate_target) {
  return wasm_mod.try(
    caml_jsstring_of_string(name),
    body,
    [],
    [],
    delegate_target ? caml_jsstring_of_string(delegate_target[1]) : null,
  );
}

//Provides: caml_binaryen_throw
//Requires: caml_jsstring_of_string, caml_list_to_js_array
function caml_binaryen_throw(wasm_mod, tag, operands) {
  return wasm_mod.throw(
    caml_jsstring_of_string(tag),
    caml_list_to_js_array(operands),
  );
}

//Provides: caml_binaryen_rethrow
//Requires: caml_jsstring_of_string, caml_list_to_js_array
function caml_binaryen_rethrow(wasm_mod, target) {
  return wasm_mod.rethrow(
    caml_jsstring_of_string(target),
  )
}

// Table operations

//Provides: caml_binaryen_table_get
//Requires: caml_jsstring_of_string
function caml_binaryen_table_get(wasm_mod, name, index, typ) {
  return wasm_mod.table.get(caml_jsstring_of_string(name), index, typ);
}

//Provides: caml_binaryen_table_set
//Requires: caml_jsstring_of_string
function caml_binaryen_table_set(wasm_mod, name, index, value) {
  return wasm_mod.table.set(caml_jsstring_of_string(name), index, value);
}

//Provides: caml_binaryen_table_size
//Requires: caml_jsstring_of_string
function caml_binaryen_table_size(wasm_mod, name) {
  return wasm_mod.table.size(caml_jsstring_of_string(name));
}

//Provides: caml_binaryen_table_grow
//Requires: caml_jsstring_of_string
function caml_binaryen_table_grow(wasm_mod, name, value, delta) {
  return wasm_mod.table.grow(caml_jsstring_of_string(name), value, delta);
}

// TableGet operations

//Provides: caml_binaryen_tableget_get_table
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_tableget_get_table(exp) {
  return caml_string_of_jsstring(Binaryen.TableGet.getTable(exp));
}

//Provides: caml_binaryen_tableget_set_table
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_tableget_set_table(exp, table) {
  return Binaryen.TableGet.setTable(exp, caml_jsstring_of_string(table));
}

//Provides: caml_binaryen_tableget_get_index
//Requires: Binaryen
function caml_binaryen_tableget_get_index(exp) {
  return Binaryen.TableGet.getIndex(exp);
}

//Provides: caml_binaryen_tableget_set_index
//Requires: Binaryen
function caml_binaryen_tableget_set_index(exp, index) {
  return Binaryen.TableGet.setIndex(exp, index);
}

// TableSet operations

//Provides: caml_binaryen_tableset_get_table
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_tableset_get_table(exp) {
  return caml_string_of_jsstring(Binaryen.TableSet.getTable(exp));
}

//Provides: caml_binaryen_tableset_set_table
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_tableset_set_table(exp, table) {
  return Binaryen.TableSet.setTable(exp, caml_jsstring_of_string(table));
}

//Provides: caml_binaryen_tableset_get_index
//Requires: Binaryen
function caml_binaryen_tableset_get_index(exp) {
  return Binaryen.TableSet.getIndex(exp);
}

//Provides: caml_binaryen_tableset_set_index
//Requires: Binaryen
function caml_binaryen_tableset_set_index(exp, index) {
  return Binaryen.TableSet.setIndex(exp, index);
}

//Provides: caml_binaryen_tableset_get_value
//Requires: Binaryen
function caml_binaryen_tableset_get_value(exp) {
  return Binaryen.TableSet.getValue(exp);
}

//Provides: caml_binaryen_tableset_set_value
//Requires: Binaryen
function caml_binaryen_tableset_set_value(exp, value) {
  return Binaryen.TableSet.setValue(exp, value);
}

// TableSize operations

//Provides: caml_binaryen_tablesize_get_table
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_tablesize_get_table(exp) {
  return caml_string_of_jsstring(Binaryen.TableSize.getTable(exp));
}

//Provides: caml_binaryen_tablesize_set_table
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_tablesize_set_table(exp, table) {
  return Binaryen.TableSize.setTable(exp, caml_jsstring_of_string(table));
}

// TableGrow operations

//Provides: caml_binaryen_tablegrow_get_table
//Requires: Binaryen
//Requires: caml_string_of_jsstring
function caml_binaryen_tablegrow_get_table(exp) {
  return caml_string_of_jsstring(Binaryen.TableGrow.getTable(exp));
}

//Provides: caml_binaryen_tablegrow_set_table
//Requires: Binaryen
//Requires: caml_jsstring_of_string
function caml_binaryen_tablegrow_set_table(exp, table) {
  return Binaryen.TableGrow.setTable(exp, caml_jsstring_of_string(table));
}

//Provides: caml_binaryen_tablegrow_get_value
//Requires: Binaryen
function caml_binaryen_tablegrow_get_value(exp) {
  return Binaryen.TableGrow.getValue(exp);
}

//Provides: caml_binaryen_tablegrow_set_value
//Requires: Binaryen
function caml_binaryen_tablegrow_set_value(exp, value) {
  return Binaryen.TableGrow.setValue(exp, value);
}

//Provides: caml_binaryen_tablegrow_get_delta
//Requires: Binaryen
function caml_binaryen_tablegrow_get_delta(exp) {
  return Binaryen.TableGrow.getDelta(exp);
}

//Provides: caml_binaryen_tablegrow_set_delta
//Requires: Binaryen
function caml_binaryen_tablegrow_set_delta(exp, delta) {
  return Binaryen.TableGrow.setDelta(exp, delta);
}
