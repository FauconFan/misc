
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

let my_split lst =
    let rec list_take lst n =
        if n <= 0 then ([], lst)
        else match lst with
        | []      -> ([], lst)
        | x :: xs ->
                let next = list_take xs (n - 1) in
                (x :: (fst next), snd next) in
    let rec loop lst count res =
        if lst == [] then res
        else
            begin
                let (l, r) = res in
                let (next_l, remain_lst) = list_take lst count in
                let (next_r, remain_lst2) = list_take remain_lst count in
                loop remain_lst2 (count + 1) (l @ next_l, r @ next_r)
            end in
    loop lst 1 ([], [])

let rec complete_binary_tree lst = match lst with
  | []      -> Empty
  | x :: xs ->
      let (l, r) = my_split xs in
      Node (x, (complete_binary_tree l), (complete_binary_tree r))

let test () =
  let o = Node (1, Node (2, Node (4, Empty, Empty), Node (5, Empty, Empty)), Node (3, Node (6, Empty, Empty), Empty)) in
  TestManager.startChallenge "63 - complete_binary_tree";
  TestManager.doTest "example" ((complete_binary_tree [1; 2; 3; 4; 5; 6]) = o);
	TestManager.endChallenge ()
