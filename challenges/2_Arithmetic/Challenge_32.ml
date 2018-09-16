
let gcd n m =
	let rec loop n m =
		if n = 0 then m
		else loop (m mod n) n in
	if n < 0 || m < 0 then 0
	else loop n m

let test () =
	TestManager.startChallenge "32 - gcd";
	TestManager.doTest "13 27" (gcd 13 27 = 1);
	TestManager.doTest "20536 7826" (gcd 20536 7826 = 2);
	TestManager.endChallenge ()
