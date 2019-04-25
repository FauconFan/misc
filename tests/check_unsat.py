#!/usr/bin/python3

import sys

def main():
    if (len(sys.argv)) is not 3:
        print("Run this program with a input file and output file")
        print("./check_unsat.py fail1.cnf <(./sat dpll fail1.cnf)")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    lines = []

    with open(output_file, "r") as f:
        lines = f.readlines()
    b = len(lines) == 1 and (lines[0] == "UNSAT" or lines[0] == "UNSAT\n")
    print(b, input_file)
    if b is False:
        sys.exit(1)
    sys.exit(0)

if __name__ == "__main__":
    main()