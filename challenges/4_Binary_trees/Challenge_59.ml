
type 'a binary_tree =
    | Empty
    | Node of 'a * 'a binary_tree * 'a binary_tree

let rec list_foldl f i li = match li with
	| []			-> i
	| head :: tail	-> list_foldl f (f i head) tail

let build_subtrees left right all =
	let build2 all l =
		list_foldl (fun a r -> Node ('x', l, r) :: a) all right in
	list_foldl build2 all left

let rec hbal_tree n =
	if n <= 0 then [Empty]
	else if n = 1 then [Node ('x', Empty, Empty)]
	else
		begin
			let t1 = hbal_tree (n - 1) in
			let t2 = hbal_tree (n - 2) in
			build_subtrees t1 t1
				(build_subtrees t1 t2
					(build_subtrees t2 t1 []))
		end

let test () =
	let o3 = [Node ('x', Node ('x', Empty, Node ('x', Empty, Empty)), Node ('x', Empty, Node ('x', Empty, Empty))); Node ('x', Node ('x', Empty, Node ('x', Empty, Empty)), Node ('x', Node ('x', Empty, Empty), Empty)); Node ('x', Node ('x', Empty, Node ('x', Empty, Empty)), Node ('x', Node ('x', Empty, Empty), Node ('x', Empty, Empty))); Node ('x', Node ('x', Node ('x', Empty, Empty), Empty), Node ('x', Empty, Node ('x', Empty, Empty))); Node ('x', Node ('x', Node ('x', Empty, Empty), Empty), Node ('x', Node ('x', Empty, Empty), Empty)); Node ('x', Node ('x', Node ('x', Empty, Empty), Empty), Node ('x', Node ('x', Empty, Empty), Node ('x', Empty, Empty))); Node ('x', Node ('x', Node ('x', Empty, Empty), Node ('x', Empty, Empty)), Node ('x', Empty, Node ('x', Empty, Empty))); Node ('x', Node ('x', Node ('x', Empty, Empty), Node ('x', Empty, Empty)), Node ('x', Node ('x', Empty, Empty), Empty)); Node ('x', Node ('x', Node ('x', Empty, Empty), Node ('x', Empty, Empty)), Node ('x', Node ('x', Empty, Empty), Node ('x', Empty, Empty))); Node ('x', Node ('x', Empty, Node ('x', Empty, Empty)), Node ('x', Empty, Empty)); Node ('x', Node ('x', Node ('x', Empty, Empty), Empty), Node ('x', Empty, Empty)); Node ('x', Node ('x', Node ('x', Empty, Empty), Node ('x', Empty, Empty)), Node ('x', Empty, Empty)); Node ('x', Node ('x', Empty, Empty), Node ('x', Empty, Node ('x', Empty, Empty))); Node ('x', Node ('x', Empty, Empty), Node ('x', Node ('x', Empty, Empty), Empty)); Node ('x', Node ('x', Empty, Empty), Node ('x', Node ('x', Empty, Empty), Node ('x', Empty, Empty)))] in
	TestManager.startChallenge "59 - hbal_tree";
	TestManager.doTest "3" (hbal_tree 3 = o3);
	TestManager.endChallenge ()
