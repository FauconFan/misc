
open Graphics
open GMessage
open Base

class frameBSP config posx posy =
  object (self)
    inherit SLAC.acomponent posx posy as super

    val mutable bsp = Generation.random_bsp_naive config

    method getLines () : (coords * coords * color * int) list =
      let lines_builder l ((co1, co2), c) =
        let real_color = Option.default black c in
        (co1, co2, white, 5) :: (co1, co2, real_color, 3) :: l
      in
      bsp
      |> Translate.lines_from_bsp config
      |> List.fold_left lines_builder []

    method getRects () : (coords * dim * color) list =
      let rects_builder ((co, dim), c) =
        (co, dim, Option.default white c)
      in
      bsp
      |> Translate.rectangles_from_bsp config
      |> List.map rects_builder

    method subClick c =
      bsp <- change_rectangle_color c bsp;
      Nothing
  end
