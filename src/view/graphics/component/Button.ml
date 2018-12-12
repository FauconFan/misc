open Base
open Graphics
open GMessage


class button dim content coord callback =
  object (self)
    inherit SLAC.acomponent coord as super

    method getLines () : (coords * coords * color * int) list = []

    method getRects () : (coords * dim * color) list =
      let gray = rgb 109 110 112 in
      let black_grayed = rgb 200 200 200 in
      let min_dim = (fst dim - 2, snd dim - 2) in
      ((0,0), dim, gray):: (( 1, 1), min_dim, black_grayed) :: []

    method subClick (c : (coords * color option)) : (SLAC.scene GMessage.t) =
      if bounds (fst c) dim then (c |> callback)
      else Nothing

    (*method private draw_string_center () =
      let (cur_x, cur_y) = current_point () in
      set_font "-*-fixed-medium-r-semicondensed--30-*-*-*-*-*-iso8859-1";
      let dim_str = text_size content in
      let (middle_x, middle_y) = (fst coord + (fst dim / 2), snd coord + (snd dim / 2)) in
      moveto (middle_x - (fst dim_str / 2)) (middle_y - (snd dim_str / 2));
      set_color black;
      draw_string content;
      moveto cur_x cur_y*)

    method getStrings () =
    let construct_string_content coord c font s content = 
      {
        coordinate = coord;
        color = c;
        font = font;
        size = s;
        content = content;
      }
    in
    let padding = 10 in
    let font = "-*-fixed-medium-r-semicondensed--30-*-*-*-*-*-iso8859-1" in
    let apply_tuple (a,b) f = (f a, f b) in
    let coord = apply_tuple coord (fun a -> padding) in
    let cont = construct_string_content coord black font 30 content in
    [cont]

  end