
from enum import Enum

class May_boolean(Enum):
    TRUE = 1
    FALSE = 2
    UNDEFINED = 3

class Environment(object):
    def __init__(self, list_rules, table_of_truth):
        self.list_rules = list_rules
        self.table_of_truth = table_of_truth
