#!/usr/bin/python3

from enum import Enum

class Movement(Enum):
	UP = 1
	RIGHT = 2
	DOWN = 3
	LEFT = 4

	def __str__(self):
		return self.name

class Taquin(object):
	"""docstring for Taquin"""
	def __init__(self, size, dico, objective = None):
		# size of the taquin
		self.size = size
		# (x, y) -> value between 1 and size * size - 1
		self.dico = dico
		# objective to calculate the score
		self.objective = objective
		# ptr function for scoring
		self.function_score = self.score_right_position
		# Set score to None
		self.score_int = None

	def __str__(self):
		s = ""
		for i in range(self.size):
			for j in range(self.size):
				s += str(self.dico[(i, j)]) + " "
			s += "\n"
		return s

	def __hash__(self):
		hashed = 0
		m = self.size * self.size
		for i in range(self.size):
			for j in range(self.size):
				hashed = hashed * m + self.dico[(i, j)]
		return hashed

	def clone(self):
		ret = Taquin(self.size, self.dico.copy(), objective = self.objective)
		return ret

	def find_case(self, value):
		for i in range(0, self.size):
			for j in range(0, self.size):
				id = self.dico[(i, j)]
				if id is value:
					return (i, j)
		return (-1, -1)

	def get_right_positions(self, value):
		return self.objective[value]

	def swap_values(self, x1, y1, x2, y2):
		tmp = self.dico[(x1, y1)]
		self.dico[(x1, y1)] = self.dico[(x2, y2)]
		self.dico[(x2, y2)] = tmp

	def get_possible_moves(self):
		def build_new_taquin(x1, y1, x2, y2):
			cl = self.clone()
			next_score = self.score()
			next_score -= cl.function_score(x1, y1)
			next_score -= cl.function_score(x2, y2)
			cl.swap_values(x1, y1, x2, y2)
			next_score += cl.function_score(x1, y1)
			next_score += cl.function_score(x2, y2)
			cl.score_int = next_score
			return cl

		x0, y0 = self.find_case(0)
		ret = []
		if x0 > 0:
			cl = build_new_taquin(x0, y0, x0 - 1, y0)
			ret.append((cl, Movement.UP))
		if y0 > 0:
			cl = build_new_taquin(x0, y0, x0, y0 - 1)
			ret.append((cl, Movement.LEFT))
		if x0 < self.size - 1:
			cl = build_new_taquin(x0, y0, x0 + 1, y0)
			ret.append((cl, Movement.DOWN))
		if y0 < self.size - 1:
			cl = build_new_taquin(x0, y0, x0, y0 + 1)
			ret.append((cl, Movement.RIGHT))
		return ret

	""" Score avec la distance manhattan """
	def score_manhattan(self, i, j):
		real_x, real_y = self.get_right_positions(self.dico[(i, j)])
		return (abs(real_x - i) + abs(real_y - j))

	def score_right_position(self, i, j):
		if self.objective[self.dico[i,j]] == (i, j):
			return 0
		return 1

	# def score

	def score(self):
		if (self.score_int == None):
			self.score_int = 0
			for i in range(self.size):
				for j in range(self.size):
					self.score_int += self.function_score(i, j)
		return self.score_int
