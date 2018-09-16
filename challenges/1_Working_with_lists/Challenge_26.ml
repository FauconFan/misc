
let extract n l =
	if n <= 0 then []
	else
		begin
			let rev_list li =
				let rec loop li res = match li with
					| []			->	res
					| head :: tail	->	loop tail (head :: res) in
				loop li [] in
			let rec len_list li = match li with
					| []			->	0
					| _ :: tail		->	1 + (len_list tail) in
			let rec loop n li len res_final res_tmp =
				if n == 0 then (rev_list res_tmp) :: res_final
				else if len <= 0 || n > len then res_final
				else
					match li with
						| []			->  failwith "SNH"
						| head :: tail	->
							let res_with = loop (n - 1) tail (len - 1) res_final (head :: res_tmp) in
							loop n tail (len - 1) res_with res_tmp
			in
			let rev_res = loop n l (len_list l) [] [] in
			rev_list rev_res
		end

let test () =
	let out = [["a"; "b"]; ["a"; "c"]; ["a"; "d"]; ["b"; "c"]; ["b"; "d"]; ["c"; "d"]] in
	TestManager.startChallenge "26 - extract";
	TestManager.doTest "Simple" ((extract 2 ["a"; "b"; "c"; "d"]) = out);
	TestManager.endChallenge ()
