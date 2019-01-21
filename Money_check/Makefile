CC = gcc
CFLAGS = -c -Wall
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
TST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit
COV_LIBS = -lgcov -coverage
SRC_DIR= src
TST_DIR= tests
SRC_FILES = $(addprefix $(SRC_DIR)/, *.c)
TST_FILES = $(addprefix $(TST_DIR)/, *.c)
GCOV = gcovr
GCONV_FLAGS = -r . --html --html-details

all: venv $(GCOV)/coverage_report.html

venv:
	python3 -m venv venv
	./venv/bin/pip3 install --upgrade pip
	./venv/bin/pip3 install gcovr

money.o:  $(SRC_FILES) $(addprefix $(SRC_DIR)/, money.h)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(SRC_FILES)

check_money.o: $(TST_FILES)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(TST_FILES)

check_money_tests: money.o check_money.o
	$(CC) money.o check_money.o $(TST_LIBS) $(COV_LIBS) -o check_money_tests

test: check_money_tests
	./check_money_tests

$(GCOV)/coverage_report.html: test
	mkdir -p $(GCOV)
	./venv/bin/$(GCOV) $(GCONV_FLAGS) -o $(GCOV)/coverage_report.html

.PHONY: clean all venv test

clean:
	-rm -rf venv
	-rm -rf $(GCOV)
	-rm *.o *.gcda *.gcno check_money_tests
