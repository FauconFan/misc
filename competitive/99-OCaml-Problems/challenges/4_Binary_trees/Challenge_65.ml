
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

let rec height_tree b = match b with
  | Empty             -> 0
  | Node (_, l, r)    -> 1 + (max (height_tree l) (height_tree r))

let layout_binary_tree_2 b =
  let tree_h = height_tree b in
  let rec get_x_root b padding = match b with
    | Empty               -> 0
    | Node (_, Empty, _)  -> 1
    | Node (_, l, _)      -> padding + (get_x_root l (padding / 2)) in
  let padding_root = (1 lsl (tree_h - 2)) in
  let x_root = get_x_root b padding_root in
  let rec loop x y padding b = match b with
    | Empty             -> Empty
    | Node (c, l, r)    ->
      begin
        let lsh = loop (x - padding) (y + 1) (padding / 2) l
        and rsh = loop (x + padding) (y + 1) (padding / 2) r in
        Node ((c, x, y), lsh, rsh)
      end in
  loop x_root 1 padding_root b

let test () =
  let e1 =
    let leaf x = Node (x,Empty,Empty) in
    Node('n', Node('k', Node('c', leaf 'a',
                             Node('e', leaf 'd', leaf 'g')),
                   leaf 'm'),
         Node('u', Node('p', Empty, leaf 'q'), Empty)) in
  let o1 = Node (('n', 15, 1),
                Node (('k', 7, 2),
                      Node (('c', 3, 3), Node (('a', 1, 4), Empty, Empty),
                            Node (('e', 5, 4), Node (('d', 4, 5), Empty, Empty),
                                  Node (('g', 6, 5), Empty, Empty))),
                      Node (('m', 11, 3), Empty, Empty)),
                Node (('u', 23, 2),
                      Node (('p', 19, 3), Empty, Node (('q', 21, 4), Empty, Empty)), Empty)) in
  let e2 =
    let leaf x = Node (x,Empty,Empty) in
    Node('n', Empty,
         Node('u', Node('p', Empty, leaf 'q'), Empty)) in
  let o2 = Node (('n', 1, 1), Empty,
                 Node (('u', 5, 2),
                       Node (('p', 3, 3), Empty, Node (('q', 4, 4), Empty, Empty)), Empty)) in
  TestManager.startChallenge "65 - layout_binary_tree_2";
  TestManager.doTest "Example" ((layout_binary_tree_2 e1) = o1);
  TestManager.doTest "Example2" ((layout_binary_tree_2 e2) = o2);
	TestManager.endChallenge ()
