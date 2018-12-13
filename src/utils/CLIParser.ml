
open Base

let default_width = 900 
let default_height = 900
let default_depth = 2

let width = ref default_width
let height = ref default_height
let depth = ref default_depth

let opt_width = ("-w", Arg.Set_int width, "width of the window")
let opt_height = ("-h", Arg.Set_int height, "height of the window")
let opt_depth = ("-d", Arg.Set_int depth, "depth of the bsp tree")

let spec_list = [opt_width; opt_height; opt_depth]

let usage_msg = "PF5 project in honor of Mondrian"

let cliparse () =
  Arg.parse spec_list ignore usage_msg;
  {dims = (!width, !height); depth = !depth}
