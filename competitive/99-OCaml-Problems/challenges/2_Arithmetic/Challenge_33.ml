
let gcd n m =
	let rec loop n m =
		if n = 0 then m
		else loop (m mod n) n in
	if n < 0 || m < 0 then 0
	else loop n m

let coprime n m =
	(gcd n m) = 1

let test () =
	TestManager.startChallenge "33 - coprime";
	TestManager.doTest "13 27" (coprime 13 27 = true);
	TestManager.doTest "20536 7826" (coprime 20536 7826 = false);
	TestManager.endChallenge ()
