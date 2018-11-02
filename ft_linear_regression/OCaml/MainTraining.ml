(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   MainTraining.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/10/29 08:36:34 by jpriou            #+#    #+#             *)
(*   Updated: 2018/11/01 17:19:15 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let args = ref []
let show = ref false

let speclist = [
  ("-s", Arg.Set show, "Show the data")
]

let savepath str = args := str :: (!args)

let usage = "\nLinearRegression Training Program\n"
let () =
  Arg.parse speclist savepath usage;
  if List.length !args != 1 then print_endline "Wrong number of argument"
  else
    begin
      let filepath = List.hd !args in
      Printf.printf "Parsing file : \"%s\"\n" filepath;
      let data =
        begin
          try
            ParsingCSV.run filepath
          with
          | Failure str -> print_endline (str); exit 1
          | _ -> print_endline "Unknown error"; exit 1
        end
      in
      if !show then ParsingCSV.display data;
      let (t0, t1) = IO.getSavedData () in
      let (t0, t1) = LinearRegression.train t0 t1 data in
      IO.setSavedData t0 t1;
    end
