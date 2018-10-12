#!/usr/bin/python3
import sys

from parser import parse
from is_soluble import is_soluble

if __name__ == '__main__':
	try:
		taquin = parse(sys.argv[1])
		print(taquin)
		soluble = is_soluble(taquin)
		print("Est-il soluble :", soluble)
	except IndexError:
		print("Larg 1 doit etre le fichier du taquin")
