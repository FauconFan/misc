
open Graphics
open Base

val lines_from_bsp : config -> bsp -> (line * color option) list
val rectangles_from_bsp : config -> bsp -> (rect * color option) list
