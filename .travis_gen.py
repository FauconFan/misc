#!/usr/bin/python3

## This is a python script file to generate a .travis.yml file according to some contents.
## To update the .travis.yml file, you just have to run python3 .travis_gen.py > .travis.yml

LANG = "cpp"
DIST = "xenial"
COMPILER = "clang"

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
                    # ("_10_RND3SAT__uf150-645", SAT),
                    # ("_11_RND3SAT__uuf150-645", UNSAT),
                    # ("_12_RND3SAT__uf175-753", SAT),
                    # ("_13_RND3SAT__uuf175-753", UNSAT),
                    # ("_14_RND3SAT__uf200-860", SAT),
                    # ("_15_RND3SAT__uuf200-860", UNSAT),
                    # ("_16_RND3SAT__uf225-960", SAT),
                    # ("_17_RND3SAT__uuf225-960", UNSAT),
                    # ("_18_RND3SAT__uf250-1065", SAT),
                    # ("_19_RND3SAT__uuf250-1065", UNSAT),
                ]),
                ("BMS 20 - 21", [
                    ("_20_BMS__RTI_k3_n100_m429", SAT),
                    ("_21_BMS__BMS_k3_n100_m429", SAT),
                ]),
                ("CBS 22 - 31", [
                    ("_22_CBS__CBS_k3_n100_m403_b10", SAT),
                    ("_23_CBS__CBS_k3_n100_m403_b30", SAT),
                    ("_24_CBS__CBS_k3_n100_m403_b50", SAT),
                    ("_25_CBS__CBS_k3_n100_m403_b70", SAT),
                    ("_26_CBS__CBS_k3_n100_m403_b90", SAT),
                    ("_27_CBS__CBS_k3_n100_m411_b10", SAT),
                    ("_28_CBS__CBS_k3_n100_m411_b30", SAT),
                    ("_29_CBS__CBS_k3_n100_m411_b50", SAT),
                    ("_30_CBS__CBS_k3_n100_m411_b70", SAT),
                    ("_31_CBS__CBS_k3_n100_m411_b90", SAT),
                ]),
                ("CBS 32 - 41", [
                    ("_32_CBS__CBS_k3_n100_m418_b10", SAT),
                    ("_33_CBS__CBS_k3_n100_m418_b30", SAT),
                    ("_34_CBS__CBS_k3_n100_m418_b50", SAT),
                    ("_35_CBS__CBS_k3_n100_m418_b70", SAT),
                    ("_36_CBS__CBS_k3_n100_m418_b90", SAT),
                    ("_37_CBS__CBS_k3_n100_m423_b10", SAT),
                    ("_38_CBS__CBS_k3_n100_m423_b30", SAT),
                    ("_39_CBS__CBS_k3_n100_m423_b50", SAT),
                    ("_40_CBS__CBS_k3_n100_m423_b70", SAT),
                    ("_41_CBS__CBS_k3_n100_m423_b90", SAT),
                ]),
                ("CBS 42 - 51", [
                    ("_42_CBS__CBS_k3_n100_m429_b10", SAT),
                    ("_43_CBS__CBS_k3_n100_m429_b30", SAT),
                    ("_44_CBS__CBS_k3_n100_m429_b50", SAT),
                    ("_45_CBS__CBS_k3_n100_m429_b70", SAT),
                    ("_46_CBS__CBS_k3_n100_m429_b90", SAT),
                    ("_47_CBS__CBS_k3_n100_m435_b10", SAT),
                    ("_48_CBS__CBS_k3_n100_m435_b30", SAT),
                    ("_49_CBS__CBS_k3_n100_m435_b50", SAT),
                    ("_50_CBS__CBS_k3_n100_m435_b70", SAT),
                    ("_51_CBS__CBS_k3_n100_m435_b90", SAT),
                ]),
                ("CBS 52 - 61", [
                    ("_52_CBS__CBS_k3_n100_m441_b10", SAT),
                    ("_53_CBS__CBS_k3_n100_m441_b30", SAT),
                    ("_54_CBS__CBS_k3_n100_m441_b50", SAT),
                    ("_55_CBS__CBS_k3_n100_m441_b70", SAT),
                    ("_56_CBS__CBS_k3_n100_m441_b90", SAT),
                    ("_57_CBS__CBS_k3_n100_m449_b10", SAT),
                    ("_58_CBS__CBS_k3_n100_m449_b30", SAT),
                    ("_59_CBS__CBS_k3_n100_m449_b50", SAT),
                    ("_60_CBS__CBS_k3_n100_m449_b70", SAT),
                    ("_61_CBS__CBS_k3_n100_m449_b90", SAT),
                ]),
                # ("GCP 62 - 69", [
                #     ("_62_GCP__flat30-60", SAT),
                #     ("_63_GCP__flat50-115", SAT),
                #     ("_64_GCP__flat75-180", SAT),
                #     ("_65_GCP__flat100-239", SAT),
                #     ("_66_GCP__flat125-301", SAT),
                #     ("_67_GCP__flat150-360", SAT),
                #     ("_68_GCP__flat175-417", SAT),
                #     ("_69_GCP__flat200-479", SAT),
                #     ("_70_SW-GCP__sw100-8-lp0-c5", SAT),
                #     ("_71_SW-GCP__sw100-8-lp1-c5", SAT),
                #     ("_72_SW-GCP__sw100-8-lp2-c5", SAT),
                #     ("_73_SW-GCP__sw100-8-lp3-c5", SAT),
                #     ("_74_SW-GCP__sw100-8-lp4-c5", SAT),
                #     ("_75_SW-GCP__sw100-8-lp5-c5", SAT),
                #     ("_76_SW-GCP__sw100-8-lp6-c5", SAT),
                #     ("_77_SW-GCP__sw100-8-lp7-c5", SAT),
                #     ("_78_SW-GCP__sw100-8-lp8-c5", SAT),
                #     ("_79_SW-GCP__sw100-8-p0-c5", SAT),
                # ]),
            ]

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
    print("compiler:", COMPILER)
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
