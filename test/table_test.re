open Binaryen;
open Frame_work;

suite("Table", () => {
  let create_test_func = (wasm_mod, name) => {
    let _ =
      Function.add_function(
        wasm_mod,
        name,
        Type.none,
        Type.none,
        [||],
        Expression.Nop.make(wasm_mod),
      );
    ();
  };
  test("Add Table", () => {
    let wasm_mod = Module.create();
    let _ = Table.add_table(wasm_mod, "addTableTest", 10, 20, Type.funcref);
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("Add Active Element Segment", () => {
    let wasm_mod = Module.create();
    let name = "addActiveElementSegment";
    let _ = Table.add_table(wasm_mod, name, 6, 9, Type.funcref);
    create_test_func(wasm_mod, "func1");
    create_test_func(wasm_mod, "func2");
    create_test_func(wasm_mod, "func3");
    let _ =
      Table.add_active_element_segment(
        wasm_mod,
        name,
        "ActiveSegmentTest",
        ["func1", "func2", "func3"],
        Expression.Const.make(wasm_mod, Literal.int32(3l)),
      );
    Printf.printf("%s", Module.write_text(wasm_mod));
    Module.dispose(wasm_mod);
  });
  test("Get Num Element Segments", () => {
    let wasm_mod = Module.create();
    let name = "GetNumElementSegments";
    let _ = Table.add_table(wasm_mod, name, 0, 10, Type.funcref);
    create_test_func(wasm_mod, "func1");
    assert(Table.get_num_element_segments(wasm_mod) == 0);
    let _ =
      Table.add_active_element_segment(
        wasm_mod,
        name,
        "GetNumSegs1",
        ["func1"],
        Expression.Const.make(wasm_mod, Literal.int32(0l)),
      );
    assert(Table.get_num_element_segments(wasm_mod) == 1);
    Module.dispose(wasm_mod);
  });
  test("Remove Element Segment", () => {
    let wasm_mod = Module.create();
    let name = "RemoveElementSegment";
    let _ = Table.add_table(wasm_mod, name, 0, 10, Type.funcref);
    create_test_func(wasm_mod, "func1");
    let _ =
      Table.add_active_element_segment(
        wasm_mod,
        name,
        "RemoveSeg1",
        ["func1"],
        Expression.Const.make(wasm_mod, Literal.int32(0l)),
      );
    assert(Table.get_num_element_segments(wasm_mod) == 1);
    Table.remove_element_segment(wasm_mod, "RemoveSeg1");
    assert(Table.get_num_element_segments(wasm_mod) == 0);
    Module.dispose(wasm_mod);
  });
  test("Get Element Segment", () => {
    let wasm_mod = Module.create();
    let name = "GetElementSegmentByName";
    let _ = Table.add_table(wasm_mod, name, 0, 10, Type.funcref);
    create_test_func(wasm_mod, "func1");
    let segmentName = "GetSegByName";
    let _ =
      Table.add_active_element_segment(
        wasm_mod,
        name,
        segmentName,
        ["func1"],
        Expression.Const.make(wasm_mod, Literal.int32(0l)),
      );
    let segment = Table.get_element_segment(wasm_mod, segmentName);
    assert(Element_segment.get_name(segment) == segmentName);
    Module.dispose(wasm_mod);
  });
  test("Get Element Segment By Index", () => {
    let wasm_mod = Module.create();
    let name = "GetElementSegmentByIndex";
    let _ = Table.add_table(wasm_mod, name, 0, 10, Type.funcref);
    create_test_func(wasm_mod, "func1");
    let segmentName = "GetSegByIndex";
    let _ =
      Table.add_active_element_segment(
        wasm_mod,
        name,
        segmentName,
        ["func1"],
        Expression.Const.make(wasm_mod, Literal.int32(0l)),
      );
    let segment = Table.get_element_segment_by_index(wasm_mod, 0);
    assert(Element_segment.get_name(segment) == segmentName);
    Module.dispose(wasm_mod);
  });
});
