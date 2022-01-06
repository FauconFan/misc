
let rev_list li =
	let rec core li res = match li with
		| []			-> res
		| head :: tail	-> core tail (head :: res) in
	core li []

let rec gray n =
	if n <= 1 then ["0"; "1"]
	else
		begin
			let prev = gray (n - 1) in
			let rec app li fst res = match li with
				| []			-> rev_list res
				| head :: tail	-> app tail fst ((fst ^ head) :: res) in
			(app prev "0" []) @ (app prev "1" [])
		end

let test () =
	let out1 = ["0"; "1"] in
	let out2 = ["00"; "01"; "10"; "11"] in
	let out3 = ["000"; "001"; "010"; "011"; "100"; "101"; "110"; "111"] in
	let out4 = ["0000"; "0001"; "0010"; "0011"; "0100"; "0101"; "0110"; "0111"; "1000"; "1001"; "1010"; "1011"; "1100"; "1101"; "1110"; "1111"] in
	TestManager.startChallenge "49 - gray";
	TestManager.doTest "1" (gray 1 = out1);
	TestManager.doTest "2" (gray 2 = out2);
	TestManager.doTest "3" (gray 3 = out3);
	TestManager.doTest "4" (gray 4 = out4);
	TestManager.endChallenge ()
