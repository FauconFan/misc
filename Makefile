
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
	make -C libsat clean
	make -C sat clean

.PHONY: fclean
fclean:
	make -C libsat fclean
	make -C sat fclean

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
ALL_FILES = $(shell find sat libsat -name "*.hpp" -o -name "*.tpp") $(SRC_FILES)
IFLAGS = -I sat -I libsat

UNCRUSTIFY = uncrustify/build/uncrustify
CPPLINT = venv/bin/cpplint
CPPCHECK = cppcheck
CLANG_TIDY = clang-tidy-6.0
INFER = /usr/local/bin/infer

.PHONY: lint_apply
lint_apply: uncrustify_apply clang_tidy_fix

.PHONY: lint_check
lint_check: uncrustify_check cpplint_run cppcheck_run clang_tidy_run

###################################### UNCRUSTIFY ##############################

CONFIG_UNCRUSTIFY = UNCRUSTIFY.cfg

$(UNCRUSTIFY): submodule
	mkdir -p uncrustify/build
	(cd uncrustify/build && cmake ..)
	make -C uncrustify/build -j8

.PHONY: uncrustify_apply
uncrustify_apply: $(UNCRUSTIFY)
	$(UNCRUSTIFY) -c $(CONFIG_UNCRUSTIFY) -l CPP --replace --no-backup --mtime $(ALL_FILES)

.PHONY: uncrustify_check
uncrustify_check: $(UNCRUSTIFY)
	$(UNCRUSTIFY) -c $(CONFIG_UNCRUSTIFY) -l CPP --check $(ALL_FILES)

###################################### CPPLINT #################################

.PHONY: cpplint_run
cpplint_run: venv
	$(CPPLINT) $(ALL_FILES)

##################################### CPPCHECK #################################

.PHONY: cppcheck_run
cppcheck_run:
	$(CPPCHECK) --error-exitcode=1 --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction $(IFLAGS) $(SRC_FILES)

##################################### CLANG_TIDY ###############################

WARNS_EXCEPTS = \
				android-cloexec-fopen \
				cppcoreguidelines-owning-memory \
				cppcoreguidelines-special-member-functions \
				cppcoreguidelines-pro-bounds-pointer-arithmetic \
				cppcoreguidelines-pro-bounds-array-to-pointer-decay \
				cppcoreguidelines-pro-bounds-constant-array-index \
				cppcoreguidelines-pro-type-union-access \
				llvm-header-guard \
				llvm-include-order \
				google-readability-braces-around-statements \
				google-readability-namespace-comments \
				google-runtime-references \
				hicpp-braces-around-statements \
				hicpp-signed-bitwise \
				hicpp-special-member-functions \
				hicpp-no-array-decay \
				hicpp-use-emplace \
				readability-braces-around-statements \
				readability-named-parameter \
				readability-delete-null-pointer \
				readability-simplify-boolean-expr \
				fuchsia-overloaded-operator \
				fuchsia-default-arguments \
				modernize-pass-by-value \
				modernize-use-emplace \
				cert-err58-cpp \

WARNS = $(shell echo "*$(foreach warn,$(WARNS_EXCEPTS),,-$(warn))" | tr -d ' ')

.PHONY: clang_tidy_run
clang_tidy_run:
	$(CLANG_TIDY) \
		-checks="$(WARNS)" \
		-header-filter=".*" \
		-warnings-as-errors="*" \
		-extra-arg=-std=c++17 \
		$(SRC_FILES) -- $(IFLAGS) \

.PHONY: clang_tidy_fix
clang_tidy_fix:
	$(CLANG_TIDY) \
		-checks="$(WARNS)" \
		-header-filter=".*" \
		-fix-errors \
		$(SRC_FILES) -- $(IFLAGS) \
