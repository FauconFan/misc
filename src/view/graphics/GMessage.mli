
type 'a gmessage =
  | Nothing
  | Apply of ('a -> unit)
  | Update of (unit -> 'a)
