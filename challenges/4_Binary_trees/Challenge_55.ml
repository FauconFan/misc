
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

let rec list_foldl f i li = match li with
	| []			-> i
	| head :: tail	-> list_foldl f (f i head) tail

let rec cbal_tree n =
	let build_subtrees left right all =
		let build2 all l =
			list_foldl (fun a r -> Node ('x', l, r) :: a) all right in
		list_foldl build2 all left in
	if n <= 0 then [Empty]
	else if n mod 2 = 1 then
		begin
			let t = cbal_tree (n / 2) in
			build_subtrees t t []
		end
	else
		begin
			let t1 = cbal_tree (n / 2 - 1) in
			let t2 = cbal_tree (n / 2) in
			build_subtrees t1 t2 (build_subtrees t2 t1 [])
		end

let test () =
	let o0 = [Empty] in
	let o1 = [Node ('x', Empty, Empty)] in
	let o2 = [Node ('x', Empty, Node ('x', Empty, Empty)); Node ('x', Node ('x', Empty, Empty), Empty)] in
	let o3 = [Node ('x', Node ('x', Empty, Empty), Node ('x', Empty, Empty))] in
	let o4 = [Node ('x', Node ('x', Empty, Empty),  Node ('x', Node ('x', Empty, Empty), Empty)); Node ('x', Node ('x', Empty, Empty),  Node ('x', Empty, Node ('x', Empty, Empty))); Node ('x', Node ('x', Node ('x', Empty, Empty), Empty), Node ('x', Empty, Empty)); Node ('x', Node ('x', Empty, Node ('x', Empty, Empty)),  Node ('x', Empty, Empty))] in
	TestManager.startChallenge "55 - cbal_tree";
	TestManager.doTest "0" (cbal_tree 0 = o0);
	TestManager.doTest "1" (cbal_tree 1 = o1);
	TestManager.doTest "2" (cbal_tree 2 = o2);
	TestManager.doTest "3" (cbal_tree 3 = o3);
	TestManager.doTest "4" (cbal_tree 4 = o4);
	TestManager.endChallenge ()
