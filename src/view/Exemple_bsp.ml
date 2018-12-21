open Base
open Graphics

let exemple_cours =
  L (
    {coord = 545; color = None},
    L(
      {coord = 760; color = None},
      L(
        {coord = 200; color = None},
        R None,
        R (Some(blue))
      ),
      L(
        {coord = 125; color = None},
        R (Some(blue)),
        R None
      )
    ),
    L(
      {coord = 345; color = None},
      L(
        {coord = 750; color = None},
        R None,
        R None
      ),
      L(
        {coord = 600; color = None},
        R None,
        L(
          {coord = 500; color = None},
          R None,
          R None
        )
      )
    )
  )

let exemple1 =
  L (
    {coord = 300; color = Some blue},
    L(
      {coord = 200; color = Some magenta},
      L(
        {coord = 150; color = Some blue},
        R (None),
        R (None)
      ),
      L(
        {coord = 100; color = None},
        R (None),
        R (None)
      )
    ),
    L(
      {coord = 600; color = Some red},
      L(
        {coord = 750; color = Some blue},
        R (None),
        R (None)
      ),
      L(
        {coord = 500; color = None},
        L(
          {coord = 850; color = None},
          R None,
          R None
        ),
        L(
          {coord = 800; color = Some blue},
          R None,
          R None
        )
      )
    )
  )

let simple =
  L (
    {coord = 500; color = Some blue},
    L (
      {coord = 100; color = Some red},
      R None,
      R None
    ),
    L (
      {coord = 600; color = None},
      R None,
      R None
    )
    (* R None, *)
    (* R None *)
  )
