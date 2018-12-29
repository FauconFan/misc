
open Base
open Graphics

type litt = bool * string

exception Unsat

let bsp_to_fnc (bsp : bsp) : litt list list =
  let hash = Hashtbl.create 256 in
  let rec aux bsp even prefix res =
    match bsp with
    | R c ->
      begin
        let (li_colors, cl) = match c with
          | None -> ([red; blue], [(true, prefix); (false, prefix)])
          | Some cc -> ([cc], [(cc = red), prefix])
        in
        Hashtbl.replace hash prefix li_colors;
        cl :: res
      end
    | L (label, l, r) ->
      begin
        res
        |> aux l (not even) (prefix ^ "l")
        |> aux r (not even) (prefix ^ "r")
        |> aux_line label l r even prefix
      end
  and aux_line label l r even prefix res =
    match label.color with
    | None -> res
    | Some c ->
      begin
        let (stats_arr, li_opt) = Bsp.stats_of_line l r even (Some prefix) in
        let li = li_opt |> Option.get |> List.rev_map (fun (name, _) -> name) in
        let f = if c = magenta then aux_magenta else aux_color in
        f li stats_arr.(2) c res
      end
  and aux_color rects_of_line n c res =
    let b = (c = red) in
    let k = n / 2 + (if n mod 2 = 1 then 1 else 0) in
    let p = ref 0 in
    let rects_of_line =
      List.filter (fun name -> match Hashtbl.find hash name with
          | [] -> failwith "Problème dans aux_color"
          | [x] -> (if x <> c then incr p); false
          | _ -> true
        ) rects_of_line in
    if (k - !p) <= 0 then raise Unsat;
    rects_of_line
    |> Combinatorics.k_combinaison (k - !p)
    |> List.rev_map (fun l -> match l with
        | [x] -> Hashtbl.replace hash x [c]; List.rev_map (fun (n) -> (b, n)) l
        | _ -> List.rev_map (fun (n) -> (b, n)) l)
    |> (fun li -> List.rev_append li res)
  and aux_magenta rects_of_line n c res =
    if n mod 2 = 1 then raise Unsat;
    res
    |> aux_color rects_of_line (n + 2) red
    |> aux_color rects_of_line (n + 2) blue
  in
  aux bsp ModelConstant.first_line_vertical "" []
