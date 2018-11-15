
(** Translate module *)

open Graphics
open Base

val lines_from_bsp : config -> bsp -> (line * color option) list
(**
   Returns a list of lines with color from a bsp
*)

val rectangles_from_bsp : config -> bsp -> (rect * color option) list
(**
   Returns a list of rects with color from a bsp
*)
