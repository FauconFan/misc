
(** Check module *)

open Base

val check_current : bsp -> bool
(**
  Checking if the given bsp respects the color of the lines, according to the rectangle's colors.
*)

val check_solve : bsp -> bool
val solve : bsp -> bsp option
