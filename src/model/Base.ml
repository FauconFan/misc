(* Fichier ml contenant les types et fonctions de base utilisés dans tout le projet *)

open Graphics

type dim = int * int (* width, height *)
type coords = int * int (* x, y *)
type rect = coords * dim (* left corner coords, and the dimension *)
type line = coords * coords (* coords of the two points of the segments *)

(*
  * Config report used to get user information
  *)
type config =
  {
    dims : dim; (* dimension de la fenêtre graphique. Permet de construire l'arbre en fonction *)
    depth : int; (* profondeur de l'arbre *)
  }

  (** type for string information, it is composed of :
    - left down corner coordinate
    - dimension of the area of string
    - color of the string
    - font of the string
    - size of the string
    - content of the string
  *)
  type string_content = 
    {
      coordinate : coords;
      color : color;
      font : string;
      size : int;
      content : string list;
    }
  

(* Types given by the subject *)

type label =
  {
    coord : int; (* taille de la ligne. L'interprétation dépend de la position dans le bsp *)
    color : color option; (* couleur de la ligen si elle existe, noir sinon *)
  }

type bsp =
  | R of color option (* Couleur d'un rectangle *)
  | L of label * bsp * bsp (* composé d'un label correspondant à la ligne et de 2 arbres bsp en fils *)

(*
   Fonction prenant deux dimensions en arguments (x,y) et (width, height) et renvoyant si la dimension
   coordonnée se situe entre (0,0) et (width, height).
*)
let bounds ((x,y) : dim) ((width, height) : dim) : bool =
  x >= 0
  && y >= 0
  && x < width
  && y < height

(*
  Fonction renvoyant un tuple contenant la distance entre les x et les y des deux (int * int) donnés en arguments
 *)
let diff_dim (x1, y1) (x2, y2) = (abs (x1 - x2), abs (y1 - y2))

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
