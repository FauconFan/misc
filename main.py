
import sys
import argparse

from src.logger import log_set_interactive, log_set_verbose
from src.parser import parse
from src.Environment import create_table_of_truth, Environment
from src.algo import algo

def answer(queries, env):
    print("==== FINAL ====")
    nb_true = 0
    for q in queries:
        answer = None
        try:
            answer = env.table_of_truth[q]
            if answer == None:
                answer = "Undefined"
        except KeyError:
            answer = "Undefined"
        except Exception as e:
            print(e)
        if answer != None:
            if answer == True:
                nb_true += 1
            print("{} : {}".format(q, answer))
    if nb_true == len(queries):
        sys.exit(0)
    else:
        sys.exit(1)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--interactive", action="store_true", default=False, help="make the deduction interactively")
    parser.add_argument("-v", "--verbose", action="store_true", default=False, help="print table of truth at every step")
    parser.add_argument("file")
    args = parser.parse_args()

    if args.interactive:
        log_set_interactive()
    if args.verbose:
        log_set_verbose()
    axioms, queries, list_rules = parse(args.file)

    table = create_table_of_truth(list_rules, axioms)
    env = Environment(list_rules, table)
    if args.verbose:
        print(env)
    try:
        algo(env)
    except Exception as e:
        print(e)
        sys.exit(1)
    answer(queries, env)

if __name__ == "__main__":
    main()
