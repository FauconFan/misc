import sys

from Formule import Formule, Operator
from Rule import Rule

ALLOWED_CHAR = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

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

def resolve_op(stack, op_stack, parenthesis):
	if len(op_stack) is not 0:
		op = op_stack.pop(0)
		if op == "(":
			parenthesis = 0
			op = op_stack.pop(0)
		if op == '!':
			right = None
		else:
			right = stack.pop(0)
		left = stack.pop(0)
		formule = Formule(op, left, right)
		stack.insert(0, formule)
		if parenthesis:
			resolve_op(stack, op_stack, parenthesis)


def resolve_stack(stack, op_stack):
	while len(op_stack) is not 0:
		resolve_op(stack, op_stack, 0)
	return stack.pop(0)

def create_formula(exp):
	op_stack = []
	stack = []
	for i in range(len(exp)):
		if exp[i] in Operator.op_list() or exp[i] in ["(", ")"]:
			if exp[i] == ")":
				resolve_op(stack, op_stack, 1)
			else:
				op_stack.insert(0, exp[i])
		elif ALLOWED_CHAR.find(exp[i]) != -1:
			stack.insert(0, exp[i])
			if "(" not in op_stack:
				resolve_op(stack, op_stack, 0)
	return resolve_stack(stack, op_stack)


def create_rule(line):
	expressions = line.split("=>")
	expressions = [exp.strip() for exp in expressions]
	left_formule = create_formula(expressions[0].replace(" ", ""))
	right_formule = create_formula(expressions[1].replace(" ", ""))
	return Rule(left_formule, right_formule, None)

def parse_lines(lines):
	list_rules = []
	for line in lines:
		print(line)
		## need to check errors here
		if line.find("<=>") >= 0:
			## convert this to two create rule implications
			pass
		elif line.find("=>") >= 0:
			list_rules.append(create_rule(line))
		elif line[0] == '=':
			axioms = list(line[1:])
		elif line[0] == '?':
			queries = list(line[1:])
	return axioms, queries, list_rules


def parse(filename):
	try:
		with open(filename) as file:
			lines = file.read().splitlines()
	except FileNotFoundError: ## depends python version
	# except IOError:
		print('File not found')
		sys.exit(1)
	except IsADirectoryError:
		print('The argument is a directory')
		sys.exit(1)
	except:
		print('Unexpected error')
		sys.exit(1)
	lines = clean_lines(lines)
	axioms, queries, list_rules = parse_lines(lines)
