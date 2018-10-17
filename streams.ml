
module type InStream = sig
  type t

  val init : unit -> t
  val update : t -> t
end

module type Stream = sig
  type t

  val get : unit -> t
  val next : unit -> t
end

module type MAKESTREAM = functor (In : InStream) -> (Stream with type t = In.t)

module MakeStream (In : InStream) : (Stream with type t = In.t) =
struct
  type t = In.t

  let value = ref (In.init ())

  let get () =
    !value

  let next () =
    let (value_tmp) = In.update (!value) in
    value := value_tmp;
    value_tmp
end
