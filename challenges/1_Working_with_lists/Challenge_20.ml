
let rec remove_at li n =
	if n < 0 then li
	else match li with
		| []			-> []
		| head :: tail	-> if n = 0 then tail
							else head :: (remove_at tail (n - 1))

let test () =
	let l1 = (true, "Empty", 3, [], []) in
	let l2 = (true, "Singleton0", (-1), [2], [2]) in
	let l3 = (true, "Singleton0", 0, [2], []) in
	let l4 = (true, "Singleton1", 1, [2], [2]) in
	let l5 = (true, "One", 1, [1; 2; 3; 4], [1; 3; 4]) in
	let l6 = (true, "Two", (-1), [1; 2; 3; 4], [1; 2; 3; 4]) in
	let l7 = (true, "Five", 2, [1; 2; 3; 4], [1; 2; 4]) in
	let l8 = (false, "FiveFailed", 2, [1; 2; 3; 4], [1; 3; 4]) in
	let l = [l1; l2; l3; l4; l5; l6; l7; l8] in
	let apply a = match a with
		| (b, n, arg1, l, exp) -> TestManager.doTest n ((remove_at l arg1 = exp) = b)
	in

	TestManager.startChallenge "20 - remove_at";
	List.iter apply l;
	TestManager.endChallenge ()
