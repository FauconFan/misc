
from enum import Enum

## MOCHE TA RACE
ALLOWED_CHAR = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

class May_boolean(Enum):
    TRUE = 1
    FALSE = 2
    UNDEFINED = 3

    @staticmethod
    def getStr(mb):
        if mb == May_boolean.TRUE:
            return "True"
        elif mb == May_boolean.FALSE:
            return "False"
        return "Undefined"


class Environment(object):
    def __init__(self, list_rules, table_of_truth):
        self.list_rules = list_rules
        self.table_of_truth = table_of_truth

    def __str__(self):
        s = "Env:\n"
        s += "Rules\n"
        for i in self.list_rules:
            s += str(i) + "\n"
        s += "Table of truth\n"
        for k, v in self.table_of_truth.items():
            s += str(k) + " : " + May_boolean.getStr(v) + "\n"
        return s

    def stillHaveUndefined(self):
        for _, v in self.table_of_truth.items():
            if v == May_boolean.UNDEFINED:
                return True
        return False

    def applyRules(self):
        for rule in self.list_rules:
            if rule.formule_left.eval(self):
                rule.formule_right.deduce(self)

    def getEnv(self, str):
        return self.table_of_truth[str]

    def setEnv(self, str, mb):
        self.table_of_truth[str] = mb

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
            raise Exception("No rule for this axiom")
    return table_of_truth
