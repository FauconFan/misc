
let range b1 b2 =
	let get_next = if b1 <= b2 then (fun i -> i + 1)
					else (fun i -> i - 1)
	in
	let rec builder actu ma f =
		if actu = ma then [actu]
		else actu :: (builder (f actu) ma f)
	in
	builder b1 b2 get_next


let test () =
	let l1 = (true, "3 - 5", 3, 5, List.init 3 (fun i -> i + 3)) in
	let l2 = (true, "3 - 8", 3, 8, List.init 6 (fun i -> i + 3)) in
	let l3 = (true, "3 - 3", 3, 3, List.init 1 (fun i -> i + 3)) in
	let l4 = (true, "3 - 42002", 3, 42002, List.init 42000 (fun i -> i + 3)) in
	let l5 = (true, "42002 - 3", 42002, 3, List.init 42000 (fun i -> 42002 - i)) in
	let l = [l1; l2; l3; l4; l5] in
	let apply a = match a with
		| (b, n, arg1, arg2, exp) -> TestManager.doTest n ((range arg1 arg2 = exp) = b)
	in

	TestManager.startChallenge "22 - range";
	List.iter apply l;
	TestManager.endChallenge ()
