
from enum import Enum

class Operator(Enum):
    AND = 1
    OR = 2
    XOR = 3
    NOT = 4
    NONE = 5


class Formule(object):
    def __init__(self, operateur, operand1 = None, operand2 = None):
        self.operateur = operateur
        if operateur == AND or operateur == OR or operateur == XOR:
            if operand1 == None or operand2 == None:
                raise "Invalid utilisation"
            self.left = operand1
            self.right = operand2
        elif operateur == NOT or operateur == NONE:
            if operand1 == None:
                raise "Invalid utilisation"
            self.elem = operand1
        else:
            raise "Invalid utilisation"
