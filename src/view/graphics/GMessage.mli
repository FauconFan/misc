(** GMessage Module *)

(** Interaction between all component's view *)

type 'a t =
  | Nothing
  | Apply of (unit -> unit)
  | Update of (unit -> 'a)
  (**
     Type for interaction between graphic's component :
     - Nothing : no change
     - Apply : change with unit function
     - Update : change a view, or something like
  *)
