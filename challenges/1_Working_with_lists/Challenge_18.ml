
let slice li n m =
	if n >= m then []
	else
		let rec split_first_part li n = match li with
			| []			-> []
			| _ :: tail		-> if n = 0 then li
							else split_first_part tail (n - 1)
		in
		let rec split_last_part li m = match li with
			| []			-> []
			| head :: tail	-> if m = 0 then []
							else (head :: (split_last_part tail (m - 1)))
		in
		let tmp = split_first_part li n in
		split_last_part tmp (m - n)


let test () =
	let l1 = (true, "Empty", 3, 4, [], []) in
	let l2 = (true, "Singleton", 1, 2, [2], []) in
	let l3 = (true, "One", 1, 2, [1; 2; 3; 4], [2]) in
	let l4 = (true, "Two", 1, 3, [1; 2; 3; 4], [2; 3]) in
	let l5 = (true, "Five", 1, 5, [1; 2; 3; 4], [2; 3; 4]) in
	let l = [l1; l2; l3; l4; l5] in
	let apply a = match a with
		| (b, n, arg1, arg2, l, exp) -> TestManager.doTest n ((slice l arg1 arg2 = exp) = b)
	in

	TestManager.startChallenge "18 - slice";
	List.iter apply l;
	TestManager.endChallenge ()
