
open Base
open Graphics

type litt = bool * string

type prop =
  | Litt of litt
  | Or of prop * prop
  | And of prop * prop

let not_litt (litt : litt) : litt =
  let (b, str) = litt in
  (not b, str)

let prop_to_fnc (prop : prop) : litt list list =
  let id_inc = ref 0 in
  let uniq_id () =
    let res = "-" ^ (string_of_int (!id_inc)) in
    incr id_inc;
    (true, res)
  in
  let get_llist_from_disj (x : litt) (a : litt) (b : litt) =
    [[not_litt x; a; b]; [not_litt a; x]; [not_litt b; x]]
  and get_llist_from_conj (x : litt) (a : litt) (b : litt) =
    [[x; not_litt a; not_litt b]; [a; not_litt x]; [b; not_litt x]]
  and get_llist_from_litt (x : litt) =
    [[x]]
  in
  let res_ref = ref [] in
  let add_in_res li =
    res_ref := li @ (!res_ref)
  in
  let rec aux prop =
    let handle_arity2 f l r =
      let xl = aux l and xr = aux r in
      let id = uniq_id () in
      add_in_res (f id xl xr);
      id
    in
    match prop with
    | Litt l -> l
    | Or (l, r) -> handle_arity2 get_llist_from_disj l r
    | And (l, r) -> handle_arity2 get_llist_from_conj l r
  in
  let last = aux prop in
  add_in_res (get_llist_from_litt last);
  !res_ref
