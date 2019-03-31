#!/usr/bin/python3

## This is a python script file to generate a .travis.yml file according to some contents.
## To update the .travis.yml file, you just have to run python3 .travis_gen.py > .travis.yml

LANG = "C"
DIST = "xenial"

J_BASE = "Base"
J_LINT = "Lint"
J_TEST = "Test"
JOBS = [J_BASE, J_LINT, J_TEST]

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
    (J_BASE, "compile sat", [], ["make -C sat"]),
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

TEST_TASKS = [
    (J_TEST, "check sat dpll", [], ["make satlib_bench", "make -C tests FOLDER_CNFS=../input_files/satlib/_01_RND3SAT__uf20-91"]),
]

INSTALL_APT_PREFIX = "sudo apt-get install -y --no-install-recommends"

TASKS = BASE_TASKS + LINT_TASKS + TEST_TASKS

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