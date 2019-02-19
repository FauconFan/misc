#!/usr/bin/python3

## This is a python script file to generate a .travis.yml file according to some contents.
## To update the .travis.yml file, you just have to run python3 .travis_gen.py > .travis.yml

LANG = "C"
DIST = "xenial"

J_BASE = "Base"
J_LINT = "Lint"
J_TEST = "Test"
JOBS = [J_BASE, J_LINT, J_TEST]

# Base is a job that test the following things
#  - it tests if the .travis.yml file was modified directly without modifying this script.
#       We want here to modify this script instead of the .travis.yml file
#  - it tests if the project compile
#  - it tests if no c file is missing in Makefile (*.c in src)
#  - it tests if no header file is missing in Makefile (*.h in inc)

BASE_TASKS = [
    (J_BASE, "verifying travis.yml file", None, ["python3 .travis_gen.py > expected.out", "diff .travis.yml expected.out"]),
    # (J_BASE, "test project compile", (None, True), ["make"]),
    (J_BASE, "all C files in Makefile", None, ["diff <(make print-SRC | tr ' ' '\\n' | sort) <(find src -name \"*.c\" | sort)"]),
    (J_BASE, "all headers files in Makefile", None, ["diff <(make print-INC | tr ' ' '\\n' | sort) <(find inc -name \"*.h\" | sort)"]),
]

LINT_TASKS = [
    (J_LINT, "uncrustify", None, ["make uncrustify_check"]),
    (J_LINT, "cpplint", (["python3-venv"], False), ["make cpplint_run"]),
    (J_LINT, "cppcheck", (["cppcheck"], False), ["make cppcheck_run"]),
    (J_LINT, "clang-tidy", (["clang-tidy-6.0"], False), ["make clang_tidy_run"]),
    (J_LINT, "infer", None, ["make infer_run"]),
]

INSTALL_SDL = "travis_retry curl -L https://www.libsdl.org/release/SDL2-2.0.9.tar.gz | tar xz; cd SDL2-2.0.9; ./configure; make; sudo make install; cd ..; rm -rf SDL2-2.0.9"
INSTALL_APT_PREFIX = "sudo apt-get install -y --no-install-recommends"

TASKS = BASE_TASKS + LINT_TASKS

print("language:", LANG)
print("dist:", DIST)
print()
print("stages:")
for job in JOBS:
    print("  -", job)
print()

print("jobs:")
print("  include:")
for (stage, name, dep, cmds) in TASKS:
    print("    - name:", name)
    print("      stage:", stage)
    if dep is not None:
        (apt_deps, b_install_sdl) = dep
        install_apt_cmd = None
        if apt_deps is not None:
            print("      before_install: sudo apt-get update")
            install_apt_cmd = INSTALL_APT_PREFIX + " " + " ".join(apt_deps)
        if install_apt_cmd is not None or b_install_sdl:
            print("      install:")
            if install_apt_cmd is not None:
                print("        -", install_apt_cmd)
            if b_install_sdl:
                print("        -", INSTALL_SDL)
    print("      script:")
    for cmd in cmds:
        print("        -", cmd)