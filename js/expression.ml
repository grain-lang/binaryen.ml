open Js_of_ocaml.Js
open Js_of_ocaml.Js.Unsafe

type t = int

type kind =
  | Invalid
  | Nop
  | Block
  | If
  | Loop
  | Break
  | Switch
  | Call
  | CallIndirect
  | LocalGet
  | LocalSet
  | GlobalGet
  | GlobalSet
  | Load
  | Store
  | AtomicRMW
  | AtomicCmpxchg
  | AtomicWait
  | AtomicNotify
  | AtomicFence
  | SIMDExtract
  | SIMDReplace
  | SIMDShuffle
  | SIMDTernary
  | SIMDShift
  | SIMDLoad
  | SIMDLoadStoreLane
  | MemoryInit
  | DataDrop
  | MemoryCopy
  | MemoryFill
  | Const
  | Unary
  | Binary
  | Select
  | Drop
  | Return
  | MemorySize
  | MemoryGrow
  | Unreachable
  | Pop
  | RefNull
  | RefIs
  | RefFunc
  | RefEq
  | Try
  | Throw
  | Rethrow
  | TupleMake
  | TupleExtract
  | I31New
  | I31Get
  | CallRef
  | RefTest
  | RefCast
  | BrOn
  | RttCanon
  | RttSub
  | StructNew
  | StructGet
  | StructSet
  | ArrayNew
  | ArrayGet
  | ArraySet
  | ArrayLen
  | RefAs

let expression_to_option x = if x = 0 then None else Some x

let get_kind expr =
  match meth_call global##.binaryen "getExpressionId" [| inject expr |] with
  | n when n = global ##. binaryen ##. InvalidId -> Invalid
  | n when n = global ##. binaryen ##. NopId -> Nop
  | n when n = global ##. binaryen ##. BlockId -> Block
  | n when n = global ##. binaryen ##. IfId -> If
  | n when n = global ##. binaryen ##. LoopId -> Loop
  | n when n = global ##. binaryen ##. BreakId -> Break
  | n when n = global ##. binaryen ##. SwitchId -> Switch
  | n when n = global ##. binaryen ##. CallId -> Call
  | n when n = global ##. binaryen ##. CallIndirectId -> CallIndirect
  | n when n = global ##. binaryen ##. LocalGetId -> LocalGet
  | n when n = global ##. binaryen ##. LocalSetId -> LocalSet
  | n when n = global ##. binaryen ##. GlobalGetId -> GlobalGet
  | n when n = global ##. binaryen ##. GlobalSetId -> GlobalSet
  | n when n = global ##. binaryen ##. LoadId -> Load
  | n when n = global ##. binaryen ##. StoreId -> Store
  | n when n = global ##. binaryen ##. AtomicRMWId -> AtomicRMW
  | n when n = global ##. binaryen ##. AtomicCmpxchgId -> AtomicCmpxchg
  | n when n = global ##. binaryen ##. AtomicWaitId -> AtomicWait
  | n when n = global ##. binaryen ##. AtomicNotifyId -> AtomicNotify
  | n when n = global ##. binaryen ##. AtomicFenceId -> AtomicFence
  | n when n = global ##. binaryen ##. SIMDExtractId -> SIMDExtract
  | n when n = global ##. binaryen ##. SIMDReplaceId -> SIMDReplace
  | n when n = global ##. binaryen ##. SIMDShuffleId -> SIMDShuffle
  | n when n = global ##. binaryen ##. SIMDTernaryId -> SIMDTernary
  | n when n = global ##. binaryen ##. SIMDShiftId -> SIMDShift
  | n when n = global ##. binaryen ##. SIMDLoadId -> SIMDLoad
  | n when n = global ##. binaryen ##. SIMDLoadStoreLaneId -> SIMDLoadStoreLane
  | n when n = global ##. binaryen ##. MemoryInitId -> MemoryInit
  | n when n = global ##. binaryen ##. DataDropId -> DataDrop
  | n when n = global ##. binaryen ##. MemoryCopyId -> MemoryCopy
  | n when n = global ##. binaryen ##. MemoryFillId -> MemoryFill
  | n when n = global ##. binaryen ##. ConstId -> Const
  | n when n = global ##. binaryen ##. UnaryId -> Unary
  | n when n = global ##. binaryen ##. BinaryId -> Binary
  | n when n = global ##. binaryen ##. SelectId -> Select
  | n when n = global ##. binaryen ##. DropId -> Drop
  | n when n = global ##. binaryen ##. ReturnId -> Return
  | n when n = global ##. binaryen ##. MemorySizeId -> MemorySize
  | n when n = global ##. binaryen ##. MemoryGrowId -> MemoryGrow
  | n when n = global ##. binaryen ##. UnreachableId -> Unreachable
  | n when n = global ##. binaryen ##. PopId -> Pop
  | n when n = global ##. binaryen ##. RefNullId -> RefNull
  | n when n = global ##. binaryen ##. RefIsId -> RefIs
  | n when n = global ##. binaryen ##. RefFuncId -> RefFunc
  | n when n = global ##. binaryen ##. RefEqId -> RefEq
  | n when n = global ##. binaryen ##. TryId -> Try
  | n when n = global ##. binaryen ##. ThrowId -> Throw
  | n when n = global ##. binaryen ##. RethrowId -> Rethrow
  | n when n = global ##. binaryen ##. TupleMakeId -> TupleMake
  | n when n = global ##. binaryen ##. TupleExtractId -> TupleExtract
  | n when n = global ##. binaryen ##. I31NewId -> I31New
  | n when n = global ##. binaryen ##. I31GetId -> I31Get
  | n when n = global ##. binaryen ##. CallRefId -> CallRef
  | n when n = global ##. binaryen ##. RefTestId -> RefTest
  | n when n = global ##. binaryen ##. RefCastId -> RefCast
  | n when n = global ##. binaryen ##. BrOnId -> BrOn
  | n when n = global ##. binaryen ##. RttCanonId -> RttCanon
  | n when n = global ##. binaryen ##. RttSubId -> RttSub
  | n when n = global ##. binaryen ##. StructNewId -> StructNew
  | n when n = global ##. binaryen ##. StructGetId -> StructGet
  | n when n = global ##. binaryen ##. StructSetId -> StructSet
  | n when n = global ##. binaryen ##. ArrayNewId -> ArrayNew
  | n when n = global ##. binaryen ##. ArrayGetId -> ArrayGet
  | n when n = global ##. binaryen ##. ArraySetId -> ArraySet
  | n when n = global ##. binaryen ##. ArrayLenId -> ArrayLen
  | n when n = global ##. binaryen ##. RefAsId -> RefAs
  | _ -> failwith "unknown expression kind"

let print expr =
  let text = meth_call global##.binaryen "emitText" [| inject expr |] in
  print_string (to_string text)

let finalize exp =
  meth_call global ##. binaryen ##. Expression "finalize" [| inject exp |]

let copy exp wasm_mod = meth_call wasm_mod "copyExpression" [| inject exp |]

module Block = struct
  let make ?(return_type = Type.auto) wasm_mod name children =
    meth_call wasm_mod "block"
      [|
        inject (string name);
        inject (array (Array.of_list children));
        inject return_type;
      |]

  let get_name exp =
    Option.map to_string
      (Opt.to_option
         (meth_call global ##. binaryen ##. Block "getName" [| inject exp |]))

  let set_name exp name =
    meth_call
      global ##. binaryen ##. Block
      "setName"
      [| inject exp; inject (string name) |]

  let get_num_children exp =
    meth_call global ##. binaryen ##. Block "getNumChildren" [| inject exp |]

  let get_child_at exp index =
    meth_call
      global ##. binaryen ##. Block
      "getChildAt"
      [| inject exp; inject index |]

  let set_child_at exp index child =
    meth_call
      global ##. binaryen ##. Block
      "setChildAt"
      [| inject exp; inject index; inject child |]

  let append_child exp child =
    meth_call
      global ##. binaryen ##. Block
      "appendChild"
      [| inject exp; inject child |]

  let insert_child_at exp index child =
    meth_call
      global ##. binaryen ##. Block
      "insertChildAt"
      [| inject exp; inject index; inject child |]

  let remove_child_at exp index =
    meth_call
      global ##. binaryen ##. Block
      "removeChildAt"
      [| inject exp; inject index |]
end

module If = struct
  let make wasm_mod cond if_true if_false =
    meth_call wasm_mod "if" [| inject cond; inject if_true; inject if_false |]

  let get_condition exp =
    meth_call global ##. binaryen ##. If "getCondition" [| inject exp |]

  let set_condition exp cond =
    meth_call
      global ##. binaryen ##. If
      "setCondition"
      [| inject exp; inject cond |]

  let get_if_true exp =
    meth_call global ##. binaryen ##. If "getIfTrue" [| inject exp |]

  let set_if_true exp child =
    meth_call
      global ##. binaryen ##. If
      "setIfTrue"
      [| inject exp; inject child |]

  let get_if_false exp =
    expression_to_option
      (meth_call global ##. binaryen ##. If "getIfFalse" [| inject exp |])

  let set_if_false exp child =
    meth_call
      global ##. binaryen ##. If
      "setIfFalse"
      [| inject exp; inject child |]
end

module Loop = struct
  let make wasm_mod name body =
    meth_call wasm_mod "loop" [| inject (string name); inject body |]

  let get_name exp =
    to_string
      (meth_call global ##. binaryen ##. Loop "getName" [| inject exp |])

  let set_name exp name =
    meth_call
      global ##. binaryen ##. Loop
      "setName"
      [| inject exp; inject (string name) |]

  let get_body exp =
    meth_call global ##. binaryen ##. Loop "getBody" [| inject exp |]

  let set_body exp child =
    meth_call
      global ##. binaryen ##. Loop
      "setBody"
      [| inject exp; inject child |]
end

module Break = struct
  let make wasm_mod name cond res =
    meth_call wasm_mod "br" [| inject (string name); inject cond; inject res |]

  let get_name exp =
    to_string
      (meth_call global ##. binaryen ##. Break "getName" [| inject exp |])

  let set_name exp name =
    meth_call
      global ##. binaryen ##. Break
      "setName"
      [| inject exp; inject (string name) |]

  let get_condition exp =
    expression_to_option
      (meth_call global ##. binaryen ##. Break "getCondition" [| inject exp |])

  let set_condition exp child =
    meth_call
      global ##. binaryen ##. Break
      "setCondition"
      [| inject exp; inject child |]

  let get_value exp =
    expression_to_option
      (meth_call global ##. binaryen ##. Break "getValue" [| inject exp |])

  let set_value exp child =
    meth_call
      global ##. binaryen ##. Break
      "setValue"
      [| inject exp; inject child |]
end

module Switch = struct
  let make wasm_mod names default_name cond value =
    meth_call wasm_mod "switch"
      [|
        inject (array (Array.of_list (List.map string names)));
        inject (string default_name);
        inject cond;
        inject value;
      |]

  let get_num_names exp =
    meth_call global ##. binaryen ##. Switch "getNumNames" [| inject exp |]

  let get_name_at exp index =
    to_string
      (meth_call
         global ##. binaryen ##. Switch
         "getNameAt"
         [| inject exp; inject index |])

  let set_name_at exp index name =
    meth_call
      global ##. binaryen ##. Switch
      "setNameAt"
      [| inject exp; inject index; inject (string name) |]

  let append_name exp name =
    meth_call
      global ##. binaryen ##. Switch
      "appendName"
      [| inject exp; inject (string name) |]

  let insert_name_at exp index name =
    meth_call
      global ##. binaryen ##. Switch
      "insertNameAt"
      [| inject exp; inject index; inject (string name) |]

  let remove_name_at exp index =
    to_string
      (meth_call
         global ##. binaryen ##. Switch
         "removeNameAt"
         [| inject exp; inject index |])

  let get_default_name exp =
    Option.map to_string
      (Opt.to_option
         (meth_call
            global ##. binaryen ##. Switch
            "getDefaultName"
            [| inject exp |]))

  let set_default_name exp name =
    meth_call
      global ##. binaryen ##. Switch
      "setDefaultName"
      [| inject exp; inject (string name) |]

  let get_condition exp =
    meth_call global ##. binaryen ##. Switch "getCondition" [| inject exp |]

  let set_condition exp child =
    meth_call
      global ##. binaryen ##. Switch
      "setCondition"
      [| inject exp; inject child |]

  let get_value exp =
    expression_to_option
      (meth_call global ##. binaryen ##. Switch "getValue" [| inject exp |])

  let set_value exp child =
    meth_call
      global ##. binaryen ##. Switch
      "setValue"
      [| inject exp; inject child |]
end

module Call = struct
  let make wasm_mod name params return_typ =
    meth_call wasm_mod "call"
      [|
        inject (string name);
        inject (array (Array.of_list params));
        inject return_typ;
      |]

  let make_return wasm_mod name params return_typ =
    meth_call wasm_mod "return_call"
      [|
        inject (string name);
        inject (array (Array.of_list params));
        inject return_typ;
      |]

  let get_target exp =
    to_string
      (meth_call global ##. binaryen ##. Call "getTarget" [| inject exp |])

  let set_target exp name =
    meth_call
      global ##. binaryen ##. Call
      "setTarget"
      [| inject exp; inject (string name) |]

  let get_num_operands exp =
    meth_call global ##. binaryen ##. Call "getNumOperands" [| inject exp |]

  let get_operand_at exp index =
    meth_call
      global ##. binaryen ##. Call
      "getOperandAt"
      [| inject exp; inject index |]

  let set_operand_at exp index operand =
    meth_call
      global ##. binaryen ##. Call
      "setOperandAt"
      [| inject exp; inject index; inject operand |]

  let append_operand exp operand =
    meth_call
      global ##. binaryen ##. Call
      "appendOperand"
      [| inject exp; inject operand |]

  let insert_operand_at exp index operand =
    meth_call
      global ##. binaryen ##. Call
      "insertOperandAt"
      [| inject exp; inject index; inject operand |]

  let remove_operand_at exp index =
    meth_call
      global ##. binaryen ##. Call
      "removeOperandAt"
      [| inject exp; inject index |]

  let is_return exp =
    to_bool (meth_call global ##. binaryen ##. Call "isReturn" [| inject exp |])

  let set_return exp isReturn =
    meth_call
      global ##. binaryen ##. Call
      "setReturn"
      [| inject exp; inject (bool isReturn) |]
end

module Call_indirect = struct
  let make wasm_mod table target params params_typ return_typ =
    meth_call wasm_mod "call_indirect"
      [|
        inject (string table);
        inject target;
        inject (array (Array.of_list params));
        inject params_typ;
        inject return_typ;
      |]

  let make_return wasm_mod table target params params_typ return_typ =
    meth_call wasm_mod "return_call_indirect"
      [|
        inject (string table);
        inject target;
        inject (array (Array.of_list params));
        inject params_typ;
        inject return_typ;
      |]

  let get_target exp =
    meth_call global ##. binaryen ##. CallIndirect "getTarget" [| inject exp |]

  let set_target exp target =
    meth_call
      global ##. binaryen ##. CallIndirect
      "setTarget"
      [| inject exp; inject target |]

  let get_table exp =
    to_string
      (meth_call
         global ##. binaryen ##. CallIndirect
         "getTable"
         [| inject exp |])

  let set_table exp name =
    meth_call
      global ##. binaryen ##. CallIndirect
      "setTable"
      [| inject exp; inject (string name) |]

  let get_num_operands exp =
    meth_call
      global ##. binaryen ##. CallIndirect
      "getNumOperands"
      [| inject exp |]

  let get_operand_at exp index =
    meth_call
      global ##. binaryen ##. CallIndirect
      "getOperandAt"
      [| inject exp; inject index |]

  let set_operand_at exp index operand =
    meth_call
      global ##. binaryen ##. CallIndirect
      "setOperandAt"
      [| inject exp; inject index; inject operand |]

  let append_operand exp operand =
    meth_call
      global ##. binaryen ##. CallIndirect
      "appendOperand"
      [| inject exp; inject operand |]

  let insert_operand_at exp index operand =
    meth_call
      global ##. binaryen ##. CallIndirect
      "insertOperandAt"
      [| inject exp; inject index; inject operand |]

  let remove_operand_at exp index =
    meth_call
      global ##. binaryen ##. CallIndirect
      "removeOperandAt"
      [| inject exp; inject index |]

  let is_return exp =
    to_bool
      (meth_call
         global ##. binaryen ##. CallIndirect
         "isReturn"
         [| inject exp |])

  let set_return exp isReturn =
    meth_call
      global ##. binaryen ##. CallIndirect
      "setReturn"
      [| inject exp; inject (bool isReturn) |]
end

module Local_get = struct
  let make wasm_mod slot typ =
    let scope = get wasm_mod "local" in
    meth_call scope "get" [| inject slot; inject typ |]
end

module Local_set = struct
  let make wasm_mod slot value =
    let scope = get wasm_mod "local" in
    meth_call scope "set" [| inject slot; inject value |]

  let get_value exp =
    meth_call global ##. binaryen ##. LocalSet "getValue" [| inject exp |]

  let set_value exp value =
    meth_call
      global ##. binaryen ##. LocalSet
      "setValue"
      [| inject exp; inject value |]
end

module Local_tee = struct
  let make wasm_mod slot value typ =
    let scope = get wasm_mod "local" in
    meth_call scope "tee" [| inject slot; inject value; inject typ |]
end

module Global_get = struct
  let make wasm_mod name typ =
    let scope = get wasm_mod "global" in
    meth_call scope "get" [| inject (string name); inject typ |]

  let get_name exp =
    to_string
      (meth_call global ##. binaryen ##. GlobalGet "getName" [| inject exp |])

  let set_name exp name =
    meth_call
      global ##. binaryen ##. GlobalGet
      "setName"
      [| inject exp; inject (string name) |]
end

module Global_set = struct
  let make wasm_mod name value =
    let scope = get wasm_mod "global" in
    meth_call scope "set" [| inject (string name); inject value |]

  let get_name exp =
    to_string
      (meth_call global ##. binaryen ##. GlobalSet "getName" [| inject exp |])

  let set_name exp name =
    meth_call
      global ##. binaryen ##. GlobalSet
      "setName"
      [| inject exp; inject (string name) |]

  let get_value exp =
    meth_call global ##. binaryen ##. GlobalSet "getValue" [| inject exp |]

  let set_value exp value =
    meth_call
      global ##. binaryen ##. GlobalSet
      "setValue"
      [| inject exp; inject value |]
end

module Load = struct
  let make wasm_mod byts ?(signed = false) offset align typ ptr =
    meth_call global##.binaryen "_BinaryenLoad"
      [|
        inject wasm_mod;
        inject byts;
        inject signed;
        inject offset;
        inject align;
        inject typ;
        inject ptr;
      |]

  let get_ptr exp =
    meth_call global ##. binaryen ##. Load "getPtr" [| inject exp |]

  let set_ptr exp ptr =
    meth_call global ##. binaryen ##. Load "setPtr" [| inject exp; inject ptr |]
end

module Store = struct
  let make wasm_mod byts offset align ptr value typ =
    meth_call global##.binaryen "_BinaryenStore"
      [|
        inject wasm_mod;
        inject byts;
        inject offset;
        inject align;
        inject ptr;
        inject value;
        inject typ;
      |]

  let get_ptr exp =
    meth_call global ##. binaryen ##. Store "getPtr" [| inject exp |]

  let set_ptr exp ptr =
    meth_call
      global ##. binaryen ##. Store
      "setPtr"
      [| inject exp; inject ptr |]

  let get_value exp =
    meth_call global ##. binaryen ##. Store "getValue" [| inject exp |]

  let set_value exp value =
    meth_call
      global ##. binaryen ##. Store
      "setValue"
      [| inject exp; inject value |]
end

module Const = struct
  let make wasm_mod lit =
    let lit_hack = Literal.to_jsoo lit in
    match lit_hack with
    | Int32 value ->
        let scope = get wasm_mod "i32" in
        meth_call scope "const" [| inject value |]
    | Int64 (low, high) ->
        let scope = get wasm_mod "i64" in
        meth_call scope "const" [| inject low; inject high |]
    | Float32Bits value ->
        let scope = get wasm_mod "f32" in
        meth_call scope "const_bits" [| inject value |]
    | Float64Bits (low, high) ->
        let scope = get wasm_mod "f64" in
        meth_call scope "const_bits" [| inject low; inject high |]
    | Float32 value ->
        let scope = get wasm_mod "f32" in
        meth_call scope "const" [| inject value |]
    | Float64 value ->
        let scope = get wasm_mod "f64" in
        meth_call scope "const" [| inject value |]
end

module Unary = struct
  let make wasm_mod op p =
    meth_call global##.binaryen "_BinaryenUnary"
      [| inject wasm_mod; inject op; inject p |]

  let get_value exp =
    meth_call global ##. binaryen ##. Unary "getValue" [| inject exp |]

  let set_value exp value =
    meth_call
      global ##. binaryen ##. Unary
      "setValue"
      [| inject exp; inject value |]
end

module Binary = struct
  let make wasm_mod op a b =
    meth_call global##.binaryen "_BinaryenBinary"
      [| inject wasm_mod; inject op; inject a; inject b |]

  let get_left exp =
    meth_call global ##. binaryen ##. Binary "getLeft" [| inject exp |]

  let set_left exp value =
    meth_call
      global ##. binaryen ##. Binary
      "setLeft"
      [| inject exp; inject value |]

  let get_right exp =
    meth_call global ##. binaryen ##. Binary "getRight" [| inject exp |]

  let set_right exp value =
    meth_call
      global ##. binaryen ##. Binary
      "setRight"
      [| inject exp; inject value |]
end

module Select = struct
  let make wasm_mod cond if_true if_false =
    meth_call wasm_mod "select"
      [| inject cond; inject if_true; inject if_false; inject Type.auto |]

  let get_if_true exp =
    meth_call global ##. binaryen ##. Select "getIfTrue" [| inject exp |]

  let set_if_true exp value =
    meth_call
      global ##. binaryen ##. Select
      "setIfTrue"
      [| inject exp; inject value |]

  let get_if_false exp =
    meth_call global ##. binaryen ##. Select "getIfFalse" [| inject exp |]

  let set_if_false exp value =
    meth_call
      global ##. binaryen ##. Select
      "setIfFalse"
      [| inject exp; inject value |]

  let get_condition exp =
    meth_call global ##. binaryen ##. Select "getCondition" [| inject exp |]

  let set_condition exp value =
    meth_call
      global ##. binaryen ##. Select
      "setCondition"
      [| inject exp; inject value |]
end

module Drop = struct
  let make wasm_mod value = meth_call wasm_mod "drop" [| inject value |]

  let get_value exp =
    meth_call global ##. binaryen ##. Drop "getValue" [| inject exp |]

  let set_value exp value =
    meth_call
      global ##. binaryen ##. Drop
      "setValue"
      [| inject exp; inject value |]
end

module Return = struct
  let make wasm_mod value = meth_call wasm_mod "return" [| inject value |]

  let get_value exp =
    meth_call global ##. binaryen ##. Return "getValue" [| inject exp |]

  let set_value exp value =
    meth_call
      global ##. binaryen ##. Return
      "setValue"
      [| inject exp; inject value |]
end

module Memory_size = struct
  let make wasm_mod =
    let scope = get wasm_mod "memory" in
    meth_call scope "size" [||]
end

module Memory_grow = struct
  let make wasm_mod value =
    let scope = get wasm_mod "memory" in
    meth_call scope "grow" [| inject value |]

  let get_delta exp =
    meth_call global ##. binaryen ##. MemoryGrow "getDelta" [| inject exp |]

  let set_delta exp delta =
    meth_call
      global ##. binaryen ##. MemoryGrow
      "setDelta"
      [| inject exp; inject delta |]
end

module Memory_copy = struct
  let make wasm_mod dest source size =
    let scope = get wasm_mod "memory" in
    meth_call scope "copy" [| inject dest; inject source; inject size |]

  let get_dest exp =
    meth_call global ##. binaryen ##. MemoryCopy "getDest" [| inject exp |]

  let set_dest exp value =
    meth_call
      global ##. binaryen ##. MemoryCopy
      "setDest"
      [| inject exp; inject value |]

  let get_source exp =
    meth_call global ##. binaryen ##. MemoryCopy "getSource" [| inject exp |]

  let set_source exp value =
    meth_call
      global ##. binaryen ##. MemoryCopy
      "setSource"
      [| inject exp; inject value |]

  let get_size exp =
    meth_call global ##. binaryen ##. MemoryCopy "getSize" [| inject exp |]

  let set_size exp value =
    meth_call
      global ##. binaryen ##. MemoryCopy
      "setSize"
      [| inject exp; inject value |]
end

module Memory_fill = struct
  let make wasm_mod dest value size =
    let scope = get wasm_mod "memory" in
    meth_call scope "fill" [| inject dest; inject value; inject size |]

  let get_dest exp =
    meth_call global ##. binaryen ##. MemoryFill "getDest" [| inject exp |]

  let set_dest exp value =
    meth_call
      global ##. binaryen ##. MemoryFill
      "setDest"
      [| inject exp; inject value |]

  let get_value exp =
    meth_call global ##. binaryen ##. MemoryFill "getValue" [| inject exp |]

  let set_value exp value =
    meth_call
      global ##. binaryen ##. MemoryFill
      "setValue"
      [| inject exp; inject value |]

  let get_size exp =
    meth_call global ##. binaryen ##. MemoryFill "getSize" [| inject exp |]

  let set_size exp value =
    meth_call
      global ##. binaryen ##. MemoryFill
      "setSize"
      [| inject exp; inject value |]
end

module Tuple_make = struct
  let make wasm_mod operands =
    let scope = get wasm_mod "tuple" in
    meth_call scope "make" [| inject (array (Array.of_list operands)) |]

  let get_num_operands exp =
    meth_call
      global ##. binaryen ##. TupleMake
      "getNumOperands"
      [| inject exp |]

  let get_operand_at exp index =
    meth_call
      global ##. binaryen ##. TupleMake
      "getOperandAt"
      [| inject exp; inject index |]

  let set_operand_at exp index operand =
    meth_call
      global ##. binaryen ##. TupleMake
      "setOperandAt"
      [| inject exp; inject index; inject operand |]

  let append_operand exp operand =
    meth_call
      global ##. binaryen ##. TupleMake
      "appendOperand"
      [| inject exp; inject operand |]

  let insert_operand_at exp index operand =
    meth_call
      global ##. binaryen ##. TupleMake
      "insertOperandAt"
      [| inject exp; inject index; inject operand |]

  let remove_operand_at exp index =
    meth_call
      global ##. binaryen ##. TupleMake
      "removeOperandAt"
      [| inject exp; inject index |]
end

module Tuple_extract = struct
  let make wasm_mod tuple index =
    let scope = get wasm_mod "tuple" in
    meth_call scope "extract" [| inject tuple; inject index |]

  let get_tuple exp =
    meth_call global ##. binaryen ##. TupleExtract "getTuple" [| inject exp |]

  let set_tuple exp value =
    meth_call
      global ##. binaryen ##. TupleExtract
      "setTuple"
      [| inject exp; inject value |]
end

module Nop = struct
  let make wasm_mod = meth_call wasm_mod "nop" [||]
end

module Unreachable = struct
  let make wasm_mod = meth_call wasm_mod "unreachable" [||]
end

module Pop = struct
  let make wasm_mod typ =
    meth_call global##.binaryen "_BinaryenPop" [| inject wasm_mod; inject typ |]
end

module Null = struct
  let make () = pure_js_expr "null"
end
