(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   LinearRegression.ml                                :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/10/28 20:28:23 by jpriou            #+#    #+#             *)
(*   Updated: 2018/10/29 09:13:34 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type entry = float * float
type data = string * string * entry list

let predict (t0:float) (t1:float) (x:float) =
  t0 +. (t1 *. x)
