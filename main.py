#!/usr/bin/python3
import sys

from parser import parse
from is_soluble import is_soluble
from solver import solver
from taquin import Taquin

if __name__ == '__main__':
	try:
		taquin = parse(sys.argv[1])
		print(taquin)
		soluble = is_soluble(taquin)
		print('Est-il soluble :', soluble)
		if soluble:
			solver(taquin)
	except IndexError:
		print('Please, give at least one argument')
