
open Base
open Graphics

type litt = bool * string

exception Unsat

let k_combinaison k sl =
  let rec core k sl =
    let rec aux sl = match sl with
      | []      -> []
      | x :: xs -> (List.map (fun z -> x :: z) (core (k - 1) xs)) :: aux xs
    in
    if k = 0 then [[]]
    else List.flatten (aux sl)
  in
  let l = List.length sl in
  if k < 0 || k > l then raise Unsat
  else if k = 0 then [[]]
  else core k sl

let string_of_litt (b, str) =
  if b then str
  else "!" ^ str

let bsp_to_fnc (bsp : bsp) : litt list list =
  let hash = Hashtbl.create 13 in
  let rec aux bsp even prefix res =
    match bsp with
    | R c ->
      begin
        Hashtbl.replace hash prefix (Option.map_default (fun c -> [c]) [blue; red] c);
        [(true, prefix); (false, prefix)] :: res
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
        if c = magenta then aux_magenta label l r even prefix c res
        else aux_color label l r even prefix c false res
      end
  and aux_color label l r even prefix c is_dual res =
    let crazy_optimisation clause color =
      if List.length clause = 1 then
        begin
          let name = List.hd clause in
          Hashtbl.replace hash name [color]
        end
    in
    let (stats_arr, li_opt) = Bsp.stats_of_line l r even (Some prefix) in
    let li = li_opt |> Option.get |> List.map (fun (name, _) -> name) in
    let b = (c == red) in
    let n = stats_arr.(2) in
    let acc = if is_dual then 0 else 1 in
    let stats_hash = [|0; 0|] in
    List.iter
      (fun name ->
         begin
           let saved = Hashtbl.find hash name in
           if List.length saved = 1 then
             let col = List.hd saved in
             if col = red then stats_hash.(1) <- stats_hash.(1) + 1
             else stats_hash.(0) <- stats_hash.(0) + 1
         end)
      li;
    Printf.printf "%d %d\n" stats_hash.(0) stats_hash.(1);
    if not is_dual && b && stats_hash.(1) > n / 2 + 1 then res
    else if not is_dual && not b && stats_hash.(0) > n / 2 + 1 then res
    else if is_dual && stats_arr.(2) / 2 = stats_hash.(1) && stats_hash.(1) = stats_hash.(0) then res
    else
      li
      |> List.filter (fun name ->
          begin
            let saved = Hashtbl.find hash name in
            not (List.mem c saved && List.length saved = 1)
          end)
      (* Some magic crazy shit happens here *)
      |> k_combinaison (n - (n / 2 + acc) + 1)
      |> List.map (fun ll ->
          begin
            crazy_optimisation ll c;
            List.map (fun n -> (b, n))
          end
            ll)
      |> (fun li -> li @ res)
  and aux_magenta label l r even prefix c res =
    res
    |> aux_color label l r even prefix red true
    |> aux_color label l r even prefix blue true
  in
  let res = aux bsp false "" [] in
  (* Hashtbl.iter (fun a b -> Printf.printf "%s" a; List.iter (fun i -> Printf.printf " %d " i) b; print_newline ()) hash; *)
  res
