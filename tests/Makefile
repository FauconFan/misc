
CHECK_SAT = ./check_sat.py
SAT = ../sat/sat

FOLDER_CNFS = ../input_files/satlib/_01_RND3SAT__uf20-91
ALGO = dpll

FILES = $(shell find $(FOLDER_CNFS) -name "*.cnf")

.PHONY: test_run
test_run: $(SAT)
	$(foreach file, $(FILES), bash -c "$(CHECK_SAT) $(file) <($(SAT) --no-logs $(ALGO) $(file))";)

$(SAT):
	make -C $(dir $(SAT)) $(notdir $(SAT))

