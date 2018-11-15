
(** DUGraphics module  *)

open Graphics
open Base

val init : config -> unit
(**
   Inits the graphical window.
*)

val close : unit -> unit
(**
   Closes the graphical window.
*)

val draw_current_bsp : config -> bsp -> unit
(**
   Draws the current bsp.
   First, drawning rectangles.
   Then, drawning lines.
*)

val launch : config -> bsp -> unit
(**
   Launches the puzzle and interacts with the user.
*)
