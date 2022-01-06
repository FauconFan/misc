
(** Check module *)

open Base

val check_current : bsp -> bool
(**
   Checking if the given bsp respects the color of the lines, according to the rectangle's colors.
*)

val check_solve : bsp -> bool
(**
   Check if there is a solution to the actuel state of the bsp
*)

val solve : bsp -> bsp option
(**
   Return None if no solution is found by the sat solver, or a Some bsp if a solution existed
*)
