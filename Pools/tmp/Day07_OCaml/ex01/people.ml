(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   people.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/07/23 14:21:04 by jpriou            #+#    #+#             *)
(*   Updated: 2018/07/23 15:07:05 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class people (name:string) =
	object (self)
		val name = name
		val mutable hp = 100

		initializer print_endline ("A people named " ^ name ^ " is just created")

		method to_string = ("name: " ^ name ^ ", hp: " ^ (string_of_int hp))
		method talk = print_endline ("I’m " ^ name ^ "! Do you know the Doctor?")
		method die = hp <- 0; print_endline "Aaaarghh!"
	end
