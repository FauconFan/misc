
open Graphics

class frame =
  object (self)
    inherit AComponent.acomponent as super

    method draw =
      draw_rect 100 100 (size_x () - 200) (size_y () - 200)
  end
