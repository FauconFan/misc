from enum import Enum

class Operator(Enum):
    AND = 1
    OR = 2
    XOR = 3
    NOT = 4
    IMP = 5
    EQU = 6
    NONE = 7

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

    ## not used anymore
    # @staticmethod
    # def op_list(): # FIXME after refactoring for parsing
    #     return ['+', '|', '^', '!']

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

class Formule(object):
    def __init__(self, operateur, operand1 = None, operand2 = None):
        self.operateur = Operator.fromChar(operateur)
        self.left = None
        self.right = None
        self.elem = None
        arity = Operator.arity(self.operateur)
        if arity == 2:
            if operand1 == None or operand2 == None:
                raise Exception("Invalid utilisation")
            self.left = operand1
            self.right = operand2
        elif arity == 1:
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
        elif self.operateur == Operator.IMP:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 == False or b1 == True:
                return True
            if b0 == None or b1 == None:
                return None
            return False
        elif self.operateur == Operator.EQU:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 == None or b1 == None:
                return None
            return b0 == b1

    def deduce(self, env):
        if self.operateur == Operator.NONE:
            env.setEnv(self.elem, True)
        elif self.operateur == Operator.NOT:
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
            if b1 == False:
                self.left.deduce(env)
        elif self.operateur == Operator.XOR:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 != None and b1 != None:
                if b0 == b1:
                    raise Exception("Incohérence")
            if b0 == False:
                self.right.deduce(env)
            if b1 == False:
                self.left.deduce(env)
        elif self.operateur == Operator.IMP:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 != None and b1 != None:
                if b0 == True and b1 == False:
                    raise Exception("Incohérence")
            if b0 == True:
                self.right.deduce(env)
            if b1 == False:
                self.left.deduceReverse(env)
        elif self.operateur == Operator.EQU:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 != None and b1 != None:
                if b0 != b1:
                    raise Exception("Incohérence")
            if b0 != None:
                if b0 == True:
                    self.right.deduce(env)
                else:
                    self.right.deduceReverse(env)
            if b1 != None:
                if b1 == True:
                    self.left.deduce(env)
                else:
                    self.left.deduceReverse(env)

    def deduceReverse(self, env):
        if self.operateur == Operator.NONE:
            env.setEnv(self.elem, False)
        elif self.operateur == Operator.NOT:
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
            if b1 == True:
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
            if b0 == False:
                self.right.deduceReverse(env)
            if b1 == True:
                self.left.deduce(env)
            if b1 == False:
                self.left.deduceReverse(env)
        elif self.operateur == Operator.IMP:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 == False and b1 == True:
                raise Exception("Incohérence")
            self.left.deduce(env)
            self.right.deduceReverse(env)
        elif self.operateur == Operator.EQU:
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if b0 != None and b1 != None:
                if b0 == b1:
                    raise Exception("Incohérence")
            if b0 == True:
                self.right.deduceReverse(env)
            elif b0 == False:
                self.right.deduce(env)
            if b1 == True:
                self.left.deduceReverse(env)
            elif b1 == False:
                self.left.deduce(env)
