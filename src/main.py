
import sys

from parser import parse

def main():
    if len(sys.argv) != 2:
        sys.exit(1)
    parse(sys.argv[1])

if __name__ == "__main__":
    main()
