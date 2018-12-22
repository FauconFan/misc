open Base
open Graphics
open GMessage

class popup content button dim coord =
  object (self)
    inherit SLAC.acomponent coord dim as super

    method! getLines () : (coords * coords * color * int) list =
      List.fold_left (fun a b -> a @  (b#getLines())) [] button

    method! getRects () : (coords * dim * color) list =
      let buttons = List.fold_left (fun a b -> a @ (b#getRects())) [] button in
      let gray = rgb 105 109 110 in
      let beige = rgb 245 246 245 in
      let padding = 2 in
      let contour = ((0,0), dim, gray) in
      let content = ((padding, padding), (fst dim - (padding * 2), snd dim - (padding * 2)), beige) in
      contour :: content :: buttons

    method! getStrings () =
      let padding = 10 in
      let buttons_str = List.fold_left (fun a b -> a @ (b#getStrings())) [] button in
      let cont = construct_string_content (padding, snd dim) 30 content in
      cont :: buttons_str

    method subClick uevent : (SLAC.scene GMessage.t) =
      match uevent with
      | Click (_, _) as click ->
        begin
          let rec aux l =
            match l with
            | [] -> Nothing
            | h :: q ->
              let message = h#subClick click in
              if message = Nothing then aux q
              else message
          in
          aux button
        end
      | _ -> Nothing

  end
