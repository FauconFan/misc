
module InStringStream =
struct
  type t = string
  type out = string option

  let init () = "My name is Joseph."

  let update (str: string) =
    let str = String.trim str in
    try
      begin
        let index = String.index str ' ' in
        let new_str = String.sub str (index + 1) ((String.length str) - index - 1) in
        let res = String.sub str 0 index in
        (new_str, Some res)
      end
    with Not_found ->
      begin
        if String.length str > 0 then ("", Some (str))
        else (str, None)
      end
end

module StringStream = Streams.MakeStream(InStringStream)

let () =
  print_endline "StringStream";
  for i = 0 to 5 do
    match StringStream.next () with
    | Some res ->
      begin
        print_string res; print_char ' '
      end
    | None ->
      begin
        print_string "None"
      end
  done;
  print_char '\n'
