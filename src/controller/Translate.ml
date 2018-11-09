
open Graphics
open Base

(**
  On renvoie la couleur correspondant à la différence entre i et j :
  - i > j : blue
  - i < j : red
  - i = j : magenta
*)
let get_max_color i j =
  if i > j then blue
  else if i < j then red
  else magenta

(**
  Renvoie la couleur d'une ligne en fonction de :
  - ses bsp fils
  - ligne verticale (line = false) ou horizontale (line = true)
*)
let color_of_line bsp_g bsp_d ligne =
  let rec aux color bsp l =
    match bsp with 
    | R c -> maybe (fun c -> if c = blue then color.(0) <- color.(0) + 1 else color.(1) <- color.(1) + 1) c ()
    | L (_, bsp_g, bsp_d) ->
      if(ligne && l) then aux color bsp_g (not l)
      else if ligne = (not l) then (aux color bsp_g (not l); aux color bsp_d (not l))
      else aux color bsp_d (not l)
  in let tab = [|0;0|]
  in aux tab bsp_g (not ligne); aux tab bsp_d (not ligne);
  Some (get_max_color (tab.(0)) (tab.(1)))

(**
  Fonction prenant une config et un bsp en entrée, et renvoie la liste des lignes avec leurs couleurs
*)
let lines_from_bsp (config : config) (bsp:bsp) : (line * color option) list =
  let rec aux l ligne bsp max_dim min_dim =
    match bsp with
    | R _ -> l
    | L (label, bsp_g, bsp_d) ->
      (
        (if ligne then ((fst min_dim, label.coord), (fst max_dim, label.coord)) else ((label.coord, snd min_dim), (label.coord, snd max_dim))),
        (color_of_line bsp_g bsp_d ligne)
      ) 
      :: 
      (aux
        (aux 
          l 
          (not ligne) 
          bsp_g 
          (if ligne then (fst max_dim, label.coord) else (label.coord, snd max_dim))
          min_dim
        )
        (not ligne)
        bsp_d
        max_dim
        (if ligne then (fst min_dim, label.coord) else (label.coord, snd min_dim))
      )
  in aux [] false bsp config.dims (0,0)

(**
  Fonction prenant une config et un bsp en entrée, et renvoie la liste des rectangles avec leurs couleurs
*)
let rectangles_from_bsp (config : config) (bsp : bsp) : (rect * color option) list =
  let rec aux l ligne bsp max_dim min_dim =
    match bsp with
    | R c -> ((min_dim, max_dim), c) :: l
    | L (label, bsp_g, bsp_d) ->
        aux
          (aux 
            l 
            (not ligne) 
            bsp_g 
            (if ligne then (fst max_dim, label.coord) else (label.coord, snd max_dim))
            min_dim
          )
          (not ligne)
          bsp_d
          max_dim
          (if ligne then (fst min_dim, label.coord) else (label.coord, snd min_dim)
        )
  in aux [] false bsp config.dims (0,0)
