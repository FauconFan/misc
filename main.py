#!/usr/bin/python3
import sys

from parser import parse
from is_soluble import is_soluble

def print_taquin(taquin):
	for i in range(taquin['size']):
		for j in range(taquin['size']):
			print(taquin[(i, j)], end = " ")
		print()
	print()

if __name__ == '__main__':
	try:
		taquin = parse(sys.argv[1])
		print_taquin(taquin)
		soluble = is_soluble(taquin)
		print("Est-il soluble :", soluble)
	except IndexError:
		print("Larg 1 doit etre le fichier du taquin")
