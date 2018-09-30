
let drop li n =
	let rec rec_drop li n actu = match li with
		| []				-> []
		| head :: tail		-> if actu mod n = 0 then rec_drop tail n (actu + 1)
								else head :: (rec_drop tail n (actu + 1))
	in
	rec_drop li n 1


let test () =
  let list_init len f =
    let rec core i ma f =
      if i >= ma then []
      else (f i) :: (core (i + 1) ma f) in
    core 0 len f in
	let l1 = (true, "Empty", 3, [], []) in
	let l2 = (true, "Singleton", 1, [2], []) in
	let l3 = (true, "Singleton3", 3, [2], [2]) in
	let l4 = (true, "onTwo", 2, [2; 3], [2]) in
	let l5 = (true, "onThree", 3, [2; 3], [2; 3]) in
	let l6 = (true, "onOne", 1, (list_init 4200 (fun i -> i)), []) in
	let l7 = (false, "onOneFail", 1, (list_init 4200 (fun i -> i)), [1]) in
	let l = [l1; l2; l3; l4; l5; l6; l7] in
	let apply a = match a with
		| (b, n, arg, l, exp) -> TestManager.doTest n ((drop l arg = exp) = b)
	in

	TestManager.startChallenge "16 - drop";
	List.iter apply l;
	TestManager.endChallenge ()
