
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

let rec internals t = match t with
  | Empty                   -> []
  | Node (_, Empty, Empty)  -> []
  | Node (x, l, r)          -> (internals l @ [x] @ internals r)

let test () =
  let example_tree =
      Node('a', Node('b', Node('d', Empty, Empty), Node('e', Empty, Empty)),
           Node('c', Empty, Node('f', Node('g', Empty, Empty), Empty))) in
  TestManager.startChallenge "62 - internals";
  TestManager.doTest "example" ((internals example_tree) = ['b'; 'a'; 'c'; 'f']);
	TestManager.endChallenge ()
