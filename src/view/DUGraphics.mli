
open Graphics
open Base

val init : config -> unit
val close : unit -> unit

val draw_current_bsp : config -> bsp -> bsp -> unit
val launch : config -> bsp -> bsp -> unit
