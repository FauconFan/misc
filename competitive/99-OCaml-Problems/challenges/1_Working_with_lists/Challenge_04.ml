
let rec length li = match li with
	| []			-> 0
	| _ :: tail		-> 1 + (length tail)

let test () =
  let list_init len f =
    let rec core i ma f =
      if i >= ma then []
      else (f i) :: (core (i + 1) ma f) in
    core 0 len f in
	let l1 = ("Empty", []) in
	let l2 = ("Singleton", [2]) in
	let l3 = ("42", (list_init 42 (fun _ -> 42))) in
	let l4 = ("420", (list_init 420 (fun _ -> 42))) in
	let l = [l1; l2; l3; l4] in
	let apply a =
		let n = fst a in
		let l = snd a in
		TestManager.doTest n (length l = List.length l)
	in

	TestManager.startChallenge "04 - length";
	List.iter apply l;
	TestManager.endChallenge ()
