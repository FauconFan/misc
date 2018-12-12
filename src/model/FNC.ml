
open Base
open Graphics

type litt = bool * string

exception Unsat

let k_combinaison k sl =
  let rec aux k sl l res =
    if k = 0 then res
    else if k = 1 then res @ List.map (fun i -> [i]) sl
    else
      begin
        if k > l then raise Unsat
        else if k = l then sl :: res
        else
          begin
            match sl with
            | []      -> raise Unsat
            | x :: xs ->
              begin
                let ltmp = aux (k - 1) xs (l - 1) res in
                let left = List.map (fun ll -> x :: ll) ltmp in
                aux k xs (l - 1) left
              end
          end
      end
  in
  aux k sl (List.length sl) []
