open Base
open Graphics
open GMessage

let color_of_button_color copt =
  Option.map_default (fun i -> i) (rgb 255 255 255) copt

class button_color copt size coord =
  object (self)
    inherit Button.button
        ~color_font:(color_of_button_color copt)
        (size, size)
        []
        coord
        (fun _ -> GMessage.Apply (fun _ -> Interact.changeColorOpt copt))
      as super

    method! getRects () =
      if Option.equal (Interact.getColorOpt ()) copt (=) then super#setPadding 3
      else super#resetPadding ();
      super#getRects ()
  end
