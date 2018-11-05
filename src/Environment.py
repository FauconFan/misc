
from enum import Enum

from src.logger import log

class Environment(object):
    def __init__(self, list_formulas, table_of_truth):
        self.list_formulas = list_formulas
        self.table_of_truth = table_of_truth

    def __str__(self):
        s = "Env:\n"
        s += "Rules\n"
        for i in self.list_formulas:
            s += str(i) + "\n"
        s += self.StrTableOfTruth()
        return s

    def StrTableOfTruth(self):
        s = ""
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
        return None

    def applyRules(self):
        for formula in self.list_formulas:
            s = formula.deduce(self)
            log(self, s, formula)

    def getEnv(self, s):
        return self.table_of_truth[s]

    # We return the fact that we already know the fact or not
    # False if we already know
    # True if we just discovered
    def setEnv(self, str, mb):
        if self.table_of_truth[str] != None and self.table_of_truth[str] != mb:
            raise Exception("Incohérence")
        if self.table_of_truth[str] == mb:
            return False
        self.table_of_truth[str] = mb
        return True

    def fusionUnionForDisjonction(self, envTrue, envFalse):
        for k, v in self.table_of_truth.items():
            if v == None:
                if envTrue.getEnv(k) == envFalse.getEnv(k):
                    self.setEnv(k, envTrue.getEnv(k))

def create_table_of_truth(list_formulas, axioms):
    table_of_truth = {}
    for formula in list_formulas:
        variables = formula.getAllVaribalesInFormula()
        for var in variables:
            if var not in table_of_truth:
                table_of_truth[var] = None
    for c in axioms:
        if c in table_of_truth:
            table_of_truth[c] = True
    return table_of_truth
