
open Base
open Graphics

(*
  Change la couleur du rectangle contenant le point coords
*)
let change_rectangle_color (coords, color) bsp =
  let construct_apply_condition bol f label bsp_g bsp_d =
    L (
      label,
      (if bol then f bsp_g else bsp_g),
      (if not bol then f bsp_d else bsp_d)
    )
  in
  let rec parcours line (x,y) bsp =
    match bsp with
    | R _ -> R color
    | L (label, bsp_g, bsp_d) ->
      construct_apply_condition
        ((if line then y else x) < label.coord)
        (parcours (not line) (x,y))
        label
        bsp_g
        bsp_d
  in parcours false coords bsp

(*
  On renvoie la couleur correspondant à la différence entre i et j :
  - i > j : blue
  - i < j : red
  - i = j : magenta
*)
let get_max_color i j =
  if i > j then Some blue
  else if i < j then Some red
  else Some magenta

(*
   Renvoie la couleur d'une ligne en fonction de :
   - ses bsp fils
   - ligne verticale (even = false) ou horizontale (even = true)
*)
let color_of_line bsp_g bsp_d even =
  let rec aux color bsp l =
    match bsp with
    | R c -> Option.may (fun c -> if c = blue then color.(0) <- color.(0) + 1 else color.(1) <- color.(1) + 1) c
    | L (_, bsp_g, bsp_d) ->
      if (even && l) then aux color bsp_g (not l)
      else if even = (not l) then (aux color bsp_g (not l); aux color bsp_d (not l))
      else aux color bsp_d (not l)
  in
  let tab = [|0;0|] in
  aux tab bsp_g (not even);
  aux tab bsp_d (not even);
  get_max_color (tab.(0)) (tab.(1))

let lines_from_bsp (config : config) (bsp:bsp) : (line * color option) list =
  let rec aux l even bsp max_dim min_dim =
    match bsp with
    | R _ -> l
    | L (label, bsp_g, bsp_d) ->
      begin
        let line_dim =
          if even then ((fst min_dim, label.coord), (fst max_dim, label.coord))
          else ((label.coord, snd min_dim), (label.coord, snd max_dim))
        and line_color = label.color
        in
        let line = (line_dim, line_color) in
        let dim_max_left = if even then (fst max_dim, label.coord) else (label.coord, snd max_dim) in
        let dim_min_right = if even then (fst min_dim, label.coord) else (label.coord, snd min_dim) in
        let l_left = aux (line :: l) (not even) bsp_g dim_max_left min_dim in
        aux l_left (not even) bsp_d max_dim dim_min_right
      end
  in aux [] false bsp config.dims (0,0)

let rectangles_from_bsp (config : config) (bsp : bsp) : (rect * color option) list =
  let rec aux res even bsp max_dim min_dim =
    match bsp with
    | R c -> ((min_dim, diff_dim min_dim max_dim), c) :: res
    | L (label, bsp_g, bsp_d) ->
      begin
        let dim_max_left = if even then (fst max_dim, label.coord) else (label.coord, snd max_dim) in
        let dim_min_right = if even then (fst min_dim, label.coord) else (label.coord, snd min_dim) in
        let l_left = aux res (not even) bsp_g dim_max_left min_dim in
        aux l_left (not even) bsp_d max_dim dim_min_right
      end
  in aux [] false bsp config.dims (0,0)
