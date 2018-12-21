
open Base
open Graphics

type litt = bool * string

exception Unsat

val bsp_to_fnc : bsp -> litt list list
