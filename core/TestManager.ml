
module Out = ANSITerminal

let titleTest = ref None
let id_test = ref 0
let test_succeed = ref 0
let test_failed = ref 0
let li_test_failed = ref []

let startChallenge t =
	titleTest := (Some t);
	id_test := 0;
	test_succeed := 0;
	test_failed := 0;
	li_test_failed := []

let doTest (str:string) (b:bool) =
	id_test := !id_test + 1;
	if b then incr test_succeed
	else
		begin
			incr test_failed;
			li_test_failed := str :: !li_test_failed
		end

let endChallenge () =
	let prefix = match !titleTest with
	| None			-> "No Title"
	| Some title	-> title
	in

	Out.printf [Out.Foreground Out.Cyan; Out.Bold] "==== %-35s ==== " prefix;
	if !test_failed = 0
	then
		begin
			Out.printf [Out.Foreground Out.Green; Out.Bold] " OK (%-2d tests)" !id_test;
			print_newline ()
		end
	else
		begin
			let def_error = [Out.Foreground Out.Red; Out.Bold; Out.Blink] in
			Out.printf def_error " Failed";	print_newline ();
			List.iter (fun str -> Out.printf def_error "\t=> %s\n" str) !li_test_failed
		end
