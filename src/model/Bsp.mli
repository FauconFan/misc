
open Base
open Graphics

val color_of_line : bsp -> bsp -> bool -> color option
(**
   Returns the color of a ligne based of the two left and right subtrees and the parity of the current depth.
*)

val change_rectangle_color : coords * color option -> bsp -> bsp
(**
   Change the color of the rectangle pointed by the color.
*)

val lines_from_bsp : config -> bsp -> (line * color option) list
(**
   Returns a list of lines with color from a bsp
*)

val rectangles_from_bsp : config -> bsp -> (rect * color option) list
(**
   Returns a list of rects with color from a bsp
*)
