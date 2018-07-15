.PHONY: all build clean

all: build

build:
	@printf "Compiling... "
	@javac $(shell find . -name "*.java")
	@printf "done\\n"

clean:
	find . -name "*.class" -delete
	find tests -name "*.log" -delete
