
CXX = clang++ -std=c++17 -O2

SRC_FILE = main.cpp
OUT = output

.PHONY: all
all: $(OUT)

$(OUT): $(SRC_FILE)
	$(CXX) $(SRC_FILE) -o $@

.PHONY: run
run: all
	./$(OUT)

.PHONY: clean
clean:
	rm -f $(OUT)

.PHONY: re
re: clean all