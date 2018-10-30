
from enum import Enum

## MOCHE TA RACE
ALLOWED_CHAR = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


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
            vs = "Undefined"
            if v != None:
                vs = str(v)
            s += str(k) + " : " + vs + "\n"
        return s

    def __eq__(self, other):
        return self.table_of_truth == other.table_of_truth

    def stillHaveUndefined(self):
        for _, v in self.table_of_truth.items():
            if v == None:
                return True
        return False

    def getFirstUndefined(self):
        for k, v in self.table_of_truth.items():
            if v == None:
                return k
        raise Exception("SNH")

    def applyRules(self):
        for rule in self.list_rules:
            b0 = rule.formule_left.eval(self)
            b1 = rule.formule_right.eval(self)
            if b0 == True and b1 == False:
                raise Exception("Incohérence")
            if b0 == True:
                rule.formule_right.deduce(self)
            if b1 == False:
                rule.formule_left.deduceReverse(self)

    def getEnv(self, s):
        return self.table_of_truth[s]

    def setEnv(self, str, mb):
        if self.table_of_truth[str] != None and self.table_of_truth[str] != mb:
            raise Exception("Incohérence")
        self.table_of_truth[str] = mb

def create_table_of_truth(list_rules, axioms):
    table_of_truth = {}
    for i in list_rules:
        rule = str(i)
        for c in list(rule):
            if ALLOWED_CHAR.find(c) != -1:
                if c not in table_of_truth:
                    table_of_truth[c] = None
    for c in axioms:
        if c in table_of_truth:
            table_of_truth[c] = True
        else:
            raise Exception("No rule for this axiom")
    return table_of_truth
