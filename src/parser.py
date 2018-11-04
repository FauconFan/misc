import sys

from src.Formule import Formule, Operator
from src.Lexer import *

VAR_CHAR = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def get_left_right(op, stack, op_stack):
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
		f_left, f_right = get_left_right(op, stack, op_stack)
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
	return resolve_stack(stack, op_stack)

def parse_tokens(lines):
	list_formulas = []
	axioms = []
	queries = []
	for line in lines:
		for token in line:
			if isinstance(token, TokenSym):
				list_formulas.append(create_formula(line))
				break
			if isinstance(token, TokenSpecial):
				if token.repr == '=':
					axioms = [a.repr for a in line[1:]]
				elif token.repr == '?':
					queries = line[1:]
					queries = [q.repr for q in line[1:]]
				break

	if not queries:
		print("No queries")
		sys.exit(1)
	return axioms, queries, list_formulas


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
	lexer = Lexer(lines)
	lexer.run()
	tokens_lines = lexer.get()
	return(parse_tokens(tokens_lines))