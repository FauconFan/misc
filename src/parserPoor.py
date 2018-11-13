import sys

from src.Formule import Formule, Operator
from src.Lexer import *

VAR_CHAR = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
PRIORITY = {
	"<=>" : 1,
	"=>" : 2,
	"^" : 3,
	"|" : 4,
	"+" : 5,
	"!" : 6,
	"(" : 7,
	")" : 8
}

def get_poor_l_r(op, stack):
	right = None
	left = None
	if op != '!' and len(stack) is not 0:
		right = stack.pop()
	if len(stack) is not 0:
		left = stack.pop()
	f_left = left
	f_right = right
	if isinstance(left, str):
		f_left = Formule(None, left)
	if isinstance(right, str):
		f_right = Formule(None, right)
	return f_left, f_right

def resolve_poor_op(var_stack, op_stack):
	if len(op_stack) <= 0 or len(var_stack) <= 0:
		print("Error: nothing in stack")
		sys.exit(1)
	op = op_stack.pop(len(op_stack) - 2)
	f_left, f_right = get_poor_l_r(op, var_stack)
	try:
		formule = Formule(op, f_left, f_right)
	except Exception as e:
		print("Try to create an invalid formule: Error: {}".format(e))
	var_stack.insert(len(var_stack), formule)
	
def check_poor_resolve(op_stack):
	lenght = len(op_stack)
	if lenght <= 1:
		return False
	op1 = op_stack[lenght - 1]
	op2 = op_stack[lenght - 2]
	if op2 == "(":
		return False
	elif op1 == ")":
		return True
	if PRIORITY[op2] < PRIORITY[op1] :
		return False
	return True

def finish(var_stack, op_stack):
	while len(op_stack) != 0:
		op = op_stack.pop(len(op_stack) - 1)
		f_left, f_right = get_poor_l_r(op, var_stack)
		try:
			formule = Formule(op, f_left, f_right)
		except Exception as e:
			print("Try to create an invalid formule: Error: {}".format(e))
			sys.exit(1)
		var_stack.insert(len(var_stack), formule)
	if len(var_stack) != 1:
		print("Error in parsing")
		sys.exit(1)
	return var_stack[0]

def create_poor_formula(exp):
	op_stack = []
	var_stack = []
	for token in exp:
		if isinstance(token, TokenSym):
			op_stack.insert(len(op_stack), token.repr)
			while check_poor_resolve(op_stack):
				resolve_poor_op(var_stack, op_stack)
		elif isinstance(token, TokenVar):
			var_stack.insert(len(var_stack), token.repr)
		## delete parenthesis
		if len(op_stack) >= 2 and op_stack[len(op_stack) - 2] == "(" and op_stack[len(op_stack) - 1] == ")":
			op_stack.pop(len(op_stack) - 1)
			op_stack.pop(len(op_stack) - 1)

	return (finish(var_stack, op_stack))

