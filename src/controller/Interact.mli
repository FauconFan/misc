
(** Interact Module *)

open Graphics
open Base

val getAllColors : unit -> color list
(** Returns all colors used by the program *)

val interact : unit -> (coords * color option) option
(**
   Function thats interact with the user :
    - 'q' exits the programs
    - 'r' / 'b' changes the current color.
*)
