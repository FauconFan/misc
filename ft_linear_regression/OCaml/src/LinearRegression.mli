(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   LinearRegression.mli                               :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/10/28 20:34:11 by jpriou            #+#    #+#             *)
(*   Updated: 2018/11/01 17:18:41 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type entry = float * float
type data = string * string * entry list

val predict : float -> float -> float -> float
val train : float -> float -> data -> (float * float)
