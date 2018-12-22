open Base
open Graphics
open GMessage


class button ?color_font:(cf = rgb 200 200 200) ?default_padding:(df = 2) dim content coord callback =
  object (self)
    inherit SLAC.acomponent coord dim as super

    val mutable padding = df

    method resetPadding () =
      padding <- df

    method setPadding (p : int) =
      padding <- p

    method getLines () : (coords * coords * color * int) list = []

    method getRects () : (coords * dim * color) list =
      let gray = rgb 109 110 112 in
      let black_grayed = cf in
      let max_dim = (fst dim + 2 * padding, snd dim + (2 * padding)) in
      ((-padding, -padding), max_dim, gray):: ((0, 0), dim, black_grayed) :: []

    method subClick (c : (coords * color option)) : (SLAC.scene GMessage.t) =
      callback c

    method getStrings () =
      let padding_str = 10 in
      let size = 30 in
      let middle_h =
        let half_h = snd dim / 2 in
        let size_content = List.fold_left (fun a b -> set_font (construct_font size); a + snd (text_size b) + 2) 0 content - 2 in
        half_h + (size_content / 2)
      in
      let cont = construct_string_content (padding_str, middle_h) size content in
      [cont]

  end
