open Base
open Graphics

(**
  A button color for changing the actual color in Interact component for graphic's view
*)

class button_color :
  color option ->
  int ->
  coords ->
  object
    inherit Button.button
  end
