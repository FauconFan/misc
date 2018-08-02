
let rec rand_select l n =
	let rec extract_elem l n = match l with
		| []				-> failwith "should never happened"
		| head :: tail		-> if n = 0 then (head, tail)
							else let res = extract_elem tail (n - 1) in
								(fst res, head :: (snd res))
	in
	let rec length l = match l with
		| []				-> 0
		| _ :: tail			-> 1 + (length tail)
	in
	if n <= 0 then []
	else if n >= length l then l
	else
	 	let tmp = extract_elem l (Random.int n) in
		(fst tmp) :: (rand_select (snd tmp) (n - 1))


let test () =
	let l1 = ("3 on 30", 3, List.init 30 (fun i -> i - 3)) in
	let l2 = ("3 on 60", 3, List.init 60 (fun i -> i * 3)) in
	let l3 = ("3 on 10", 3, List.init 10 (fun i -> i + 3)) in
	let l = [l1; l2; l3] in
	let apply a = match a with
		| (n, arg1, l) ->
			begin
				let ans = rand_select l arg1 in
				let b = ref true in
				let f = (fun i -> if List.for_all (fun j -> j <> i) l then b := false) in
				List.iter f ans;
				if (List.length ans <> arg1) then b := false;
				TestManager.doTest n !b
			end
	in

	TestManager.startChallenge "23 - rand_select";
	List.iter apply l;
	TestManager.endChallenge ()
