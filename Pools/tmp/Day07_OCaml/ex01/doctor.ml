(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   doctor.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/07/23 15:01:27 by jpriou            #+#    #+#             *)
(*   Updated: 2018/07/23 15:24:56 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class doctor (name:string) (age:int) (sidekick:People.people) =
	object (self)
		val name = name
		val age = age
		val sidekick = sidekick
		val mutable hp = 100

		initializer print_endline ("A doctor named " ^ name ^ " is just created")

		method to_string =
			("name: " ^ name
				^ ", age: " ^ (string_of_int age)
				^ ", sidekick: {" ^ (sidekick#to_string) ^ "}"
				^ ", hp: " ^ (string_of_int hp))

		method talk =
			print_endline "Hi! I'm the Doctor !"

		method travel_in_time start arrival =
			let tardis = "              ___\n      _______(_@_)_______\n      | POLICE      BOX |\n      |_________________|\n       | _____ | _____ |\n       | |###| | |###| |\n       | |###| | |###| |\n       | _____ | _____ |\n       | || || | || || |\n       | ||_|| | ||_|| |\n       | _____ |$_____ |\n       | || || | || || |\n       | ||_|| | ||_|| |\n       | _____ | _____ |\n       | || || | || || |\n       | ||_|| | ||_|| |\n       |       |       |\n       *****************" in
			let year = abs (arrival - start) in
			let msg = if start < arrival then "future" else "past" in

			print_endline tardis;
			print_endline ("Travelling " ^ (string_of_int year) ^ " years to the " ^ msg ^ ".");
			print_endline ("Doctor's age doesn't change. He just travelled...")

		method use_sonic_screwdriver =
			print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"

		method private regenerate = hp <- 100

	end
