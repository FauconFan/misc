
let rec last_two li = match li with
	| []				-> None
	| [_]				-> None
	| fs :: [snd]		-> Some (fs, snd);
	| _ :: tail			-> last_two tail

let test () =
	let l1 = [] in
	let l2 = [2] in
	let l3 = [1; 2; 3; 4; 5] in
	let l4 = [42; 38] in
	let l5 = [26; 46; 34; 28] in
	let l6 = [26; 46; 34; 28; 27] in

	TestManager.startChallenge "02 - last_two";
	TestManager.doTest "Empty List" (last_two l1 = None);
	TestManager.doTest "Singleton" (last_two l2 = None);
	TestManager.doTest "Incr List" (last_two l3 = Some (4, 5));
	TestManager.doTest "Pair" (last_two l4 = Some (42, 38));
	TestManager.doTest "Even List" (last_two l5 = Some (34, 28));
	TestManager.doTest "Odd List" (last_two l6 = Some (28, 27));
	TestManager.endChallenge ()
