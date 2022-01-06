#!/usr/bin/python3

import argparse

from src.Data import Data

learning_rate = 0.1

def train(li):
    t0 = 0
    t1 = 0
    m = len(li)
    while True:
        tmpt0 = 0
        tmpt1 = 0
        for (x, y) in li:
            tmpt0 = tmpt0 + ((t0 + t1 * x) - y)
            tmpt1 = tmpt1 + (((t0 + t1 * x) - y) * x)
        tmpt0 = learning_rate * (1.0 / m) * tmpt0
        tmpt1 = learning_rate * (1.0 / m) * tmpt1
        t0 = t0 - tmpt0
        t1 = t1 - tmpt1
        print(tmpt0, tmpt1)
        if (abs(tmpt0) + abs(tmpt1) < 1e-10):
            break
    return (t0, t1)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("file", help="pathfile of the data")
    args = parser.parse_args()

    data = Data(args.file)
    for d in data.contents:
        print(d)
    data.normalise()
    (t0, t1) = train(data.contents)
    print("t0 t1", t0, t1)
    for (x, y) in data.contents:
        cand = t0 + t1 * x
        print(x, cand, y, abs(y - cand))
    (t0, t1) = data.getnormedt0t1(t0, t1)
    print(t0, t1)
    data.unnormalise()

if __name__ == "__main__":
    main()
