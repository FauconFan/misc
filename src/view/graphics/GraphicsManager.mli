
(** GraphicsManager Module *)

(** It deals with the main task of graphic's managing. *)

open Graphics
open Base

val init : config -> SLAC.scene -> unit
(** 
  initialization of GraphicsManager and Graphic's window.
*)

val close : unit -> unit
(** 
  close of GraphicsManager and Graphic's windows.
*)

val run : unit -> unit
(**
  running function of view's managing
*)

val changeConfig : config -> unit
(**
  Set configuration of the view, i.e set width and height of graphic's window and set depth of the bsp.
*)