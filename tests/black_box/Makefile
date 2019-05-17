
CIMP = ../../cimp

IN_FILES = \
			01_empty.in \
			02_normal.in \
			03_open.in \
			04_help.in \
			05_list.in \
			06_open_update.in \
			07_wrong.in \
			08_open_list.in \
			08_open_jpg.in \
			08_open_png.in \

.PHONY: run
run:
	test -f $(CIMP)
	@$(foreach file, $(IN_FILES), cat $(file) | $(CIMP) && ) true

