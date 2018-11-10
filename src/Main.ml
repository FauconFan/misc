
open Base

let default_weight = 1000
let default_height = 1000
let default_depth = 5

let weight = ref default_weight
let height = ref default_height
let depth = ref default_depth

let opt_weight = ("-w", Arg.Set_int weight, "weight of the window")
let opt_height = ("-h", Arg.Set_int height, "height of the window")
let opt_depth = ("-d", Arg.Set_int depth, "depth of the bsp tree")

let spec_list = [opt_weight; opt_height; opt_depth]

let usage_msg = "PF5 project in honor of Mondrian"

let () =
  Arg.parse spec_list ignore usage_msg;
  let config = {dims = (!weight, !height); depth = !depth} in

  DUGraphics.init config;
  DUGraphics.launch config;
  DUGraphics.close ()
