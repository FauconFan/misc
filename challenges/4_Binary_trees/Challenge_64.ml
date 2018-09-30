
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

let layout_binary_tree_1 b =
  let rec core x y b = match b with
    | Empty           -> (Empty, x)
    | Node (c, l, r)  ->
      begin
        let (lhs, new_x) = core x (y + 1) l in
        let (rhs, new_new_x) = core (new_x + 1) (y + 1) r in
        let new_head = Node ((c, new_x, y), lhs, rhs) in
        (new_head, new_new_x)
      end in
  let (res, _) = core 1 1 b in
  res

let test () =
  let e1 =
    let leaf x = Node (x, Empty, Empty) in
    Node('n', Node('k', Node('c', leaf 'a',
                             Node('h', Node('g', leaf 'e',Empty), Empty)),
                   leaf 'm'),
         Node('u', Node('p', Empty, Node('s', leaf 'q', Empty)), Empty)) in
  let o = Node (('n', 8, 1),
 Node (('k', 6, 2),
  Node (('c', 2, 3), Node (('a', 1, 4), Empty, Empty),
   Node (('h', 5, 4),
    Node (('g', 4, 5), Node (('e', 3, 6), Empty, Empty), Empty), Empty)),
  Node (('m', 7, 3), Empty, Empty)),
 Node (('u', 12, 2),
  Node (('p', 9, 3), Empty,
   Node (('s', 11, 4), Node (('q', 10, 5), Empty, Empty), Empty)),
  Empty)) in
  TestManager.startChallenge "64 - layout_binary_tree_1";
  TestManager.doTest "Example" ((layout_binary_tree_1 e1) = o);
	TestManager.endChallenge ()
