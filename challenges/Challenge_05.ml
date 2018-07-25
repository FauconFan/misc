
let rec rev li = match li with
	| []				-> []
	| head :: tail		-> (rev tail) @ [head]

let test () =
	let l1 = ("Empty", []) in
	let l2 = ("Singleton", [2]) in
	let l3 = ("42", (List.init 42 (fun i -> i))) in
	let l4 = ("420", (List.init 420 (fun i -> i))) in
	let l = [l1; l2; l3; l4] in
	let apply a =
		let n = fst a in
		let l = snd a in
		TestManager.doTest n (rev l = List.rev l)
	in

	TestManager.changeTitle "05 - rev";
	List.iter apply l
