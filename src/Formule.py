from src.Operator import Operator

class Formule(object):
    def __init__(self, operateur, operand1 = None, operand2 = None):
        self.operateur = Operator.fromChar(operateur)
        self.left = None
        self.right = None
        self.elem = None
        arity = Operator.arity(self.operateur)
        if arity == 2:
            if operand1 == None or operand2 == None:
                raise Exception("Invalid utilisation: {} {} {}".format(operand1, operateur, operand2))
            self.left = operand1
            self.right = operand2
        elif arity == 1:
            if operand1 == None:
                raise Exception("Invalid utilisation: {} {} {}".format(operand1, operateur, operand2))
            self.elem = operand1
        else:
            raise Exception("Invalid utilisation: {} {} {}".format(operand1, operateur, operand2))

    def __str__(self):
        if self.elem:
            return Operator.repr_op(self.operateur) + str(self.elem)
        return "(" + str(self.left) + Operator.repr_op(self.operateur) + str(self.right) + ")"

    def getAllVaribalesInFormula(self):
        if self.operateur == Operator.NONE:
            s = set()
            s.add(self.elem)
            return s
        elif self.operateur == Operator.NOT:
            return self.elem.getAllVaribalesInFormula()
        else:
            return self.left.getAllVaribalesInFormula() | self.right.getAllVaribalesInFormula()

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

    def deduce(self, env, fact_bool, is_poor):
        s = set()
        if Operator.arity(self.operateur) == 1:
            if self.operateur == Operator.NOT:
                return (self.elem.deduce(env, fact_bool == False, is_poor))
            b = env.setEnv(self.elem, fact_bool)
            if b:
                s.add(self.elem)
            return s
        else:
            tab = Operator.getDeduction(self.operateur)
            b0 = self.left.eval(env)
            b1 = self.right.eval(env)
            if is_poor:
                if b0 == False:
                    b0 = None
                if b1 == False:
                    b1 = None
            li = tab[fact_bool][b0][b1]
            if (len(li) == 0 and not(is_poor)):
                raise Exception("Incohérence")
            elif (len(li) == 1):
                (ded0, ded1) = li[0]
                if b0 == None:
                    s = s | self.left.deduce(env, ded0, is_poor)
                elif b0 != ded0:
                    raise Exception("Incohérence")
                if b1 == None:
                    s = s | self.right.deduce(env, ded1, is_poor)
                elif b1 != ded1:
                    raise Exception("Incohérence")
            return s
