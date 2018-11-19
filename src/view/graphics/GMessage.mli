
type 'a t =
  | Nothing
  | Apply of ('a -> unit)
  | Update of (unit -> 'a)
