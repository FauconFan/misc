
let split li n =
	let rec rev_tail_recu li res = match li with
		| []				-> res
		| head :: tail		-> rev_tail_recu tail (head :: res)
	in
	let rec rec_split le ri n =
		if n <= 0 then (le, ri)
		else match ri with
			| []				-> (le, ri)
			| head :: tail		-> rec_split (head :: le) tail (n - 1)
	in
	let buf = rec_split [] li n in
	((rev_tail_recu (fst buf) []), snd buf)

let test () =
	let l1 = (true, "Empty", 3, [], ([], [])) in
	let l2 = (true, "Singleton", 1, [2], ([2], [])) in
	let l3 = (true, "Singleton3", 3, [2], ([2], [])) in
	let l4 = (true, "Pair1", 1, [2; 3], ([2], [3])) in
	let l5 = (true, "Pair2", 2, [2; 3], ([2; 3], [])) in
	let l6 = (true, "Triple2", 2, [2; 3; 4], ([2; 3], [4])) in
	let l = [l1; l2; l3; l4; l5; l6] in
	let apply a = match a with
		| (b, n, arg, l, exp) -> TestManager.doTest n ((split l arg = exp) = b)
	in

	TestManager.startChallenge "17 - split";
	List.iter apply l;
	TestManager.endChallenge ()
