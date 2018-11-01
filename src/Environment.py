
from enum import Enum


class Environment(object):
    def __init__(self, list_formulas, table_of_truth):
        self.list_formulas = list_formulas
        self.table_of_truth = table_of_truth

    def __str__(self):
        s = "Env:\n"
        s += "Rules\n"
        for i in self.list_formulas:
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
        return None

    def applyRules(self):
        for formula in self.list_formulas:
            formula.deduce(self)

    def getEnv(self, s):
        return self.table_of_truth[s]

    def setEnv(self, str, mb):
        if self.table_of_truth[str] != None and self.table_of_truth[str] != mb:
            raise Exception("Incohérence")
        self.table_of_truth[str] = mb

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
        else:
            raise Exception("No rule for this axiom")
    return table_of_truth
