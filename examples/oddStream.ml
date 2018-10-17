
module InOddStream =
struct
  type t = int
  type out = int

  let init () = 1

  let update (i: int) =
    (i + 2, i + 2)
end

module OddStream = Streams.MakeStream(InOddStream)

let () =
  print_endline "OddStream";
  let ppint i = print_int i; print_char ' ' in
  ppint @@ OddStream.get ();
  for i = 1 to 24 do ppint (OddStream.next ()) done;
  print_char '\n'
