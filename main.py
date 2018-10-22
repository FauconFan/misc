#!/usr/bin/python3
import sys
import argparse

from src.parser import parse
from src.is_soluble import is_soluble
from src.solver import solver
from src.taquin import Taquin

if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument("-s", "--show", action="store_true", default=False, help="show moves at the end")
	parser.add_argument("taquin")
	args = parser.parse_args()

	taquin = parse(args.taquin)
	print(taquin)
	soluble = is_soluble(taquin)
	print('Est-il soluble :', soluble) # !! Ne pas enlever cette ligne. Elle est utilisée dans les tests
	if soluble:
		result = solver(taquin)
		print(result)
		if args.show:
			print(result.build_moves())
