
module InOddStream =
struct
  type t = int list

  let init () = [1]

  let update (li: int list) =
    ((List.hd li) + 2) :: li
end

module OddStream = Streams.MakeStream(InOddStream)

let () =
  print_endline "OddStream";
  let rec print_list li = match li with
    | []      -> ()
    | x :: xs ->
      begin
        print_list xs;
        print_int x;
        print_char ' ';
      end
  in
  let ppint i = print_int i; print_char ' ' in
  for i = 1 to 24 do ignore(OddStream.next ()) done;
  print_list (OddStream.get ());
  print_char '\n'
