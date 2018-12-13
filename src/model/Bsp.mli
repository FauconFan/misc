
open Base
open Graphics

val color_of_line : bsp -> bsp -> bool -> color
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

val stats_of_line : bsp -> bsp -> bool -> string option -> (int array * (string * color option) list option)
(**
   Returns the statistics about a line, based of the left, and the right subtrees the even of the depth and a prefix.
   See implementation for details.
*)
