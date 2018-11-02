(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   LinearRegression.ml                                :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2018/10/28 20:28:23 by jpriou            #+#    #+#             *)
(*   Updated: 2018/11/01 19:05:09 by jpriou           ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type entry = float * float
type data = string * string * entry list

let learningRate = 0.1
let precision = 1e-5

let predict (t0:float) (t1:float) (x:float) =
  (* t0 +. (t1 *. x) *)
  let res = t0 +. (t1 *. x) in
  Printf.printf "debug on %f : %f\n" x res;
  res

let rec train (t0:float) (t1:float) (data:data) =
  let (_, _, li) = data in
  let m = List.length li in
  Printf.printf "initials t0 %f t1 %f\n" t0 t1;
  (* let rec loop li tmp0 tmp1 = match li with
    | []          -> (tmp0, tmp1)
    | (x,y) :: xs ->
      begin
        Printf.printf "x: %f\ny: %f\n" x y;
        let tmp = (predict t0 t1 x) -. y in
        Printf.printf "tmp : %f\n" tmp;
	      Printf.printf "New values :\ntmp0: %f\ntmp1: %f\n" tmp0 tmp1;
        loop xs (tmp0 +. tmp) (tmp1 +. (tmp *. x))
      end
     in *)
  let sumlist li f = List.fold_left
      (fun a i -> Printf.printf "Debug %f\n" a; a +. (f i))
      0.0
      li
  in
  let tmp0 = sumlist li
      (fun (x, y) -> let p = predict t0 t1 x in (p -. y))
  in
  let tmp1 = sumlist li
      (fun (x, y) -> let p = predict t0 t1 x in (p -. y) *. x)
  in
  Printf.printf "before %f %f\n" tmp0 tmp1;
  (* let (tmp0, tmp1) = loop li 0. 0. in *)
  let tmp0 = learningRate *. (1.0 /. (float_of_int m)) *. tmp0 in
  let tmp1 = learningRate *. (1.0 /. (float_of_int m)) *. tmp1 in
  Printf.printf "values %f %f\n" tmp0 tmp1;
  (* let _ = read_line () in *)
  if (abs_float tmp0) +. (abs_float tmp1) >= precision
  then train (t0 -. tmp0) (t1 -. tmp1) data
  else (t0, t1)
