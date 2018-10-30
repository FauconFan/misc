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
        return ""

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
            b0 = self.elem.eval(env)
            if b0 == None:
                return None
            return not(b0)
        elif self.operateur == Operator.AND:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 == None or b1 == None:
                return None
            return b0 and b1
        elif self.operateur == Operator.OR:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 == True or b1 == True:
                return True
            if b0 == None or b1 == None:
                return None
            return False
        elif self.operateur == Operator.XOR:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 == None or b1 == None:
                return None
            return b0 ^ b1

    def deduce(self, env):
        if self.operateur == Operator.NONE:
            env.setEnv(self.elem, True)
        elif self.operateur == Operator.NOT: # Bug here
            if isinstance(self.elem, str):
                env.setEnv(self.elem, False)
            else:
                self.elem.deduceReverse(env)
        elif self.operateur == Operator.AND:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 != None and b1 != None:
                if not(b0 == True and b1 == True):
                    raise Exception("Incohérence")
            self.left.deduce(env)
            self.right.deduce(env)
        elif self.operateur == Operator.OR:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 != None and b1 != None:
                if b0 == False and b1 == False:
                    raise Exception("Incohérence")
            if b0 == False:
                self.right.deduce(env)
            elif b1 == False:
                self.left.deduce(env)
        elif self.operateur == Operator.XOR:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 != None and b1 != None:
                if b0 == b1:
                    raise Exception("Incohérence")
            if b0 == False:
                self.right.deduce(env)
            elif b1 == False:
                self.left.deduce(env)

    def deduceReverse(self, env):
        if self.operateur == Operator.NONE:
            env.setEnv(self.elem, False)
        elif self.operateur == Operator.NOT: # Bug here
            if isinstance(self.elem, str):
                env.setEnv(self.elem, True)
            else:
                self.elem.deduce(env)
        elif self.operateur == Operator.AND:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 == True and b1 == True:
                raise Exception("Incohérence")
            if b0 == True:
                self.right.deduceReverse(env)
            elif b1 == True:
                self.left.deduceReverse(env)
        elif self.operateur == Operator.OR:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 == True or b1 == True:
                raise Exception("Incohérence")
            self.left.deduceReverse(env)
            self.right.deduceReverse(env)
        elif self.operateur == Operator.XOR:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 != None and b1 != None:
                if b0 ^ b1 == True:
                    raise Exception("Incohérence")
            if b0 == True:
                self.right.deduce(env)
            elif b0 == False:
                self.right.deduceReverse(env)
            elif b1 == True:
                self.left.deduce(env)
            elif b1 == False:
                self.left.deduceReverse(env)
