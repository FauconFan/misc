
from enum import Enum

from src.logger import log
from src.Exceptions import IncoherenceException


class Environment(object):
	def __init__(self, list_formulas, table_of_truth, is_poor):
		self.list_formulas = list_formulas
		self.table_of_truth = table_of_truth
		self.is_poor = is_poor
		self.setEnv = self.setEnvRich
		if is_poor:
			self.setEnv = self.setEnvPoor

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
			if v is not None:
				vs = str(v)
			s += str(k) + " : " + vs + "\n"
		return s

	def __eq__(self, other):
		return self.table_of_truth == other.table_of_truth

	def stillHaveUndefined(self):
		for _, v in self.table_of_truth.items():
			if v is None:
				return True
		return False

	def getNextUndefined(self):
		tabUndefined_tmp = {}
		for k, v in self.table_of_truth.items():
			tabUndefined_tmp[k] = 0
		for formula in self.list_formulas:
			formula.countUndefined(self, tabUndefined_tmp)
		tabUndefined = {}
		for k, v in self.table_of_truth.items():
			if v is None:
				tabUndefined[k] = tabUndefined_tmp[k]
		cand = None
		candValue = 0
		for k, v in tabUndefined.items():
			if cand is None:
				cand = k
				candValue = v
			elif candValue < v:
				cand = k
				candValue = v
		return cand

	def applyRules(self):
		for formula in self.list_formulas:
			s = formula.deduce(self, True, self.is_poor)
			log(self, s, formula)

	def getEnv(self, s):
		return self.table_of_truth[s]

	# We return the fact that we already know the fact or not
	# False if we already know
	# True if we just discovered
	def setEnvRich(self, str, mb):
		if self.table_of_truth[str] is not None and self.table_of_truth[str] != mb:
			raise IncoherenceException
		if self.table_of_truth[str] == mb:
			return False
		self.table_of_truth[str] = mb
		return True

	def setEnvPoor(self, str, mb):
		if self.table_of_truth[str] and not mb:
			raise IncoherenceException
		if self.table_of_truth[str]:
			return False
		self.table_of_truth[str] = True
		return True

	def fusionUnionForDisjonction(self, envTrue, envFalse):
		for k, v in self.table_of_truth.items():
			if v is None:
				if envTrue.getEnv(k) == envFalse.getEnv(k):
					self.setEnv(k, envTrue.getEnv(k))


def create_table_of_truth(list_formulas, axioms, is_poor):
	table_of_truth = {}
	default = None
	if is_poor:
		default = False
	for formula in list_formulas:
		variables = formula.getAllVariablesInFormula()
		for var in variables:
			if var not in table_of_truth:
				table_of_truth[var] = default
	for c_tuple in axioms:
		(b, c) = c_tuple
		table_of_truth[c] = b
	return table_of_truth
