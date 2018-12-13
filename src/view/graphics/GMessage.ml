
type 'a t =
  | Nothing
  | Apply of (unit -> unit)
  | Update of (unit -> 'a)
