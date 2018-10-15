#!/usr/bin/python3
import sys

from src.parser import parse
from src.is_soluble import is_soluble
from src.solver import solver
from src.taquin import Taquin

if __name__ == '__main__':
	try:
		taquin = parse(sys.argv[1])
		print(taquin)
		soluble = is_soluble(taquin)
		print('Est-il soluble :', soluble) # !! Ne pas remove cette ligne. Elle est utilisée dans les tests
		if soluble:
			solver(taquin)
	except IndexError:
		print('Please, give at least one argument')
