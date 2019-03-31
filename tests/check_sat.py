#!/usr/bin/python3

import sys

def read_input(input_file):
    fnc = []
    clause = []
    lines = []
    with open(input_file, "r") as f:
        lines = f.readlines()
    lines = [line.replace("\n", "") for line in lines]
    lines = list(filter(lambda st : not st.startswith("c"), lines))
    assert lines[0].startswith("p cnf")
    lines = lines[1:]
    brut = []
    for line in lines:
        for st in line.split(" "):
            if st != "" and st != "%":
                brut.append(int(st))
    for integer in brut:
        if integer is 0:
            if len(clause) is not 0:
                fnc.append(clause)
                clause = []
        else:
            clause.append(integer)
    if len(clause) is not 0:
        fnc.append(clause)
    print(fnc)
    return fnc

def read_output(output_file):
    lines = []
    with open(output_file, "r") as f:
        lines = f.readlines()
    lines = [line.replace("\n", "") for line in lines]
    assert len(lines) == 2
    assert lines[0] == "SAT"
    distrib = [int(num) for num in lines[1].split(" ")]
    return (distrib)

def verify_distrib(fnc, distrib):
    for clause in fnc:
        # print(clause)
        b = False
        for value in distrib:
            # print(value)
            if value in clause:
                b = True
                break
        if b is False:
            return False
    return True

def main():
    if (len(sys.argv)) is not 3:
        print("Run this program with a input file and an output file")
        print("./check_sat.py sample1.cnf <(./sat sample1.cnf)")
        sys.exit(1)
    
    input_file = sys.argv[1]
    output_file = sys.argv[2]

    fnc = read_input(input_file)
    distrib = read_output(output_file)

    b = verify_distrib(fnc, distrib)
    print(b)
    if b is False:
        sys.exit(1)
    sys.exit(0)

if __name__ == "__main__":
    main()