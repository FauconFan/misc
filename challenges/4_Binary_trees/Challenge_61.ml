
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

let rec count_leaves t = match t with
  | Empty                   -> 0
  | Node (_, Empty, Empty)  -> 1
  | Node (_, l, r)          -> count_leaves l + count_leaves r

let test () =
  let example_tree =
      Node('a', Node('b', Node('d', Empty, Empty), Node('e', Empty, Empty)),
           Node('c', Empty, Node('f', Node('g', Empty, Empty), Empty))) in
  TestManager.startChallenge "61 - count_leaves";
  TestManager.doTest "example" ((count_leaves example_tree) = 3);
	TestManager.endChallenge ()
