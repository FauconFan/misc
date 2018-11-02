(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   IO.mli                                             :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/11/01 16:39:38 by jpriou            #+#    #+#             *)
(*   Updated: 2018/11/01 16:55:45 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

val askNumber : unit -> float

val getSavedData : unit -> (float * float)
val setSavedData : float -> float -> unit
