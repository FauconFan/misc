
let rec duplicate li = match li with
	| []			-> []
	| head :: tail	-> head :: head :: (duplicate tail)

let test () =
	let l1 = (true, "Empty", [], []) in
	let l2 = (true, "Singleton", [2], [2; 2]) in
	let l3 = (true, "PairSame", [2; 2], [2; 2; 2; 2]) in
	let l4 = (true, "PairDiff", [2; 3], [2; 2; 3; 3]) in
	let l5 = (false, "PairDiffFail", [2; 3], [2; 3; 3]) in
	let l = [l1; l2; l3; l4; l5] in
	let apply a = match a with
		| (b, n, l, exp) -> TestManager.doTest n ((duplicate l = exp) = b)
	in

	TestManager.startChallenge "14 - duplicate";
	List.iter apply l;
	TestManager.endChallenge ()
