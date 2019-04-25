#!/usr/bin/python3

## This is a python script file to generate a .travis.yml file according to some contents.
## To update the .travis.yml file, you just have to run python3 .travis_gen.py > .travis.yml

LANG = "C"
DIST = "xenial"

J_BASE = "Base"
J_LINT = "Lint"
J_TEST = "Test"
J_BENCH = "Benchmark"
JOBS = [J_BASE, J_LINT, J_TEST, J_BENCH]

# There are 2 stages,
#   - Base tests the global tests, and do some tests to prevent human errors when filling files.mk for example.
#       Linters needs files.mk to have the right filenames.
#   - Lint tests running some external tools according to filenames.

# Base is a stage that test the following things
#  - it tests if the .travis.yml file was modified directly without modifying this script.
#       We want here to modify this script instead of the .travis.yml file
#  - it tests if the project compile

BASE_TASKS = [
    (J_BASE, "verifying travis.yml file", [], ["python3 .travis_gen.py > expected.out", "diff .travis.yml expected.out"]),
    (J_BASE, "compile libsat", [], ["make -C libsat"]),
    (J_BASE, "compile libsat fast", [], ["make -C libsat fast"]),
    (J_BASE, "compile sat", [], ["make -C sat"]),
    (J_BASE, "compile sat fast", [], ["make -C sat fast"]),
]

# Lint is a stage that test the project using some external tools
#  - uncrustify, checks if the code respects the norm definned in the UNCRUSTIFY.cfg file
#  - cpplint, cppcheck, clang-tidy, infer, checks leaks, known errors and undefined behaviours

LINT_TASKS = [
    (J_LINT, "uncrustify", [], ["make uncrustify_check"]),
    (J_LINT, "cpplint", ["python3-venv"], ["make cpplint_run"]),
    (J_LINT, "cppcheck", ["cppcheck"], ["make cppcheck_run"]),
    (J_LINT, "clang-tidy", ["clang-tidy-6.0", "clang-6.0"], ["travis_retry make clang_tidy_run"]),
]

# Test is a stage that test the project using the ./check_sat.py

TEST_TASKS = []

SAT = 0
UNSAT = 1

SAT_DPLL =[
                ("RND3SAT 01 - 09", [
                    ("_01_RND3SAT__uf20-91", SAT),
                    ("_02_RND3SAT__uf50-218", SAT),
                    ("_03_RND3SAT__uuf50-218", UNSAT),
                    ("_04_RND3SAT__uf75-325", SAT),
                    ("_05_RND3SAT__uuf75-325", UNSAT),
                    ("_06_RND3SAT__uf100-430", SAT),
                    ("_07_RND3SAT__uuf100-430", UNSAT),
                    ("_08_RND3SAT__uf125-538", SAT),
                    ("_09_RND3SAT__uuf125-538", UNSAT),
                ]),
            ]

# FOLDERS_SAT_DPLL = ["_01_RND3SAT__uf20-91",
#                     "_02_RND3SAT__uf50-218",
#                     "_04_RND3SAT__uf75-325",
#                     "_06_RND3SAT__uf100-430"]

def build_command(is_sat, folder):
    rule = "test_sat" if is_sat == SAT else "test_unsat"
    return ("make -C tests " + rule + " FOLDER_CNFS=../input_files/satlib/" + folder)

for (name, li) in SAT_DPLL:
    name = "sat dpll " + name
    li_tasks = ["make satlib_bench"]
    for (folder, is_sat) in li:
        li_tasks.append(build_command(is_sat, folder))

    TEST_TASKS.append((J_TEST, name, [], li_tasks))

# Bench is a stage when we run bench with examples, without verifying

CMDS_QUEENS = ["make -C sat fast"]

for i in range(1, 21 + 1):
    CMDS_QUEENS.append("time (echo " + str(i) + " | sat/sat queens)")

BENCH_TASKS = [
    (J_BENCH, "queens", [], CMDS_QUEENS)
]

INSTALL_APT_PREFIX = "sudo apt-get install -y --no-install-recommends"

TASKS = BASE_TASKS + LINT_TASKS + TEST_TASKS + BENCH_TASKS

def print_header():
    print("language:", LANG)
    print("dist:", DIST)
    print()
    print("stages:")
    for job in JOBS:
        print("  -", job)
    print()

def print_dep(apt_deps):
    if len(apt_deps) is not 0:
        print("      before_install: sudo apt-get update")
        print("      install:")
        print("        -", INSTALL_APT_PREFIX + " " + " ".join(apt_deps))

def print_task(task):
    (stage, name, dep, cmds) = task
    print("    - name:", name)
    print("      stage:", stage)
    print_dep(dep)
    print("      script:")
    for cmd in cmds:
        print("        -", cmd)

def main():
    print_header()
    print("matrix:")
    print("  include:")
    for task in TASKS:
        print_task(task)

if __name__ == "__main__":
    main()
