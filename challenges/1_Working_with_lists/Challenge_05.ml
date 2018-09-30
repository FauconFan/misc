
let rev li =
	let rec rev_tail_recu li res = match li with
		| []				-> res
		| head :: tail		-> rev_tail_recu tail (head :: res)
	in rev_tail_recu li []

let test () =
  let list_init len f =
    let rec core i ma f =
      if i >= ma then []
      else (f i) :: (core (i + 1) ma f) in
    core 0 len f in
	let l1 = ("Empty", []) in
	let l2 = ("Singleton", [2]) in
	let l3 = ("42", (list_init 42 (fun i -> i))) in
	let l4 = ("42000", (list_init 42000 (fun i -> i))) in
	let l = [l1; l2; l3; l4] in
	let apply a =
		let n = fst a in
		let l = snd a in
		TestManager.doTest n (rev l = List.rev l)
	in

	TestManager.startChallenge "05 - rev";
	List.iter apply l;
	TestManager.endChallenge ()
