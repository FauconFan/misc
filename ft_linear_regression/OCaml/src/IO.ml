(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   IO.ml                                              :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/11/01 16:39:32 by jpriou            #+#    #+#             *)
(*   Updated: 2018/11/01 17:19:46 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let path_save = "data.csv"

let rec askNumber () : float =
  print_endline "Please enter your number :";
  match float_of_string_opt (input_line stdin) with
  | None -> print_endline "Please enter a valid number..."; askNumber ()
  | Some b -> b

let getSavedData () : (float * float) =
  let t0 = ref 0.0 in
  let t1 = ref 0.0 in

  begin
    try
      let ic = open_in path_save in
      let _ = input_line ic in
      let line = input_line ic in
      let sp = String.split_on_char ',' line in
      match sp with
      | [s0; s1] ->
        begin
          match (float_of_string_opt s0, float_of_string_opt s1) with
          | (Some b0, Some b1) -> t0 := b0; t1 := b1
          | _ -> print_endline "Invalid data"
        end
      | _ -> print_endline "Invalid data";
      close_in ic
    with
    | Sys_error _ -> ()
  end;
  (!t0, !t1)

let setSavedData (t0:float) (t1:float) : unit =
  begin
    try
      let oc = open_out path_save in
      Printf.fprintf oc "t0,t1\n%f,%f\n" t0 t1;
      close_out oc;
      Printf.printf "New values :\nt0: %f\nt1: %f\n" t0 t1;
    with
    | _ -> failwith "Unknown"
  end
