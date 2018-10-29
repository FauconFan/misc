import sys

from Formule import Formule, Operator
from Lineparser import LineParser

def clean_lines(lines):
	#Mise Au propre de la recuperation sur l'entree standard

	new_lines = []
	for i in lines:
		val = i
		if '#' in i.strip():
			val = i[:i.index("#")]
		if len(val.strip()) > 0:
			new_lines.append(val.strip())
	return new_lines

# def is_operator(char):
# 	if char == '+':
# 		return 1
# 	elif char == '|':
# 		return 2
# 	return -1

# def create_formula(exp):
# 	# print(exp)
# 	for c in exp:
# 		if is_operator(c) > 0:

def create_rule(line):
	expressions = line.split("=>")
	expressions = [exp.strip() for exp in expressions]
	## creer recursivement une formule par priorite
	## pour l'instant: expression simple
	# create_formula(expressions[0])
	line_parser = LineParser(expressions[0])
	line_parser.parse()

def parse_line(line):
	# print(line)
	## need to check errors here
	if line.find("<=>") >= 0:
		## convert this to two create rule implications
		pass
	elif line.find("=>") >= 0:
		create_rule(line)
	elif line[0] == '=':
		## get axioms
		pass
	elif line[0] == '?':
		## get queries
		pass


def parse(filename):
	try:
		with open(filename) as file:
			lines = file.read().splitlines()
	# except FileNotFoundError: ## depends python version
	except IOError:
		print('File not found')
		sys.exit(1)
	except IsADirectoryError:
		print('The argument is a directory')
		sys.exit(1)
	except:
		print('Unexpected error')
		sys.exit(1)
	lines = clean_lines(lines)
	for line in lines:
		parse_line(line)