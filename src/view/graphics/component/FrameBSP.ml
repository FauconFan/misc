
open Graphics
open GMessage
open Base

class frameBSP config (posx, posy) =
  object (self)
    inherit SLAC.acomponent (posx, posy) config.dims as super

    val mutable bsp = Generation.random_bsp_naive config

    method getLines () : (coords * coords * color * int) list =
      let (dim_x, dim_y) = config.dims in
      let ligne = [((posx, posy), (posx, posy + dim_y), black, 3); ((posx, posy), (posx + dim_x, posy), black, 3); ((posx, posy + dim_y), (posx + dim_x, posy + dim_y), black, 3); ((posx + dim_x, posy), (posx + dim_x, posy + dim_y), black, 3)] in
      let lines_builder l ((co1, co2), c) =
        let change_color c =
        if c = red then rgb 255 120 120
        else if c = green then rgb 120 255 120
        else if c = blue then rgb 120 120 255
        else if c = yellow then rgb 255 255 120
        else if c = cyan then rgb 120 255 255
        else if c = magenta then rgb 255 120 255
        else c
        in
        let real_color = Option.map_default change_color black c in
        (co1, co2, real_color, 3) :: l
      in
      bsp
      |> Bsp.lines_from_bsp config
      |> List.fold_left lines_builder ligne

    method getRects () : (coords * dim * color) list =
      let rects_builder ((co, dim), c) =
        (co, dim, Option.default white c)
      in
      bsp
      |> Bsp.rectangles_from_bsp config
      |> List.map rects_builder

    method subClick c =
      bsp <- Bsp.change_rectangle_color c bsp;
      Nothing

    method getStrings () = []
  end
