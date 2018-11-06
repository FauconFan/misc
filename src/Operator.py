from enum import Enum

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
    def getDeduction(op, known, elem1 = None, elem2 = None):
		arity = Operator.arity(op)
		if arity == 1 and elem1 == None:
			raise Exception("Wrong usage")
		elif arity == 2 and (elem1 == None or elem2 == None):
			raise Exception("Wrong usage")
		tables = Operator.getTables(op)
		li2 = []
		for k, v in tables.items():
			if v == known:
				li2.append(k)
		li = []
		if arity == 1:
			for i in li2:
