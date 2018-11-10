
import sys
import argparse

from src.logger import log_set_interactive, log_set_verbose, log_helper
from src.parser import parse
from src.Environment import create_table_of_truth, Environment
from src.algo import algo

from src.Operator import Operator

def answer(queries, env):
    print("==== FINAL ====")
    nb_true = 0
    for q_tuple in queries:
        (asked, q) = q_tuple
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
            if answer == asked:
                nb_true += 1
            print("{} : {}".format(q, answer))
    if nb_true == len(queries):
        sys.exit(0)
    else:
        sys.exit(1)

def main():
    parser = argparse.ArgumentParser(
        description="Command line tool to solve booleans formulas, based on axioms, rules and queries.",
        usage="python3 %(prog)s [options] file",
        formatter_class=argparse.RawTextHelpFormatter)
    parser.add_argument("-i", "--interactive", action="store_true", default=False, help="make the deduction interactively")
    parser.add_argument("-v", "--verbose", action="count", default=0, help=log_helper())
    parser.add_argument("-p", "--poor", action="store_true", default=False, help="make the evaluation very poor")
    parser.add_argument("file")
    args = parser.parse_args()

    if args.interactive:
        log_set_interactive()
    log_set_verbose(args.verbose)
    axioms, queries, list_rules = parse(args.file)

    table = create_table_of_truth(list_rules, axioms, args.poor)
    env = Environment(list_rules, table, args.poor)
    if args.verbose:
        print(env)
    try:
        algo(env, args.poor)
    except Exception as e:
        print(e)
        sys.exit(1)
    answer(queries, env)

if __name__ == "__main__":
    main()
