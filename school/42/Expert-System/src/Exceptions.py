
class LexerException(Exception):
	pass


class IncoherenceException(Exception):
	def __init__(self):
		Exception.__init__(self, "Incohérence found in the system of rules")


class InvalidUsageException(Exception):
	def __init__(self, msg):
		Exception.__init__(self, msg)
