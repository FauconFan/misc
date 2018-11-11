from enum import Enum

def operatorBuffer():
	pass

operatorBuffer.buffer = {}

class Operator(Enum):
	NONE = 0
	NOT = 1
	AND = 2
	OR = 3
	XOR = 4
	IMP = 5
	EQU = 6

	@staticmethod
	def repr_op(op):
		if op == Operator.AND:
			return " + "
		elif op == Operator.OR:
			return " | "
		elif op == Operator.XOR:
			return " ^ "
		elif op == Operator.NOT:
			return "!"
		elif op == Operator.IMP:
			return " => "
		elif op == Operator.EQU:
			return " <=> "
		return ""

	@staticmethod
	def fromChar(op):
		if op == '+':
			return Operator.AND
		elif op == '|':
			return Operator.OR
		elif op == '^':
			return Operator.XOR
		elif op == '!':
			return Operator.NOT
		elif op == "=>":
			return Operator.IMP
		elif op == "<=>":
			return Operator.EQU
		elif op == None:
			return Operator.NONE

	@staticmethod
	def arity(op):
		if op == Operator.AND or op == Operator.OR or op == Operator.XOR or op == Operator.IMP or op == Operator.EQU:
			return 2
		return 1

	@staticmethod
	def getTables(op):
		if op == Operator.NONE:
			return {True: True, False: False}
		elif op == Operator.NOT:
			return {True: False, False: True}
		elif op == Operator.AND:
			return {(True, True): True, (True, False): False, (False, True): False, (False, False): False}
		elif op == Operator.OR:
			return {(True, True): True, (True, False): True, (False, True): True, (False, False): False}
		elif op == Operator.XOR:
			return {(True, True): False, (True, False): True, (False, True): True, (False, False): False}
		elif op == Operator.IMP:
			return {(True, True): True, (True, False): False, (False, True): True, (False, False): True}
		elif op == Operator.EQU:
			return {(True, True): True, (True, False): False, (False, True): False, (False, False): True}

	@staticmethod
	def getDeduction(op):
		def builder(op):
			def builderBase1():
				return {True: [], False: [], None: []}
			def builderBase2():
				return {True: builderBase1(), False: builderBase1(), None: builderBase1()}
			arity = Operator.arity(op)
			tables = Operator.getTables(op)
			res = {}
			if arity == 1:
				res = {True: builderBase1(), False: builderBase1()}
				for k, v in tables.items():
					res[v][k].append(k)
					res[v][None].append(k)
			else:
				res = {True: builderBase2(), False: builderBase2()}
				for k, v in tables.items():
					(lhs, rhs) = k
					res[v][lhs][rhs].append(k)
					res[v][None][None].append(k)
					res[v][lhs][None].append(k)
					res[v][None][rhs].append(k)
			return res
		rep = Operator.repr_op(op)
		if operatorBuffer.buffer.get(rep) == None:
			operatorBuffer.buffer[rep] = builder(op)
		return operatorBuffer.buffer[rep]
