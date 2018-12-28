(** FNC module *)

open Base
open Graphics

type litt = bool * string
(**
   type of a litteral
*)

exception Unsat
(**
   exception thrown by bsp_to_fnc if no solution exists
*)

val bsp_to_fnc : bsp -> litt list list
(**
   Return a conjunction of disjunction (conjunctive normal form) that represents the given bsp
*)
