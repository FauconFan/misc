
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

let rec at_level t n =
  if n <= 0 then []
  else match t with
  | Empty                   -> []
  | Node (x, l, r)          -> if n = 1 then [x] else (at_level l (n - 1)) @ (at_level r (n - 1))

let test () =
  let example_tree =
      Node('a', Node('b', Node('d', Empty, Empty), Node('e', Empty, Empty)),
           Node('c', Empty, Node('f', Node('g', Empty, Empty), Empty))) in
  TestManager.startChallenge "62A - at_level";
  TestManager.doTest "example" ((at_level example_tree 2) = ['b'; 'c']);
  TestManager.doTest "example2" ((at_level example_tree 5) = []);
	TestManager.endChallenge ()
