
val may : ('a -> unit) -> 'a option -> unit
val map : ('a -> 'b) -> 'a option -> 'b option
val default : 'a -> 'a option -> 'a
val map_default : ('a -> 'b) -> 'b -> 'a option -> 'b
val is_none : 'a option -> bool
val is_some : 'a option -> bool
val get : 'a option -> 'a

exception No_value
