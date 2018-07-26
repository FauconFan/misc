
let rec at n li =
	if n < 0 then None
	else
		match li with
		| []			-> None
		| head :: tail	-> if n = 0 then Some head
							else at (n - 1) tail

let test () =
	let empty = [] in
	let singleton = ["oui"] in
	let five = ["zero"; "un"; "deux"; "trois"; "quatre"] in

	TestManager.startChallenge "03 - at";
	TestManager.doTest "Empty List 0" (at 0 empty = None);
	TestManager.doTest "Empty List 1" (at 1 empty = None);
	TestManager.doTest "Empty List 2" (at 2 empty = None);
	TestManager.doTest "Empty List -2" (at (-2) empty = None);
	TestManager.doTest "Singleton 0" (at 0 singleton = Some "oui");
	TestManager.doTest "Singleton 1" (at 1 singleton = None);
	TestManager.doTest "Singleton 2" (at 2 singleton = None);
	TestManager.doTest "Singleton -2" (at (-2) singleton = None);
	TestManager.doTest "Five List 0" (at 0 five = Some "zero");
	TestManager.doTest "Five List 1" (at 1 five = Some "un");
	TestManager.doTest "Five List 2" (at 2 five = Some "deux");
	TestManager.doTest "Five List 4" (at 4 five = Some "quatre");
	TestManager.doTest "Five List 6" (at 6 five = None);
	TestManager.doTest "Five List -2" (at (-2) five = None);
	TestManager.endChallenge ()
