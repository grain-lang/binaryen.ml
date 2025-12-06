let suite = (name, suiteFn) => {
  Printf.printf("Running suite: %s\n", name);
  suiteFn();
};
let test = (name, fn) => {
  Printf.printf(". Running test: %s\n", name);
  fn();
};
