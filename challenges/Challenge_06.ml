
let is_palindrome li =
	let rec length li = match li with
		| []		-> 0
		| _ :: tail	-> 1 + (length tail)
	in
	let len = length li in
	let mid = len / 2 in
	let get_first_part li mid is_odd =
		let rec _get_first_part li mid res is_odd =
			if mid = 0 then
				if is_odd then match li with
					| []				-> failwith "Never happened"
					| _ :: tail			-> (tail, res)
				else (li, res)
			else match li with
				| []			-> failwith "Never happened"
				| head :: tail	-> _get_first_part tail (mid - 1) (head :: res) is_odd
		in
		let res = _get_first_part li mid [] is_odd in
		res
	in
	let final = get_first_part li mid (len mod 2 = 1) in
	(fst final) = (snd final)

let test () =
	let f n = (fun i -> if i < n / 2 then i else n - 1 - i) in
	let l1 = (true, "Empty", []) in
	let l2 = (true, "Singleton", [2]) in
	let l3 = (true, "Pair", [3; 3]) in
	let l4 = (false, "FailPair", [4; 5]) in
	let l5 = (true, "42", (List.init 42 (f 42))) in
	let l6 = (true, "42000", (List.init 42000 (f 42000))) in
	let l7 = (false, "CustomFail", [1; 2; 5; 6; 6; 7; 2; 1]) in
	let l = [l1; l2; l3; l4; l5; l6; l7] in
	let apply a = match a with
		| (b, n, l) -> TestManager.doTest n (is_palindrome l = b)
	in

	TestManager.startChallenge "06 - is_palindrome";
	List.iter apply l;
	TestManager.endChallenge ()
