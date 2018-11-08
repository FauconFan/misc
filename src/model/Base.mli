
open Graphics

(**
  * This a documentation part
  *)

type dim = int * int (* weight, height *)
type coords = int * int (* x, y *)
type rect = coords * dim (* left corner coords, and the dimension *)
type line = coords * coords (* coords of the two points of the segments *)

(**
  * Config report used to get user information
  *)

type config =
  {
    dims : dim;
    depth : int;
  }

(* Types given by the subject *)

type label =
  {
    coord : int;
    colored : bool;
  }

type bsp =
  | R of color option
  | L of label * bsp * bsp

(* Utils function *)

val bounds : dim -> dim -> bool
