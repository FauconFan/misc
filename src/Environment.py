
from enum import Enum

## MOCHE TA RACE
ALLOWED_CHAR = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

class May_boolean(Enum):
    TRUE = 1
    FALSE = 2
    UNDEFINED = 3

class Environment(object):
    def __init__(self, list_rules, table_of_truth):
        self.list_rules = list_rules
        self.table_of_truth = table_of_truth

def create_table_of_truth(list_rules, axioms):
    table_of_truth = {}
    for i in list_rules:
        rule = str(i)
        for c in list(rule):
            if ALLOWED_CHAR.find(c) != -1:
                if c not in table_of_truth:
                    table_of_truth[c] = May_boolean.UNDEFINED
    for c in axioms:
        if c in table_of_truth:
            table_of_truth[c] = May_boolean.TRUE
        else:
            raise "No rule for this axiom"
    return table_of_truth