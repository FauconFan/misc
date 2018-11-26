
open Base
open Graphics

type litt = bool * string

type prop =
  | Litt of litt
  | Or of prop * prop
  | And of prop * prop

val prop_to_fnc : prop -> litt list list
