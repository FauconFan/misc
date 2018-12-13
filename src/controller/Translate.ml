
open Graphics
open Base

let lines_from_bsp (config : config) (bsp : bsp) : (line * color option) list =
  Bsp.lines_from_bsp config bsp

let rectangles_from_bsp (config : config) (bsp : bsp) : (rect * color option) list =
  Bsp.rectangles_from_bsp config bsp
