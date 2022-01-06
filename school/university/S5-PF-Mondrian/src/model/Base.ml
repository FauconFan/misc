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
    size : int;
    center : bool;
    content : string list;
  }


(* Types given by the subject *)

type label =
  {
    coord : int; (* taille de la ligne. L'interprétation dépend de la position dans le bsp *)
    color : color option; (* couleur de la ligne si elle existe, None sinon *)
  }

type bsp =
  | R of color option (* Couleur d'un rectangle *)
  | L of label * bsp * bsp (* composé d'un label correspondant à la ligne et de 2 arbres bsp en fils *)

(*
  The default font used in the all program.
*)
let (font_format : (int -> string, unit, string) format) = "-*-fixed-medium-r-semicondensed--%d-*-*-*-*-*-iso8859-1"

(*
  construct_font return a fresh string based on size
*)
let construct_font size =
  Printf.sprintf font_format size

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
  Fonction constructeur de string_content
*)
let construct_string_content
    ?color:(color = black)
    ?center:(center = false)
    coord size content =
  {
    coordinate = coord;
    color = color;
    size = size;
    center = center;
    content = content;
  }

type uevent =
  | Click of coords * color option
  | Motion of coords * color option

let getUEventData u = match u with
  | Click (co, c) -> (co, c)
  | Motion (co, c) -> (co, c)

let getUEventCoords u = match u with
  | Click (co, _) -> co
  | Motion (co, _) -> co

let shiftUevent u co = match u with
  | Click (_, c) -> Click (co, c)
  | Motion (_, c) -> Motion (co, c)
