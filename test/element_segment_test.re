open Binaryen;
open Frame_work;

suite("Element Segment", () => {
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
  let create_segment = (wasm_mod, table_name, segment_name) => {
    let _ = Table.add_table(wasm_mod, table_name, 10, 20, Type.funcref);
    let _ = create_test_func(wasm_mod, "testFunc1");
    let _ = create_test_func(wasm_mod, "testFunc2");
    Table.add_active_element_segment(
      wasm_mod,
      table_name,
      segment_name,
      [ "testFunc1", "testFunc2" ],
      Expression.Const.make(wasm_mod, Literal.int32(0l)),
    );
  };
  test("GetName", () => {
    let wasm_mod = Module.create();
    let table_name = "testTable";
    let segment_name = "testSegment";
    let segment = create_segment(wasm_mod, table_name, segment_name);
    assert (Element_segment.get_name(segment) == segment_name);
    Module.dispose(wasm_mod);
  });
  test("GetTable", () => {
    let wasm_mod = Module.create();
    let table_name = "testTable";
    let segment_name = "testSegment";
    let segment = create_segment(wasm_mod, table_name, segment_name);
    assert (Element_segment.get_table(segment) == table_name);
    Module.dispose(wasm_mod);
  });
  test("GetOffset", () => {
    let wasm_mod = Module.create();
    let table_name = "testTable";
    let segment_name = "testSegment";
    let segment = create_segment(wasm_mod, table_name, segment_name);
    let offset_expr = Element_segment.get_offset(segment);
    assert (Expression.get_kind(offset_expr) == Expression.Const);
    Module.dispose(wasm_mod);
  });
  test("GetLength", () => {
    let wasm_mod = Module.create();
    let table_name = "testTable";
    let segment_name = "testSegment";
    let segment = create_segment(wasm_mod, table_name, segment_name);
    assert (Element_segment.get_length(segment) == 2);
    Module.dispose(wasm_mod);
  });
  test("GetData", () => {
    let wasm_mod = Module.create();
    let table_name = "testTable";
    let segment_name = "testSegment";
    let segment = create_segment(wasm_mod, table_name, segment_name);
    assert (Element_segment.get_data(segment, 0) == "testFunc1");
    assert (Element_segment.get_data(segment, 1) == "testFunc2");
    Module.dispose(wasm_mod);
  });
});
