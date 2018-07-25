
let rec last li = match li with
	| []			-> None
	| [head]		-> Some head
	| _ :: tail		-> last tail

let test () =
	let l1 = [] in
	let l2 = [2] in
	let l3 = [1; 2; 3; 4; 5] in

	TestManager.changeTitle "01 - last";
	TestManager.doTest "Empty List" (last l1 = None);
	TestManager.doTest "Singleton" (last l2 = Some 2);
	TestManager.doTest "Incr List" (last l3 = Some 5)
