
open Graphics
open Base

val init : config -> unit
val close : unit -> unit

val draw_current_bsp : config -> bsp -> unit
val launch : config -> bsp -> unit
