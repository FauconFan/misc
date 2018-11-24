open Base
open Graphics
open GMessage

class Button dim content coord action =
  object (self)
    inherit SLAC.acomponent coord as super

    method draw () : unit =
      super#draw ();
      self#draw_string_center ()

    method getLines () : (coords * coords * color * int) list = []

    method getRects () : (coords * dim * color) list =
      let gray = rgb 109 110 112 in
      let black_grayed = rgb 24 24 25 in
      let min_dim = (fst dim - 2, snd dim - 2) in
      (coord, dim, gray):: ((fst coord + 1, snd coord + 1), min_dim, black_grayed) :: []

    method subClick (c : (coords * color option)) : (SLAC.scene GMessage.t) =
      let diff (x1, y1) (x2, y2) = (x2-x1, y2-y1) in
      if bounds (diff (fst c) (coord)) dim then Apply (c |> action)
      else Nothing

    method private draw_string_center () =
      let (cur_x, cur_y) = current_point () in
      set_font "-*-fixed-medium-r-semicondensed--50-*-*-*-*-*-iso8859-1";
      let dim_str = text_size content in
      let (middle_x, middle_y) = (fst coord + (fst dim / 2), snd coord + (snd dim / 2)) in
      moveto (middle_x - (fst dim_str / 2)) (middle_y - (snd dim_str / 2));
      draw_string content;
      moveto cur_x cur_y

  end