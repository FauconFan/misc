from src.Operator import Operator
from src.Exceptions import IncoherenceException, InvalidUsageException


class Formule(object):
	def __init__(self, operateur, operand1=None, operand2=None):
		self.operateur = Operator.fromChar(operateur)
		self.left = None
		self.right = None
		self.elem = None
		arity = Operator.arity(self.operateur)
		if arity == 2:
			if operand1 is None or operand2 is None:
				raise InvalidUsageException("Invalid utilisation: {} {} {}".format(operand1, operateur, operand2))
			self.left = operand1
			self.right = operand2
		elif arity == 1:
			if operand1 is None:
				raise InvalidUsageException("Invalid utilisation: {} {} {}".format(operand1, operateur, operand2))
			self.elem = operand1
		else:
			raise InvalidUsageException("Invalid utilisation: {} {} {}".format(operand1, operateur, operand2))

	def __str__(self):
		if self.elem:
			return Operator.repr_op(self.operateur) + str(self.elem)
		return "(" + str(self.left) + Operator.repr_op(self.operateur) + str(self.right) + ")"

	def getAllVariablesInFormula(self):
		if self.operateur == Operator.NONE:
			s = set()
			s.add(self.elem)
			return s
		elif self.operateur == Operator.NOT:
			return self.elem.getAllVariablesInFormula()
		else:
			return self.left.getAllVariablesInFormula() | self.right.getAllVariablesInFormula()

	def eval(self, env, is_poor):
		if self.operateur == Operator.NONE:
			return env.getEnv(self.elem)
		elif self.operateur == Operator.NOT:
			b0 = self.elem.eval(env, is_poor)
			if b0 is None:
				return None
			return not(b0)
		tab = Operator.getEval(self.operateur)
		b0 = self.left.eval(env, is_poor)
		b1 = self.right.eval(env, is_poor)
		b = tab[b0][b1]
		if is_poor and b is None:
			b = False
		return b

	def deduce(self, env, fact_bool, is_poor):
		s = set()
		if Operator.arity(self.operateur) == 1:
			if self.operateur == Operator.NOT:
				return (self.elem.deduce(env, not fact_bool, is_poor))
			b = env.setEnv(self.elem, fact_bool)
			if b:
				s.add(self.elem)
			return s
		else:
			tab = Operator.getDeduction(self.operateur)
			b0 = self.left.eval(env, is_poor)
			b1 = self.right.eval(env, is_poor)
			if is_poor:
				if not b0:
					b0 = None
				if not b1:
					b1 = None
			li = tab[fact_bool][b0][b1]
			if (len(li) == 0 and not(is_poor)):
				raise IncoherenceException
			elif (len(li) == 1):
				(ded0, ded1) = li[0]
				if b0 is None:
					s = s | self.left.deduce(env, ded0, is_poor)
				elif b0 != ded0:
					raise IncoherenceException
				if b1 is None:
					s = s | self.right.deduce(env, ded1, is_poor)
				elif b1 != ded1:
					raise IncoherenceException
			return s

	def countUndefinedNoCheck(self, tabUndefined):
		if Operator.arity(self.operateur) == 1:
			if self.operateur == Operator.NOT:
				self.elem.countUndefinedNoCheck(tabUndefined)
			else:
				tabUndefined[self.elem] = tabUndefined[self.elem] + 1
		else:
			self.left.countUndefinedNoCheck(tabUndefined)
			self.right.countUndefinedNoCheck(tabUndefined)

	def countUndefined(self, env, tabUndefined):
		if Operator.arity(self.operateur) == 1:
			if self.operateur == Operator.NOT:
				self.elem.countUndefined(env, tabUndefined)
			else:
				tabUndefined[self.elem] = tabUndefined[self.elem] + 1
		else:
			b0 = self.left.eval(env, False)
			b1 = self.right.eval(env, False)
			if b0 is not None:
				self.left.countUndefined(env, tabUndefined)
			else:
				self.left.countUndefinedNoCheck(tabUndefined)
			if b1 is not None:
				self.right.countUndefined(env, tabUndefined)
			else:
				self.right.countUndefinedNoCheck(tabUndefined)
