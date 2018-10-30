from enum import Enum

class Operator(Enum):
    AND = 1
    OR = 2
    XOR = 3
    NOT = 4
    NONE = 5

    @staticmethod
    def repr_op(op):
        if op == Operator.AND:
            return " + "
        if op == Operator.XOR:
            return " ^ "
        if op == Operator.NOT:
            return "!"
        if op == Operator.OR:
            return " | "
        return " "

    @staticmethod
    def op_list():
        return ['+', '|', '^', '!']

    @staticmethod
    def fromChar(op):
        if op == '+':
            return Operator.AND
        if op == '|':
            return Operator.OR
        if op == '^':
            return Operator.XOR
        if op == '!':
            return Operator.NOT
        if op == None:
            return Operator.NONE
    ## not used
    @staticmethod
    def arity(op):
        if op == Operator.NONE:
            return 0
        elif op == Operator.NOT:
            return 1
        return 2

class Formule(object):
    def __init__(self, operateur, operand1 = None, operand2 = None):
        self.operateur = Operator.fromChar(operateur)
        self.left = None
        self.right = None
        self.elem = None
        # print(operand1, operateur, operand2)
        if self.operateur == Operator.AND or self.operateur == Operator.OR or self.operateur == Operator.XOR:
            if operand1 == None or operand2 == None:
                raise "Invalid utilisation"
            self.left = operand1
            self.right = operand2
        elif self.operateur == Operator.NOT or self.operateur == Operator.NONE:
            if operand1 == None:
                raise "Invalid utilisation"
            self.elem = operand1
        else:
            print("Mauvaise expression : ", operateur, operand1, operand2)
            raise "Invalid utilisation"

    def __str__(self):
        if self.elem:
            return Operator.repr_op(self.operateur) + str(self.elem)
        return "(" + str(self.left) + Operator.repr_op(self.operateur) + str(self.right) + ")"
