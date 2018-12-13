
open Base
open Graphics

type litt = bool * string

val string_of_litt : litt -> string

val bsp_to_fnc : bsp -> litt list list
