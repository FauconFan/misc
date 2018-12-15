
open Base
open Graphics

type litt = bool * string

exception Unsat

(*
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
*)
let rec shift p v i =
  if i < Array.length p then begin
    p.(i) <- v; shift p (v + 1) (i + 1) end

let rec moveLast (p : int array) (s : int) (i : int) =
  let size_p = Array.length p in
  if i < 0 then false
  else if p.(i) >= (s - 1) then moveLast p s (i-1)
  else if i >= (size_p - 1) then begin p.(i) <- p.(i) + 1; true end
  else if p.(i + 1) = p.(i) + 1 then moveLast p s (i - 1)
  else begin shift p (p.(i) + 1) i; true end

let add_sol ens p res =
  let list_init n f =
    let rec add_el i l =
      if(i < 0 || i >= n) then l
      else add_el (i-1) ((f i) :: l)
    in
    add_el (n-1) []
  in
  res := (list_init (Array.length p) (fun a -> ens.(p.(a)))) :: (!res)

let k_combinaison k ens =
  let ens = Array.of_list ens in
  let n = Array.length ens in
  if k <= 0 || k > n  then []
  else
    let res = ref [] in
    let p = Array.init k (fun a -> a) in
    let rec aux () =
      begin
        add_sol ens p res;
        if(moveLast p (Array.length ens) (Array.length p - 1)) then aux ()
        else !res
      end
    in
    aux ()

let string_of_litt (b, str) =
  if b then str
  else "!" ^ str

let string_of_color c =
  if c = red then "Red"
  else if c = green then "Green"
  else if c = blue then "Blue"
  else if c = yellow then "Yellow"
  else if c = cyan then "Cyan"
  else if c = magenta then "Magenta"
  else "Bug"

let bsp_to_fnc (bsp : bsp) : litt list list =
  let hash = Hashtbl.create 13 in
  let rec aux bsp even prefix res =
    match bsp with
    | R c ->
      begin
        let t = match c with
          | None -> Hashtbl.replace hash prefix [red; blue];
            [(true, prefix); (false, prefix)]
          | Some cc -> Hashtbl.replace hash prefix [cc]; [(cc = red), prefix]
        in
        t :: res
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
        let li = li_opt |> Option.get |> List.map (fun (name, _) -> name) in
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
    if k - !p <= 0 then raise Unsat;
    k_combinaison (k - !p) rects_of_line
    |> List.map (fun l -> match l with
        | [x] -> Hashtbl.replace hash x [c]; List.map (fun (n) -> (b, n)) l
        | _ -> List.map (fun (n) -> (b, n)) l)
    |> (fun li -> li @ res)
  and aux_magenta rects_of_line n c res =
    if n mod 2 = 1 then raise Unsat;
    let tmp = aux_color rects_of_line (n + 2) red res in
    aux_color rects_of_line (n + 2) blue tmp
  in
  aux bsp false "" []

(* let bsp_to_fnc (bsp : bsp) : litt list list =
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
    let q = ref 0 in
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
      li
      |> List.filter (fun name ->
          begin
            let saved = Hashtbl.find hash name in
            if (List.mem c saved && List.length saved = 1) then (incr q; false)
            else true
          end)
      (* Some magic crazy shit happens here *)
      |> k_combinaison (!q) (n - (n / 2 + acc) + 1)
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
   res *)
