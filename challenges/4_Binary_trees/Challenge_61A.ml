
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

let rec leaves t = match t with
  | Empty                   -> []
  | Node (x, Empty, Empty)  -> [x]
  | Node (_, l, r)          -> leaves l @ leaves r

let test () =
  let example_tree =
      Node('a', Node('b', Node('d', Empty, Empty), Node('e', Empty, Empty)),
           Node('c', Empty, Node('f', Node('g', Empty, Empty), Empty))) in
  TestManager.startChallenge "61A - leaves";
  TestManager.doTest "example" ((leaves example_tree) = ['d'; 'e'; 'g']);
	TestManager.endChallenge ()
