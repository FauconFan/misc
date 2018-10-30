(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   MainPredict.ml                                     :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/10/29 08:36:34 by jpriou            #+#    #+#             *)
(*   Updated: 2018/10/30 08:24:09 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let filepath = ref ""
let show = ref false

let speclist = [
  ("-f", Arg.Set_string filepath, "CSV Data");
  ("-s", Arg.Set show, "Show the data")
]

let usage = "\nLinearRegression Predict Program\n"

let () =
  Arg.parse speclist print_endline usage;
  Printf.printf "Parsing file : \"%s\"\n" !filepath;
  let data =
    begin
      try
        ParsingCSV.run !filepath
      with
      | Failure str -> print_endline (str); exit 1
      | _ -> print_endline "Unknown error"; exit 1
    end
  in
  if !show then ParsingCSV.display data;
  let (t0, t1) = (0.0, 0.0) in
  let in = askNumber () in




let rec askNumber () : float =
  print_endline "Please enter your number :";
  match float_of_string_opt (input_line stdin) with
  | None -> print_endline "Please enter a valid number..."; askNumber ()
  | Some b -> b
