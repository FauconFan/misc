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

class Formule(object):
    def __init__(self, operateur, operand1 = None, operand2 = None):
        self.operateur = Operator.fromChar(operateur)
        self.left = None
        self.right = None
        self.elem = None
        # print(operand1, operateur, operand2)
        if self.operateur == Operator.AND or self.operateur == Operator.OR or self.operateur == Operator.XOR:
            if operand1 == None or operand2 == None:
                raise Exception("Invalid utilisation")
            self.left = operand1
            self.right = operand2
        elif self.operateur == Operator.NOT or self.operateur == Operator.NONE:
            if operand1 == None:
                raise Exception("Invalid utilisation")
            self.elem = operand1
        else:
            print("Mauvaise expression : ", operateur, operand1, operand2)
            raise Exception("Invalid utilisation")

    def __str__(self):
        if self.elem:
            return Operator.repr_op(self.operateur) + str(self.elem)
        return "(" + str(self.left) + Operator.repr_op(self.operateur) + str(self.right) + ")"

    def eval(self, env):
        if self.operateur == Operator.NONE:
            return env.getEnv(self.elem)
        elif self.operateur == Operator.NOT:
            return not(env.getEnv(self.elem))
        elif self.operateur == Operator.AND:
            return env.getEnv(self.left) and env.getEnv(self.right)
        elif self.operateur == Operator.OR:
            return env.getEnv(self.left) or env.getEnv(self.right)
        elif self.operateur == Operator.XOR:
            return env.getEnv(self.left) ^ env.getEnv(self.right)

    def decuce(self, env):
        if self.operateur == Operator.NONE:
            env.setEnv(self.elem, May_boolean.TRUE)
        elif self.operateur == Operator.NOT:
            env.setEnv(self.elem, May_boolean.FALSE)
        elif self.operateur == operateur.AND:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 != May_boolean.UNDEFINED and b1 != May_boolean.UNDEFINED:
                if not(b0 == May_boolean.TRUE and b1 == May_boolean.TRUE):
                    raise Exception("Exception")
            self.left.deduce(env)
            self.right.decuce(env)
        elif self.operateur == Operator.OR:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 != May_boolean.UNDEFINED and b1 != May_boolean.UNDEFINED:
                if b0 == May_boolean.FALSE and b1 == May_boolean.FALSE:
                    raise Exception("Exception")
            if b0 == May_boolean.FALSE:
                self.right.decuce(env)
            elif b1 == May_boolean.FALSE:
                self.left.deduce(env)
        elif self.operateur == Operator.XOR:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 != May_boolean.UNDEFINED and b1 != May_boolean.UNDEFINED:
                if b0 == b1:
                    raise Exception("Exception")
            if b0 == May_boolean.FALSE:
                self.right.decuce(env)
            elif b1 == May_boolean.FALSE:
                self.left.deduce(env)
