(** Fichier ml contenant les types et fonctions de base utilisés dans tout le projet *)

open Graphics

type dim = int * int (** width, height *)
type coords = int * int (** x, y *)
type rect = coords * dim (** left corner coords, and the dimension *)
type line = coords * coords (** coords of the two points of the segments *)

(**
  * Config report used to get user information
  *)
type config =
  {
    dims : dim; (** dimension de la fenêtre graphique. Permet de construire l'arbre en fonction *)
    depth : int; (** profondeur de l'arbre *)
  }

(* Types given by the subject *)

type label =
  {
    coord : int; (** taille de la ligne. L'interprétation dépend de la position dans le bsp *)
    colored : bool; (** boolean exprimant si la ligne est coloriée ou si elle est en noir *)
  }

type bsp =
  | R of color option (** Couleur d'un rectangle *)
  | L of label * bsp * bsp (** composé d'un label correspondant à la ligne et de 2 arbres bsp en fils *)

(**
   Fonction prenant deux dimensions en arguments (x,y) et (width, height) et renvoyant si la dimension
   coordonnée se situe entre (0,0) et (width, height).
*)
let bounds ((x,y) : dim) ((width, height) : dim) : bool =
  x >= 0
  && y >= 0
  && x < width
  && y < height

(**
  Fonction applicant la fonction f à x ssi x est différent de None, sinon renvoit default
*)
let maybe f x default =
  match x with 
  | None -> default
  | Some y -> f y
