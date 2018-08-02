
let lotto_select size b =
	if b <= 0 then []
	else
		let rec builder size b res =
			if size <= 0 then res
			else builder (size - 1) b ((1 + (Random.int b)) :: res)
		in
		builder size b []

let test () =
	let l1 = ("3 on 30", 3, 49) in
	let l2 = ("3 on 60", 5, 50) in
	let l3 = ("3 on 10", 9, 2) in
	let l = [l1; l2; l3] in
	let apply a = match a with
		| (n, arg1, arg2) ->
			begin
				let ans = lotto_select arg1 arg2 in
				let b = ref true in
				let f = (fun i -> if i < 0 || i > arg2 then b := false) in
				List.iter f ans;
				if (List.length ans <> arg1) then b := false;
				TestManager.doTest n !b
			end
	in

	TestManager.startChallenge "24 - lotto_select";
	List.iter apply l;
	TestManager.endChallenge ()
