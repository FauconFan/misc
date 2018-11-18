import sys
import argparse

from src.Environment import create_table_of_truth, Environment
from src.Operator import Operator
from src.logger import log_set_interactive, log_set_verbose, log_helper
from src.parser import parse
from src.algo import algo


def print_initial(axioms, queries, rules):
	def print_facts(list, name_sing, name_plus):
		if len(list) == 0:
			print("= NO {} =".format(name_plus))
		else:
			name_toprint = name_sing
			if len(queries) != 1:
				name_toprint = name_plus
			print("= {} =".format(name_toprint))
			li_li = []
			for (b, var) in list:
				li_li.append("{}({})".format(var, b))
			print(", ".join(li_li))
	print("==== INITIAL ====")
	print_facts(axioms, "AXIOM", "AXIOMS")
	print_facts(queries, "QUERY", "QUERIES")
	print("= RULES =")
	for k, v in enumerate(rules):
		print("{} -> {}".format(k, v))


def print_final(queries, env):
	print("==== FINAL ====")
	nb_true = 0

	for q_tuple in queries:
		(asked, q) = q_tuple
		answer = None
		try:
			answer = env.table_of_truth[q]
			if answer is None:
				answer = "Undefined"
		except KeyError:
			answer = "Undefined"
		except Exception as e:
			print(e)
		if answer is not None:
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
	try:
		axioms, queries, list_rules = parse(args.file, args.poor)
	except Exception as e:
		print(e)
		sys.exit(1)

	print_initial(axioms, queries, list_rules)
	table = create_table_of_truth(list_rules, axioms, args.poor)
	env = Environment(list_rules, table, args.poor)
	if args.verbose:
		print(env)
	try:
		algo(env, args.poor)
	except Exception as e:
		print(e)
		sys.exit(1)
	print_final(queries, env)


if __name__ == "__main__":
	main()
