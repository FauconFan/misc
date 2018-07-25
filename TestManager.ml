
module Out = ANSITerminal

let titleTest = ref None
let id_test = ref 1

let printTitle () =
	let text = match !titleTest with
	| None		-> "Title Not Set"
	| Some s	-> s
	in
	Out.print_string [Out.Foreground Out.Cyan] "===== ";
	Out.print_string [Out.Foreground Out.Cyan; Out.Bold] text;
	Out.print_string [Out.Foreground Out.Cyan] " =====\n"

let changeTitle t =
	if not (!titleTest = None) then print_newline ();
	titleTest := (Some t);
	id_test := 1;
	printTitle ()

let doTest (str:string) (b:bool) =
	Out.printf [Out.Foreground Out.Cyan; Out.Bold] "%3d" !id_test;
	Printf.printf "  %15s\t=> " str;
	if b
	then Out.print_string [Out.Foreground Out.Green] "OK"
	else Out.print_string [Out.Foreground Out.Red; Out.Blink] "Failed";
	print_char '\n';
	id_test := !id_test + 1
