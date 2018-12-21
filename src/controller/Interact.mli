
(** Interact Module, interacting with the user *)

open Graphics
open Base

val getAllColors : unit -> color list
(** Returns all colors used by the program *)

val getColorOpt : unit -> color option
(** Get the current color *)

val changeColorOpt : color option -> unit
(** Change the current color *)

val interact : unit -> (coords * color option) option
(**
   Function thats interact with the user :
    - 'q' exits the programs
    - 'r' / 'b' changes the current color.
*)
