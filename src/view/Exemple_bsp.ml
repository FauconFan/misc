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
    {coord = 300; color = None},
    L(
      {coord = 200; color = None},
        L(
          {coord = 150; color = None},
          R (Some(red)),
          R (Some(blue))
          ),
          L(
            {coord = 100; color = None},
            R (Some(red)),
            R (Some(red))
          )
        ),
        L(
          {coord = 600; color = None},
          L(
            {coord = 750; color = None},
            R (Some(blue)),
            R (Some(blue))
          ),
          L(
            {coord = 500; color = None},
            R None,
            L(
              {coord = 800; color = None},
              R None,
              R None
            )
          )
        )
      )

let simple =
  L (
    {coord = 500; color = Some red},
    R None,
    R None
  )
