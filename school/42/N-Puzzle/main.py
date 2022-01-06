#!/usr/bin/python3
import sys
import argparse

from src.parser import parse
from src.is_soluble import is_soluble
from src.solver import solver
from src.taquin import Taquin

if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument("-q", "--quiet", action="store_true", default=False, help="show moves at the end")
	parser.add_argument("--heuristic", default="manhattan", help="choose the heuristic function in ['manhattan', 'euclidian', 'right_position']")
	parser.add_argument("taquin")
	args = parser.parse_args()

	taquin = parse(args.taquin)
	if not args.quiet:
		print(taquin)
	try:
		taquin.choose_heuristic(args.heuristic)
	except:
		print("Choose wisely your heuristic function")
		sys.exit(1)
	soluble = is_soluble(taquin)
	print('Is it soluble ?', soluble) # !! Ne pas enlever cette ligne. Elle est utilisée dans les tests
	if soluble:
		result = solver(taquin)
		print(result)
		if not args.quiet:
			print(result.build_moves())
