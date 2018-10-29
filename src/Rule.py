
from enum import Enum

class State(Enum):
    DEF_ALL = 1
    DEF_PART = 2
    DEF_NOT = 3

class Rule(object):
    def __init__(self, formule_left, formule_right, state):
        self.formule_left = formule_left
        self.formule_right = formule_right
        self.state = state
