import sys


from src.Formule import Formule, Operator
from src.Lexer import *
from src.parserPoor import create_poor_formula


VAR_CHAR = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


def get_left_right(op, stack):
	right = None
	left = None
	if op != '!' and len(stack) is not 0:
		right = stack.pop(0)
	if len(stack) is not 0:
		left = stack.pop(0)
	f_left = left
	f_right = right
	if isinstance(left, str):
		f_left = Formule(None, left)
	if isinstance(right, str):
		f_right = Formule(None, right)
	return f_left, f_right


def resolve_op(stack, op_stack, parenthesis, resolve):
	# print(stack, op_stack)
	if len(op_stack) is not 0:
		if not resolve and (op_stack[0] == "=>" or op_stack[0] == "<=>"):
			return
		op = op_stack.pop(0)
		if op == "(":
			return
		f_left, f_right = get_left_right(op, stack)
		try:
			formule = Formule(op, f_left, f_right)
		except Exception as e:
			print("Try to create an invalid formule: Error: {}".format(e))
			sys.exit(1)
		stack.insert(0, formule)
		if op == "!":
			resolve_op(stack, op_stack, parenthesis, resolve)
		if parenthesis:
			resolve_op(stack, op_stack, parenthesis, resolve)


def resolve_stack(stack, op_stack):
	while len(op_stack) is not 0:
		resolve_op(stack, op_stack, False, True)
	last = stack.pop(0)
	if len(stack) is not 0:
		print("Error in parsing")
		sys.exit(1)
	if isinstance(last, str):
		return Formule(None, last)
	return last


def create_formula(exp):
	op_stack = []
	stack = []
	for token in exp:
		if isinstance(token, TokenSym):
			if token.repr == ")":
				resolve_op(stack, op_stack, True, False)
			else:
				op_stack.insert(0, token.repr)
		elif isinstance(token, TokenVar):
			stack.insert(0, token.repr)
			resolve_op(stack, op_stack, False, False)
	res = resolve_stack(stack, op_stack)
	print(res)
	return res


def eat_facts(li):
	fact_true = True
	res = []
	index = 0
	last_fact = True
	while index < len(li):
		token = li[index]
		if isinstance(token, TokenVar):
			res.append((fact_true, token.repr))
			last_fact = True
			fact_true = True
		elif isinstance(token, TokenSym):
			if token.repr != '!':
				print("Cannot have this symbol here :", token.repr)
				sys.exit(1)
			fact_true = (not fact_true)
			last_fact = False
		elif isinstance(token, TokenSpecial):
			print("Cannot have this symbol here :", token.repr)
			sys.exit(1)
		else:
			print("Should never happened")
			sys.exit(1)
		index = index + 1
	if not last_fact:
		print("Cannot finished with a ! symbol")
		sys.exit(1)
	return res


def parse_tokens(lines, is_poor):
	list_formulas = []
	axioms = None
	queries = None
	for line in lines:
		if (len(line) == 0):
			continue
		token = line[0]
		if isinstance(token, TokenSym) or isinstance(token, TokenVar):
			if is_poor:
				list_formulas.append(create_poor_formula(line))
			else:
				list_formulas.append(create_formula(line))
		if isinstance(token, TokenSpecial):
			if token.repr == '=':
				tmp = eat_facts(line[1:])
				if axioms is None:
					axioms = tmp
				else:
					axioms = axioms + tmp
			elif token.repr == '?':
				tmp = eat_facts(line[1:])
				if (queries is None):
					queries = tmp
				else:
					queries = queries + tmp

	if not queries:
		print("No queries")
		sys.exit(1)
	return axioms, queries, list_formulas


def parse(filename, is_poor):
	try:
		with open(filename) as file:
			lines = file.read().splitlines()
	except FileNotFoundError:
		print('File not found')
		sys.exit(1)
	except IsADirectoryError:
		print('The argument is a directory')
		sys.exit(1)
	except Exception:
		print('Unexpected error')
		sys.exit(1)
	lexer = Lexer(lines)
	lexer.run()
	tokens_lines = lexer.get()
	return(parse_tokens(tokens_lines, is_poor))
