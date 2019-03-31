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

def set_from_fnc(fnc):
    s = set()
    for clause in fnc:
        for value in clause:
            s.add(abs(value))
    return (s)

def set_from_distrib(distrib):
    s = set()
    for i in distrib:
        s.add(abs(i))
    return (s);

def verify_distrib(fnc, distrib):
    for clause in fnc:
        b = False
        for value in distrib:
            if value in clause:
                b = True
                break
        if b is False:
            return False
    return True

def main():
    if (len(sys.argv)) is not 3:
        print("Run this program with a input file and an output file")
        print("./check_sat.py sample1.cnf <(./sat dpll sample1.cnf)")
        sys.exit(1)
    
    input_file = sys.argv[1]
    output_file = sys.argv[2]

    fnc = read_input(input_file)
    distrib = read_output(output_file)

    s_fnc = set_from_fnc(fnc)
    s_dist = set_from_distrib(distrib)

    if (s_fnc != s_dist):
        sys.exit(1)

    b = verify_distrib(fnc, distrib)
    print(b)
    if b is False:
        sys.exit(1)
    sys.exit(0)

if __name__ == "__main__":
    main()