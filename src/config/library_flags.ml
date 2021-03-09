module C = Configurator.V1

let () =
  C.main ~name:"library_flags" (fun c ->
      let default = [] in

      let library_flags =
        match C.ocaml_config_var c "system" with
        | Some "macosx" ->
            (* These flags preserve the original C error behavior *)
            [ "-cclib"; "-Wl,-keep_dwarf_unwind" ]
        | Some _ -> default
        | None -> default
      in

      C.Flags.write_sexp "library_flags.sexp" library_flags)
