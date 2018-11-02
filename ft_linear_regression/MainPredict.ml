(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   MainPredict.ml                                     :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/10/29 08:36:34 by jpriou            #+#    #+#             *)
(*   Updated: 2018/11/01 17:04:36 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let args = ref []

let savepath str = args := str :: (!args)

let usage = "\nLinearRegression Predict Program\n"

let () =
  Arg.parse [] savepath usage;
  if List.length !args > 1 then print_endline "Wrong number of argument"
  else
    begin
      let (t0, t1) = IO.getSavedData () in
      let i = IO.askNumber () in
      let out = LinearRegression.predict t0 t1 i in
      Printf.printf "%f\n" out
    end
