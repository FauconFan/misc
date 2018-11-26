open Base
open Graphics
open GMessage

class button dim content coord callback =
  object (self)
    inherit SLAC.acomponent coord as super

    method! draw () : unit =
      super#draw ();
      self#draw_string_center ()

    method getLines () : (coords * coords * color * int) list = []

    method getRects () : (coords * dim * color) list =
      let gray = rgb 109 110 112 in
      let black_grayed = rgb 200 200 200 in
      let min_dim = (fst dim - 2, snd dim - 2) in
      ((0,0), dim, gray):: (( 1, 1), min_dim, black_grayed) :: []

    method subClick (c : (coords * color option)) : (SLAC.scene GMessage.t) =
      let diff (x1, y1) (x2, y2) = (x2-x1, y2-y1) in
      if bounds (fst c) dim then Apply (c |> callback)
      else Nothing

    method private draw_string_center () =
      let (cur_x, cur_y) = current_point () in
      set_font "-*-fixed-medium-r-semicondensed--30-*-*-*-*-*-iso8859-1";
      let dim_str = text_size content in
      let (middle_x, middle_y) = (fst coord + (fst dim / 2), snd coord + (snd dim / 2)) in
      moveto (middle_x - (fst dim_str / 2)) (middle_y - (snd dim_str / 2));
      set_color black;
      draw_string content;
      moveto cur_x cur_y

  end