
import sys

from src.parser import parse

def main():
    if len(sys.argv) != 2:
        sys.exit(1)
    axioms, queries, list_rules = parse(sys.argv[1])
    print("axioms:", axioms)
    print("queries:", queries)
    print("list_rules")
    for i in list_rules:
        print(str(i))

if __name__ == "__main__":
    main()
