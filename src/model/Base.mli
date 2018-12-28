
(** Base module for all the project *)

open Graphics

(**
   Base module that contains types and functions of all the project.
*)

type dim = int * int
(** dimension width, height *)

type coords = int * int
(** cartesian coords x, y *)

type rect = coords * dim
(** left corner coords, and the dimension *)

type line = coords * coords
(** coords of the two points of the segments *)


type config =
  {
    dims : dim;
    depth : int;
  }

(** Config report used to get user information
    - dimension of the playground.
    - depth of the final bsp
*)

type string_content =
  {
    coordinate : coords;
    color : color;
    size : int;
    center : bool;
    content : string list;
  }
(** type for string information, it is composed of :
    - left down corner coordinate
    - dimension of the area of string
    - color of the string
    - font of the string
    - size of the string
    - content of the string
*)

type label =
  {
    coord : int;
    color : color option;
  }

val font_format : (int -> string, unit, string) format
(**
   font format for a graphic's string
*)

val construct_font : int -> string

(** Label given by the subjet :
    - position of the line. Interpretation depends of the position in the bsp
    - color of the line if it exists, black otherwise.
*)

type bsp =
  | R of color option
  | L of label * bsp * bsp

(** bsp given by the subject :
    - color of a rectangle (a leaf)
    - a label and 2 subtrees (a node)
*)

val bounds : dim -> dim -> bool
(**
   Function thats return if a point is in a given dimension.
*)

val diff_dim : int * int -> int * int -> int * int
(**
   Function that returns the absolute diff between two dimensions.
*)

val construct_string_content :
  ?color:color ->
  ?center:bool->
  coords -> int -> string list -> string_content
(**
   Function that constructs a string_content with a default font.
*)

type uevent =
  | Click of coords * color option
  | Motion of coords * color option
  (**
     type for any graphic's action of the user
  *)

val getUEventData : uevent -> coords * color option
(**
   Get the data of the uevent, whithout knowing its type
*)

val getUEventCoords : uevent -> coords
(**
   Get the coordinate of the uevent, whithout knowing its type
*)

val shiftUevent : uevent -> coords -> uevent
(**
   change coordinate of the uevent, whithout knowing its type
*)
