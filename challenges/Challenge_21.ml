
let rec insert_at elem n li =
	if n <= 0 then elem :: li
	else match li with
		| []			-> [elem]
		| head :: tail	-> head :: (insert_at elem (n - 1) tail)


let test () =
	let l1 = (true, "Empty", 'a', 3, [], ['a']) in
	let l2 = (true, "Singleton-1", 'b', (-1), ['c'], ['b'; 'c']) in
	let l3 = (true, "Singleton0", 'c', 0, ['d'], ['c'; 'd']) in
	let l4 = (true, "Singleton1", 'c', 1, ['d'], ['d'; 'c']) in
	let l5 = (true, "One", 'u', 1, ['1'; '2'; '3'; '4'], ['1'; 'u'; '2'; '3'; '4']) in
	let l = [l1; l2; l3; l4; l5] in
	let apply a = match a with
		| (b, n, elem, rank, l, exp) -> TestManager.doTest n ((insert_at elem rank l = exp) = b)
	in

	TestManager.startChallenge "21 - insert_at";
	List.iter apply l;
	TestManager.endChallenge ()
