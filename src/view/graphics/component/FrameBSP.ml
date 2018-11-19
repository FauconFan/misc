
open Graphics
open Base

class frameBSP config posx posy =
  object (self)
    inherit AComponent.acomponent posx posy as super

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
      bsp <- change_rectangle_color c bsp

      (* method draw =
         let d_rect (((x, y), (w, h)), c) =
          set_color white;
          Option.may set_color c;
          fill_rect x y w h;
          set_color white;
         in
         let d_line (((x1, y1), (x2, y2)), c) =
          let aux w col =
            col;
            set_line_width w;
            moveto x1 y1;
            lineto x2 y2;
          in
          aux 5 (white |> set_color);
          aux 3 (Option.map_default set_color (black |> set_color) c);
         in
         let rects = Translate.rectangles_from_bsp config bsp in
         let lines = Translate.lines_from_bsp config bsp in
         List.iter d_rect rects;
         List.iter d_line lines; *)
  end
