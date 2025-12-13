open Binaryen;
open Frame_work;

suite("Memory", () => {
  test("set_memory", () => {
    let wasm_mod = Module.create();
    Memory.set_memory(wasm_mod, 1, 2, "memory", [], false, false, "memory");
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("Has Memory", () => {
    let wasm_mod = Module.create();
    assert(!Memory.has_memory(wasm_mod));
    Memory.set_memory(
      wasm_mod,
      1,
      2,
      "hasMemory1",
      [],
      false,
      false,
      "hasMemory1",
    );
    assert(Memory.has_memory(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("Get Initial", () => {
    let wasm_mod = Module.create();
    Memory.set_memory(
      wasm_mod,
      3,
      5,
      "getInitial1",
      [],
      false,
      false,
      "getInitial1",
    );
    assert(Memory.get_initial(wasm_mod, "getInitial1") == 3);
    Module.dispose(wasm_mod);
  });
  test("Has Max", () => {
    let wasm_mod = Module.create();
    Memory.set_memory(wasm_mod, 3, 5, "hasMax1", [], false, false, "hasMax1");
    assert(Memory.has_max(wasm_mod, "hasMax1"));
    Memory.set_memory(
      wasm_mod,
      3,
      Memory.unlimited,
      "hasMax2",
      [],
      false,
      false,
      "hasMax2",
    );
    assert(!Memory.has_max(wasm_mod, "hasMax2"));
    Module.dispose(wasm_mod);
  });
  test("Get Max", () => {
    let wasm_mod = Module.create();
    Memory.set_memory(wasm_mod, 3, 5, "getMax1", [], false, false, "getMax1");
    assert(Memory.get_max(wasm_mod, "getMax1") == 5);
    Module.dispose(wasm_mod);
  });
  test("Get Shared", () => {
    let wasm_mod = Module.create();
    Memory.set_memory(
      wasm_mod,
      3,
      5,
      "getShared1",
      [],
      true,
      false,
      "getShared1",
    );
    assert(Memory.is_shared(wasm_mod, "getShared1"));
    Memory.set_memory(
      wasm_mod,
      3,
      5,
      "getShared2",
      [],
      false,
      false,
      "getShared2",
    );
    assert(!Memory.is_shared(wasm_mod, "getShared2"));
    Module.dispose(wasm_mod);
  });
  test("Get Is64", () => {
    let wasm_mod = Module.create();
    Memory.set_memory(wasm_mod, 3, 5, "is64_1", [], false, true, "is64_1");
    assert(Memory.is_64(wasm_mod, "is64_1"));
    Memory.set_memory(wasm_mod, 3, 5, "is64_2", [], false, false, "is64_2");
    assert(!Memory.is_64(wasm_mod, "is64_2"));
    Module.dispose(wasm_mod);
  });
  // Segments
  let create_segment = (wasm_mod, name, kind): Memory.segment => {
    let data = Bytes.of_string(Printf.sprintf("data_%s", name));
    {
      name,
      data,
      kind,
      size: Bytes.length(data),
    };
  };
  test("Get Num Segments", () => {
    let wasm_mod = Module.create();
    Memory.set_memory(
      wasm_mod,
      1,
      2,
      "getNumSegs1",
      [],
      false,
      false,
      "getNumSegs1",
    );
    assert(Memory.get_num_segments(wasm_mod) == 0);
    Memory.set_memory(
      wasm_mod,
      1,
      2,
      "getNumSegs2",
      [
        create_segment(wasm_mod, "1", Memory.Passive),
        create_segment(wasm_mod, "2", Memory.Passive),
      ],
      false,
      false,
      "getNumSegs2",
    );
    assert(Memory.get_num_segments(wasm_mod) == 2);
    Module.dispose(wasm_mod);
  });
  test("Get Segment Offset", () => {
    let wasm_mod = Module.create();
    Memory.set_memory(
      wasm_mod,
      1,
      2,
      "getOffset1",
      [create_segment(wasm_mod, "1", Memory.Passive)],
      false,
      false,
      "getOffset1",
    );
    assert(Memory.get_segment_byte_offset(wasm_mod, "1") == (-1));
    Memory.set_memory(
      wasm_mod,
      1,
      2,
      "getOffset2",
      [
        create_segment(
          wasm_mod,
          "2",
          Memory.Active({
            offset: Expression.Const.make(wasm_mod, Literal.int32(4l)),
          }),
        ),
      ],
      false,
      false,
      "getOffset2",
    );
    assert(Memory.get_segment_byte_offset(wasm_mod, "2") == 4);
    Module.dispose(wasm_mod);
  });
  test("Get Segment Passive", () => {
    let wasm_mod = Module.create();
    Memory.set_memory(
      wasm_mod,
      1,
      2,
      "getPassive1",
      [create_segment(wasm_mod, "1", Memory.Passive)],
      false,
      false,
      "getPassive1",
    );
    assert(Memory.get_segment_passive(wasm_mod, "1"));
    Memory.set_memory(
      wasm_mod,
      1,
      2,
      "getPassive2",
      [
        create_segment(
          wasm_mod,
          "2",
          Memory.Active({
            offset: Expression.Const.make(wasm_mod, Literal.int32(4l)),
          }),
        ),
      ],
      false,
      false,
      "getPassive2",
    );
    assert(!Memory.get_segment_passive(wasm_mod, "2"));
    Module.dispose(wasm_mod);
  });
  test("Get Segment Data", () => {
    let wasm_mod = Module.create();
    Memory.set_memory(
      wasm_mod,
      1,
      2,
      "getData1",
      [create_segment(wasm_mod, "1", Memory.Passive)],
      false,
      false,
      "getData1",
    );
    let data = Memory.get_segment_data(wasm_mod, "1");
    assert(Bytes.to_string(data) == "data_1");
    Module.dispose(wasm_mod);
  });
});
