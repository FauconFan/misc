(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/07/23 14:22:27 by jpriou            #+#    #+#             *)
(*   Updated: 2018/07/23 14:34:58 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	let p = new People.people "Robert" in
	let q = new People.people "Garp" in

	print_newline ();

	p#talk;
	print_endline p#to_string;
	p#die;
	print_endline p#to_string;

	print_newline ();

	q#talk;
	print_endline q#to_string;
	q#die;
	print_endline q#to_string
