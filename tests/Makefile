
CHECK_SAT = ./check_sat.py
CHECK_UNSAT = ./check_unsat.py
SAT = ../sat/sat

FOLDER_CNFS = ../input_files/satlib/_01_RND3SAT__uf20-91
ALGO = cdcl

FILES = $(shell find $(FOLDER_CNFS) -name "*.cnf" | sort)

.PHONY: test_sat
test_sat: $(SAT)
	$(foreach file, $(FILES), bash -c "$(CHECK_SAT) $(file) <($(SAT) --no-logs $(ALGO) $(file))";)

.PHONY: test_unsat
test_unsat: $(SAT)
	$(foreach file, $(FILES), bash -c "$(CHECK_UNSAT) $(file) <($(SAT) --no-logs $(ALGO) $(file))";)

$(SAT):
	make -C $(dir $(SAT)) fast
