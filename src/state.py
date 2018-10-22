#!/usr/bin/python3

class State(object):
	"""docstring for state"""
	def __init__(self, taquin, taille_history, liste_history):
		self.taquin = taquin
		self.taille_history = taille_history
		self.liste_history = liste_history
		self.score = taquin.score()

	def __lt__(self, other):
		return self.score < other.score

	def __str__(self):
		s = ""
		s += str(self.taquin)
		s += "size history : " + str(self.taille_history) + "\n"
		s += "score : " + str(self.score) + "\n"
		return s
