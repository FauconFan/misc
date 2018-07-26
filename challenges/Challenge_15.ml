
let rec replicate li n = match li with
	| []			-> []
	| head :: tail	->
		let rec build s rem =
			if rem <= 0 then (replicate tail n)
			else s :: (build s (rem - 1))
		in
		(build head n)

let test () =
	let l1 = (true, "Empty", 3, [], []) in
	let l2 = (true, "Singleton", 1, [2], [2]) in
	let l3 = (true, "Singleton3", 3, [2], [2; 2; 2]) in
	let l4 = (true, "PairSame", 2, [2; 2], [2; 2; 2; 2]) in
	let l5 = (true, "PairDiff", 2, [2; 3], [2; 2; 3; 3]) in
	let l6 = (false, "PairDiffFail", 2, [2; 3], [2; 3; 3]) in
	let l7 = (true, "Triple3", 3, [1; 2; 3], [1; 1; 1; 2; 2; 2; 3; 3; 3]) in
	let l = [l1; l2; l3; l4; l5; l6; l7] in
	let apply a = match a with
		| (b, n, arg, l, exp) -> TestManager.doTest n ((replicate l arg = exp) = b)
	in

	TestManager.startChallenge "15 - replicate";
	List.iter apply l;
	TestManager.endChallenge ()
