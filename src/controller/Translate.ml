
open Graphics
open Base

(**
  Fonction prenant une config et un bsp en entrée, et renvoie la liste des lignes avec leurs couleurs
*)
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

(**
  Fonction prenant une config et un bsp en entrée, et renvoie la liste des rectangles avec leurs couleurs
*)
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
