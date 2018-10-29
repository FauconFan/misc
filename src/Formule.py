from enum import Enum

class Operator(Enum):
    AND = 1
    OR = 2
    XOR = 3
    NOT = 4
    NONE = 5

    def fromChar(op):
        if op == '+':
            return Operator.AND
        if op == '|':
            return Operator.OR
        if op == '^':
            return Operator.XOR
        if op == '!':
            return Operator.NOT

    def arity(op):
        if op == NONE:
            return 0
        elif op == NOT:
            return 1
        return 2

class Formule(object):
    def __init__(self, operateur, operand1 = None, operand2 = None):
        self.operateur = Operator.fromChar(operateur)
        # if self.operateur == Operator.AND or self.operateur == Operator.OR or self.operateur == Operator.XOR:
        #     if operand1 == None or operand2 == None:
        #         raise "Invalid utilisation"
        #     self.left = operand1
        #     self.right = operand2
        # elif self.operateur == Operator.NOT or self.operateur == Operator.NONE:
        #     if operand1 == None:
        #         raise "Invalid utilisation"
        #     self.elem = operand1
        # else:
        #     raise "Invalid utilisation"

    # def __repr__(self):
    #     return "Formule : " + self.left + self.__reprOP() + self.right

    # def __reprOP(self):
    #     if self.operateur == Operator.AND:
    #         return " + "
    #     if self.operateur == Operator.XOR:
    #         return " ^ "
    #     if self.operateur == Operator.NOT:
    #         return " !"
    #     if self.operateur == Operator.OR:
    #         return " | "
    #     return " "