
(** Functions for the option type *)

(**
   This sig file is coming from this website : http://ocaml-lib.sourceforge.net/doc/Option.html
*)

(**
   Options are an Ocaml standard type that can be either None (undefined) or Some x where x can be any value. Options are widely used in Ocaml to represent undefined values (a little like NULL in C, but in a type and memory safe way). This module adds some functions for working with options.
*)

val may : ('a -> unit) -> 'a option -> unit
(** may f (Some x) calls f x and may f None does nothing. *)
val may2 : ('a -> 'b -> unit) -> 'a option -> 'b option -> unit
(** may f (Some x) (Some y) calls f x y and does nothing otherwise. *)
val map : ('a -> 'b) -> 'a option -> 'b option
(** map f (Some x) returns Some (f x) and map None returns None. *)
val default : 'a -> 'a option -> 'a
(** default x (Some v) returns v and default x None returns x. *)
val map_default : ('a -> 'b) -> 'b -> 'a option -> 'b
(** map_default f x (Some v) returns f v and map_default f x None returns x. *)
val map2_default : ('a -> 'b -> 'c) -> 'c -> 'a option -> 'b option -> 'c
(** map2_default f x (Some v) (Some w) returns f v w and returns x otherwise *)
val is_none : 'a option -> bool
(** is_none None returns true otherwise it returns false. *)
val is_some : 'a option -> bool
(** is_some (Some x) returns true otherwise it returns false. *)
val get : 'a option -> 'a
(** get (Some x) returns x and get None raises No_value. *)

exception No_value
(** Raised when calling get None.*)
