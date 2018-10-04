#!/usr/bin/python3
import sys
from parser import parse
if __name__ == '__main__':
	try:
		parse(sys.argv[1])
	except IndexError:
		print("Larg 1 doit etre le fichier du taquin")