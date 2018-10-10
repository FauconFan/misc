(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/07/23 14:22:27 by jpriou            #+#    #+#             *)
(*   Updated: 2018/07/23 15:25:17 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	let p = new People.people "Robert" in
	let q = new People.people "Garp" in
	let d = new Doctor.doctor "Paster" 64 p in

	print_newline ();

	p#talk;
	print_endline p#to_string;
	p#die;
	print_endline p#to_string;

	print_newline ();

	q#talk;
	print_endline q#to_string;
	q#die;
	print_endline q#to_string;

	print_newline ();
	print_endline (d#to_string);
	d#travel_in_time 1964 2018;
	d#use_sonic_screwdriver
