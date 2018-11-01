
from enum import Enum

class TokenType(Enum):
	VAR = 1
	SYM = 2
	SPECIAL = 3

class Token(object):
	def __init__(self, type):
		self.type = type

class TokenVar(Token):
	def __init__(self, repr):
		Token.__init__(self, TokenType.VAR)
		self.repr = repr

	def __str__(self):
		return self.repr

class TokenSym(Token):
	def __init__(self, repr):
		Token.__init__(self, TokenType.SYM)
		self.repr = repr

	def __str__(self):
		return self.repr

class TokenSpecial(Token):
	def __init__(self, repr):
		Token.__init__(self, TokenType.SPECIAL)
		self.repr = repr

	def __str__(self):
		return self.repr

class Lexer(object):
	"""docstring for Lexer."""
	def __init__(self, content):
		self.content = content
		self.tokens = []

	def clean_lines(self):
		#Mise Au propre de la recuperation sur l'entree standard

		new_lines = []
		for i in self.content:
			val = i
			if '#' in i.strip():
				val = i[:i.index("#")]
			for word in val.split():
				if word[0].isalpha() and word[0].islower():
					raise Exception("A variable can't start with a lowercase character")
			val = val.replace(" ", "")
			val = val.replace("\t", "")
			if len(val) > 0:
				new_lines.append(val.strip())
		self.content = new_lines

	def run(self):
		self.clean_lines()
		for line in self.content:
			tokens = []
			print(line)
			cpy = line
			while (len(cpy)) > 0:
				if cpy.startswith("=>"):
					tokens.append(TokenSym("=>"))
					cpy = cpy[2:]
				elif cpy.startswith("<=>"):
					tokens.append(TokenSym("<=>"))
					cpy = cpy[3:]
				elif cpy[0] in "!+|^()":
					tokens.append(TokenSym(cpy[0]))
					cpy = cpy[1:]
				elif cpy[0] in "=?":
					tokens.append(TokenSpecial(cpy[0]))
					cpy = cpy[1:]
				elif cpy[0].isupper():
					l = 1
					while l < len(cpy):
						if not cpy[l].islower():
							break
						l = l + 1
					tokens.append(TokenVar(cpy[:l]))
					cpy = cpy[l:]
				else:
					raise Exception("This character never matchs : " + cpy[0] + " in this line " + cpy)
			self.tokens.append(tokens)

	def get(self):
		return self.tokens
