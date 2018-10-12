#!/usr/bin/python3

class State(object):
	"""docstring for state"""
	def __init__(self, taquin, taille_history, liste_history):
		self.taquin = taquin
		self.taille_history = taille_history
		self.liste_history = liste_history
		self.score = taquin.score()

	# def clone(self):
	# 	return State(self.taquin.clone(), self.taille_history, self.liste_history.copy())