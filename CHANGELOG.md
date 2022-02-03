# Changelog

### [0.12.1](https://github.com/grain-lang/binaryen.ml/compare/v0.12.0...v0.12.1) (2022-02-03)


### Features

* **ci:** Upgrade release-please ([#131](https://github.com/grain-lang/binaryen.ml/issues/131)) ([ca3bdb7](https://github.com/grain-lang/binaryen.ml/commit/ca3bdb7aa324a013205a80759bcc733fea64ae4a))


### Bug Fixes

* Restrict js_of_ocaml to version 3 ([fa39480](https://github.com/grain-lang/binaryen.ml/commit/fa39480fc74b19cf7052ec5c0764ee58b5783549))


### Miscellaneous Chores

* Fix release version ([5d1bd42](https://github.com/grain-lang/binaryen.ml/commit/5d1bd42a7132298a902060c46dae72507e702eb0))

## [0.12.0](https://www.github.com/grain-lang/binaryen.ml/compare/v0.11.2...v0.12.0) (2022-01-26)


### ⚠ BREAKING CHANGES

* Add table type to add_table signature
* Rename Event to Tag to match Binaryen

### Features

* Add table type to add_table signature ([5c50272](https://www.github.com/grain-lang/binaryen.ml/commit/5c502720943a8bf6e649891051db00336eec9451))
* Add update_maps function that Binaryen added ([5c50272](https://www.github.com/grain-lang/binaryen.ml/commit/5c502720943a8bf6e649891051db00336eec9451))
* Rename Event to Tag to match Binaryen ([5c50272](https://www.github.com/grain-lang/binaryen.ml/commit/5c502720943a8bf6e649891051db00336eec9451))
* Upgrade to libbinaryen v102 ([#120](https://www.github.com/grain-lang/binaryen.ml/issues/120)) ([5c50272](https://www.github.com/grain-lang/binaryen.ml/commit/5c502720943a8bf6e649891051db00336eec9451))

### [0.11.2](https://www.github.com/grain-lang/binaryen.ml/compare/v0.11.1...v0.11.2) (2022-01-24)


### Bug Fixes

* Handle JS global in non-node environments ([#125](https://www.github.com/grain-lang/binaryen.ml/issues/125)) ([74e94fe](https://www.github.com/grain-lang/binaryen.ml/commit/74e94fe8ac7b2c2a66b8118b5eaa3a81e5f9296a))

### [0.11.1](https://www.github.com/grain-lang/binaryen.ml/compare/v0.11.0...v0.11.1) (2022-01-16)


### Bug Fixes

* Make features work in 32-bit mode ([#123](https://www.github.com/grain-lang/binaryen.ml/issues/123)) ([e435c8b](https://www.github.com/grain-lang/binaryen.ml/commit/e435c8bd9f6619c42b82e53e5d1caa929b5d4ebf))

## [0.11.0](https://www.github.com/grain-lang/binaryen.ml/compare/v0.10.0...v0.11.0) (2022-01-13)


### ⚠ BREAKING CHANGES

* Mention implicit python dependency in the docs
* Switch to libbinaryen dependency (#113)
* Remove MacOS-specific library flags (#111)
* Require OCaml 4.12 (#108)

### Features

* Depend on libbinaryen ([59874ce](https://www.github.com/grain-lang/binaryen.ml/commit/59874ce785288d4a33ed5408ac4a0a33e16ff4c1))
* Remove MacOS-specific library flags ([#111](https://www.github.com/grain-lang/binaryen.ml/issues/111)) ([5a67f9f](https://www.github.com/grain-lang/binaryen.ml/commit/5a67f9f330332f8957976841819707d09124dc94))
* Require OCaml 4.12 ([#108](https://www.github.com/grain-lang/binaryen.ml/issues/108)) ([36eedea](https://www.github.com/grain-lang/binaryen.ml/commit/36eedea279fb19ee6131b72b21c24ba0a9d7f993))
* Switch to libbinaryen dependency ([#113](https://www.github.com/grain-lang/binaryen.ml/issues/113)) ([59874ce](https://www.github.com/grain-lang/binaryen.ml/commit/59874ce785288d4a33ed5408ac4a0a33e16ff4c1))


### Miscellaneous Chores

* Mention implicit python dependency in the docs ([59874ce](https://www.github.com/grain-lang/binaryen.ml/commit/59874ce785288d4a33ed5408ac4a0a33e16ff4c1))

## [0.10.0](https://www.github.com/grain-lang/binaryen.ml/compare/v0.9.1...v0.10.0) (2021-05-09)


### ⚠ BREAKING CHANGES

* Move expressions into namespaces
* Move element segment into own module
* Move `Features` into `Module.Feature`
* Create Settings modules & move global functions
* Convert some Settings from ints to bools
* Remove SIMD methods that Binaryen replaced
* Upgrade Binaryen to v101 (#99)

### Features

* Add `Module.get_features` ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Add `Type.expandType` ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Add operations on element segments ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Add operations on exports ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Add operations on expressions ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Add operations on functions ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Add operations on globals ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Add operations on imports ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Add support for reference types ([#101](https://www.github.com/grain-lang/binaryen.ml/issues/101)) ([5058492](https://www.github.com/grain-lang/binaryen.ml/commit/50584929466b7aae5f7c9b48b8b9bab5676ed53e))
* Build vendored Binaryen with GCC 7 instead of 9 ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Convert some Settings from ints to bools ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Create Settings modules & move global functions ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Move `Features` into `Module.Feature` ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Move element segment into own module ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Move expressions into namespaces ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))
* Upgrade Binaryen to v101 ([#99](https://www.github.com/grain-lang/binaryen.ml/issues/99)) ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))


### Miscellaneous Chores

* Remove SIMD methods that Binaryen replaced ([3de1b28](https://www.github.com/grain-lang/binaryen.ml/commit/3de1b289ed4673f701801f3087e48ac9746d89d1))

### [0.9.1](https://www.github.com/grain-lang/binaryen.ml/compare/v0.9.0...v0.9.1) (2021-04-02)


### Bug Fixes

* Correct JS conversion of i64 & float64_bits literals ([#96](https://www.github.com/grain-lang/binaryen.ml/issues/96)) ([00b7093](https://www.github.com/grain-lang/binaryen.ml/commit/00b7093ad57c7698ff7f6e69f59fd426ee341fbf))

## [0.9.0](https://www.github.com/grain-lang/binaryen.ml/compare/v0.8.1...v0.9.0) (2021-03-17)


### Features

* add Function_table.unlimited constant ([#87](https://www.github.com/grain-lang/binaryen.ml/issues/87)) ([0d2fcde](https://www.github.com/grain-lang/binaryen.ml/commit/0d2fcde007b77e6edd5c66975fd7a611ae9a8ef8))
* write bindings for add_table ([6dc0fa8](https://www.github.com/grain-lang/binaryen.ml/commit/6dc0fa83d5873630cf7a0a6f2895600c68ad4f30))


### Bug Fixes

* **js:** cast the call_indirect string arguments to JS strings ([7b4136a](https://www.github.com/grain-lang/binaryen.ml/commit/7b4136a2e2fdae3efd85351dc40aad2ad4c3ed3e))
* **js:** utilize JSOO externals to convert between uint8array & bytes ([#85](https://www.github.com/grain-lang/binaryen.ml/issues/85)) ([61d28c5](https://www.github.com/grain-lang/binaryen.ml/commit/61d28c5e7e6ca6217759a75e2c96e7cb5c1b3d45))
* return JS null value from Expression.null ([#83](https://www.github.com/grain-lang/binaryen.ml/issues/83)) ([61861e2](https://www.github.com/grain-lang/binaryen.ml/commit/61861e2590816bccc5c6c17a2a5b77f3a3db3779))


### Miscellaneous Chores

* fix formatter & format the code ([#80](https://www.github.com/grain-lang/binaryen.ml/issues/80)) ([b9c485a](https://www.github.com/grain-lang/binaryen.ml/commit/b9c485a69cfb6ffbcc8a7a7611c2ea09386486e2))
* set dune language to the version of dune we use ([e9eb5c9](https://www.github.com/grain-lang/binaryen.ml/commit/e9eb5c927dbee84f9ab783a2bfb7f2e16c94e7f6))
* use test file directly in one rule so ocaml-lsp works ([34b7a13](https://www.github.com/grain-lang/binaryen.ml/commit/34b7a13864f81d5d2b8781f1b172d72f28354209))


### Documentation

* cleanup Binaryen submodule & building language (closes [#65](https://www.github.com/grain-lang/binaryen.ml/issues/65)) ([3bdb23d](https://www.github.com/grain-lang/binaryen.ml/commit/3bdb23dbca2734d58ee0802b796593016ac80c6e))

### [0.8.1](https://www.github.com/grain-lang/binaryen.ml/compare/v0.8.0...v0.8.1) (2021-03-09)


### Bug Fixes

* Module.optimize on macOS ([#77](https://www.github.com/grain-lang/binaryen.ml/issues/77)) ([0b92043](https://www.github.com/grain-lang/binaryen.ml/commit/0b920431372119d92b0077f51b91ca745fbfde87))


### Continuous Integration

* write opam CHANGES from environment var ([#78](https://www.github.com/grain-lang/binaryen.ml/issues/78)) ([4f25e0e](https://www.github.com/grain-lang/binaryen.ml/commit/4f25e0e96c3b1d2ad22d3b037695960cd6b2722a))

## [0.8.0](https://www.github.com/grain-lang/binaryen.ml/compare/v0.7.0...v0.8.0) (2021-03-05)


### ⚠ BREAKING CHANGES

* Table name must now be provided to the `Expression.call_indirect` and `Expression.return_call_indirect` instructions.

### Features

* Upgrade to Binaryen 100 ([#75](https://www.github.com/grain-lang/binaryen.ml/issues/75)) ([d59f5f9](https://www.github.com/grain-lang/binaryen.ml/commit/d59f5f9fb5356f4ccd7f4a7fefe15d5d4b721412))


### Continuous Integration

* fix markdown escaping for opam release ([#72](https://www.github.com/grain-lang/binaryen.ml/issues/72)) ([a2e6052](https://www.github.com/grain-lang/binaryen.ml/commit/a2e605241376ffdfcbba7ecd2e7a7ac52b53019f))


### Miscellaneous Chores

* fix dune misdocumentation ([#73](https://www.github.com/grain-lang/binaryen.ml/issues/73)) ([341e718](https://www.github.com/grain-lang/binaryen.ml/commit/341e71805078dae312171d5985dec7ebc689bdbe))

## [0.7.0](https://www.github.com/grain-lang/binaryen.ml/compare/v0.6.0...v0.7.0) (2021-02-24)


### ⚠ BREAKING CHANGES

* memory_size and memory_grow are now toplevel functions in `Expression`.
* removed `Type.nullref`, `Type.exnref`
* removed `Op.any_true_vec_i64x2` and `Op.all_true_vec_i64x2`
* Bump to Binaryen 98

### Features

* Bump to Binaryen 98 ([9a52a07](https://www.github.com/grain-lang/binaryen.ml/commit/9a52a077051441f8b0999bad1d77a8d3a6357460))


### Continuous Integration

* add opam & npm releases to workflow ([#69](https://www.github.com/grain-lang/binaryen.ml/issues/69)) ([d339608](https://www.github.com/grain-lang/binaryen.ml/commit/d3396085565e478b31a5819628be08bae1e2be16))
* run opam build on ubuntu 18 instead of 20 ([#67](https://www.github.com/grain-lang/binaryen.ml/issues/67)) ([7ee2009](https://www.github.com/grain-lang/binaryen.ml/commit/7ee20092da341f927acf552abcbcf8bfcca90c0b))


### Miscellaneous Chores

* memory_size and memory_grow are now toplevel functions in `Expression`. ([9a52a07](https://www.github.com/grain-lang/binaryen.ml/commit/9a52a077051441f8b0999bad1d77a8d3a6357460))
* removed `Op.any_true_vec_i64x2` and `Op.all_true_vec_i64x2` ([9a52a07](https://www.github.com/grain-lang/binaryen.ml/commit/9a52a077051441f8b0999bad1d77a8d3a6357460))
* removed `Type.nullref`, `Type.exnref` ([9a52a07](https://www.github.com/grain-lang/binaryen.ml/commit/9a52a077051441f8b0999bad1d77a8d3a6357460))

## [0.6.0](https://www.github.com/grain-lang/binaryen.ml/compare/v0.5.0...v0.6.0) (2021-01-24)


### Features

* Allow signed narrow-width loads ([#62](https://www.github.com/grain-lang/binaryen.ml/issues/62)) ([6448aeb](https://www.github.com/grain-lang/binaryen.ml/commit/6448aeb4ae00a07c98b0386fc1a82f6b653ac2c0))

## [0.5.0](https://www.github.com/grain-lang/binaryen.ml/compare/v0.4.0...v0.5.0) (2021-01-12)


### Features

* Allow optional return_type parameter when creating blocks ([ab737bd](https://www.github.com/grain-lang/binaryen.ml/commit/ab737bd4940a4534a84d1dcff2d0a42cd49cdd38))


### Bug Fixes

* add arch & os restrictions for opam ([#41](https://www.github.com/grain-lang/binaryen.ml/issues/41)) ([421b45d](https://www.github.com/grain-lang/binaryen.ml/commit/421b45d152bf8c5e15ba55e60357ab6c2d7a25f4))
* provide type to select instruction ([#46](https://www.github.com/grain-lang/binaryen.ml/issues/46)) ([2096a3c](https://www.github.com/grain-lang/binaryen.ml/commit/2096a3c2a219212519be3498c831d2e9d234a0ee))


### Documentation

* add section about static linking ([#37](https://www.github.com/grain-lang/binaryen.ml/issues/37)) ([f9afda1](https://www.github.com/grain-lang/binaryen.ml/commit/f9afda1bf80fbf06173cc1d6767164d4d93e12a5))


### Miscellaneous Chores

* Add --no-browser flag to opam-publish ([#43](https://www.github.com/grain-lang/binaryen.ml/issues/43)) ([f47f2bb](https://www.github.com/grain-lang/binaryen.ml/commit/f47f2bb1ed2016ab9f82e25e67dcc727958581c2))
* Switch back to official setup-opam action ([#44](https://www.github.com/grain-lang/binaryen.ml/issues/44)) ([f4338bd](https://www.github.com/grain-lang/binaryen.ml/commit/f4338bd110bf5c116a8a99f9b868a83a3da82d11))


### Continuous Integration

* Add release workflow ([#21](https://www.github.com/grain-lang/binaryen.ml/issues/21)) ([bd9d210](https://www.github.com/grain-lang/binaryen.ml/commit/bd9d210f26e7dc42ba452ee6283696d538e5bbc1))
* Add release-please-action to release process ([#55](https://www.github.com/grain-lang/binaryen.ml/issues/55)) ([5909560](https://www.github.com/grain-lang/binaryen.ml/commit/590956017550fb884c22c2681b924856a82c87b0))
