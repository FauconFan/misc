
#                                    /@
#                     __        __   /\/
#                    /==\      /  \_/\/   
#                  /======\    \/\__ \__
#                /==/\  /\==\    /\_|__ \
#             /==/    ||    \=\ / / / /_/
#           /=/    /\ || /\   \=\/ /     
#        /===/   /   \||/   \   \===\
#      /===/   /_________________ \===\
#   /====/   / |                /  \====\
# /====/   /   |  _________    /  \   \===\    THE LEGEND OF 
# /==/   /     | /   /  \ / / /  __________\_____      ______       ___
#|===| /       |/   /____/ / /   \   _____ |\   /      \   _ \      \  \
# \==\             /\   / / /     | |  /= \| | |        | | \ \     / _ \
# \===\__    \    /  \ / / /   /  | | /===/  | |        | |  \ \   / / \ \
#   \==\ \    \\ /____/   /_\ //  | |_____/| | |        | |   | | / /___\ \
#   \===\ \   \\\\\\\/   /////// /|  _____ | | |        | |   | | |  ___  |
#     \==\/     \\\\/ / //////   \| |/==/ \| | |        | |   | | | /   \ |
#     \==\     _ \\/ / /////    _ | |==/     | |        | |  / /  | |   | |
#       \==\  / \ / / ///      /|\| |_____/| | |_____/| | |_/ /   | |   | |
#       \==\ /   / / /________/ |/_________|/_________|/_____/   /___\ /___\
#         \==\  /               | /==/
#         \=\  /________________|/=/    OCARINA OF TIME
#           \==\     _____     /==/ 
#          / \===\   \   /   /===/
#         / / /\===\  \_/  /===/
#        / / /   \====\ /====/
#       / / /      \===|===/
#       |/_/         \===/
#                      =

PATH_SATLIB_DL_SH = input_files/satlib_dl.bash

.PHONY: satlib_bench
satlib_bench:
	bash $(PATH_SATLIB_DL_SH)

.PHONY: clean
clean:
	make -C clean libsat
	make -C clean sat

.PHONY: fclean
fclean:
	make -C fclean libsat
	make -C fclean sat

###################################### VENV ####################################

venv:
	python3 -m venv venv
	venv/bin/pip3 install pip --upgrade
	venv/bin/pip3 install cpplint

###################################### SUBMODULES ##############################

.PHONY: submodule
submodule:
	git submodule init
	git submodule update

###################################### UTILS ###################################
## This part is for continuous integration, testing, linting, etc...

SRC_FILES = $(shell find sat libsat -name "*.cpp")
ALL_FILES = $(shell find sat libsat -name "*.hpp") $(SRC_FILES)
IFLAGS = -I sat -I libsat

UNCRUSTIFY = uncrustify/build/uncrustify
CPPLINT = venv/bin/cpplint
CPPCHECK = cppcheck
CLANG_TIDY = clang-tidy-6.0
INFER = /usr/local/bin/infer

.PHONY: lint_apply
lint_apply: uncrustify_apply clang_tidy_fix

.PHONY: lint_check
lint_check: uncrustify_check cpplint_run cppcheck_run clang_tidy_run infer_run

###################################### UNCRUSTIFY ##############################

CONFIG_UNCRUSTIFY = UNCRUSTIFY.cfg

$(UNCRUSTIFY): submodule
	mkdir -p uncrustify/build
	(cd uncrustify/build && cmake ..)
	make -C uncrustify/build -j8

.PHONY: uncrustify_apply
uncrustify_apply: $(UNCRUSTIFY)
	$(UNCRUSTIFY) -c $(CONFIG_UNCRUSTIFY) --replace --no-backup --mtime $(ALL_FILES)

.PHONY: uncrustify_check
uncrustify_check: $(UNCRUSTIFY)
	$(UNCRUSTIFY) -c $(CONFIG_UNCRUSTIFY) --check $(ALL_FILES)

###################################### CPPLINT #################################

.PHONY: cpplint_run
cpplint_run: venv
	$(CPPLINT) $(ALL_FILES)

##################################### CPPCHECK #################################

.PHONY: cppcheck_run
cppcheck_run:
	$(CPPCHECK) --error-exitcode=1 --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction $(IFLAGS) $(SRC_FILES)

##################################### CLANG_TIDY ###############################

.PHONY: clang_tidy_run
clang_tidy_run:
	$(CLANG_TIDY) \
		-checks="*,-llvm-header-guard,-google-readability-braces-around-statements,-hicpp-braces-around-statements,-hicpp-signed-bitwise,-readability-braces-around-statements" \
		-warnings-as-errors="*" \
		$(SRC_FILES) -- $(IFLAGS) \

.PHONY: clang_tidy_fix
clang_tidy_fix:
	$(CLANG_TIDY) \
		-checks="*,-llvm-header-guard,-google-readability-braces-around-statements,-hicpp-braces-around-statements,-hicpp-signed-bitwise,-readability-braces-around-statements" \
		-header-filter=".*" \
		-fix-errors \
		$(SRC_FILES) -- $(IFLAGS) \