
module InFibonacciStream =
struct
  type t = int list

  let init () = [1; 1]

  let update li = match li with
    | x :: y :: _ -> (x + y) :: li
    | _           -> failwith "SNH"
end

module FibonacciStream = Streams.MakeStream(InFibonacciStream)

let () =
  print_endline "FibonacciStream";
  let rec print_list li = match li with
    | []      -> ()
    | x :: xs ->
      begin
        print_list xs;
        print_int x;
        print_char ' ';
      end
  in
  print_list (FibonacciStream.get ());
  for i = 2 to 20 do
    print_int @@ List.hd @@ FibonacciStream.next ();
    print_char ' '
  done;
  print_char '\n'
