#!/usr/bin/python3

class Taquin(object):
	"""docstring for Taquin"""
	def __init__(self, size, dico):
		# size of the taquin
		self.size = size
		# (x, y) -> value between 1 and size * size - 1
		self.dico = dico

	def __str__(self):
		s = ""
		for i in range(self.size):
			for j in range(self.size):
				s += str(self.dico[(i, j)]) + " "
			s += "\n"
		return s

	def clone(self):
		ret = Taquin(self.size, self.dico.copy())
		return ret

	def find_case(self, value):
		for i in range(0, self.size):
			for j in range(0, self.size):
				id = self.dico[(i, j)]
				if id is value:
					return (i, j)
		return (-1, -1)

	def get_right_positions(self, value):
		if value is 0:
			return (self.size - 1, self.size - 1)
		x = (value - 1) // self.size
		y = (value - 1) % self.size
		return x, y

	def swap_values(self, x1, y1, x2, y2):
		tmp = self.dico[(x1, y1)]
		self.dico[(x1, y1)] = self.dico[(x2, y2)]
		self.dico[(x2, y2)] = tmp