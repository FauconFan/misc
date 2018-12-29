
(**
  A button color for changing the actual color in Interact component for graphic's view
*)

open Base
open Graphics

class button_color :
  color option ->
  int ->
  coords ->
  object
    inherit Button.button
  end
