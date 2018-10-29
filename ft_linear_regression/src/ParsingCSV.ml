(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ParsingCSV.ml                                      :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/10/28 20:26:50 by jpriou            #+#    #+#             *)
(*   Updated: 2018/10/28 21:01:25 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let run (filepath:string) : LinearRegression.data =
  let data = ref [] in
  let c0 = ref "" in
  let c1 = ref "" in

  begin
    try
      let ic = open_in filepath in
      try
        let line = input_line ic in
        let sp = String.split_on_char ',' line in
        match sp with
        | [s; p] -> c0 := s; c1 := p
        | _ -> ignore @@ failwith ("Could not have more than 2 columns.")
      with
      | End_of_file -> close_in ic; ignore @@ failwith ("Empty file");
      try
        let running = ref true in
        while !running do
          let line = input_line ic in
          let sp = String.split_on_char ',' line in
          match sp with
          | [s; p] ->
            begin
              let (f0, f1) = (float_of_string_opt s, float_of_string_opt p) in
              match (f0, f1) with
              | (Some b0, Some b1) -> data := (b0, b1) :: !data
              | _ -> failwith "No numbers"
            end
          | _ -> failwith ("Could not have more than 2 columns.")
        done;
      with
      | End_of_file -> close_in ic;

    with
    | Sys_error str -> failwith ("Sys error : " ^ str)
  end;
  (!c0, !c1, !data)
