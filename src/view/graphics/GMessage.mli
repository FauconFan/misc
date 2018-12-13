(** GMessage Module *)

(** Interaction between all component's view *)

type 'a t =
  | Nothing
  | Apply of (unit -> unit)
  | Update of (unit -> 'a)
