#!/usr/bin/python3

from state import State
import sys

def insert_in_list(list_states, n_state):
	# Insertion par recherche dichotomique
	
	index_left = 0
	index_right = len(list_states) - 1
	if (len(list_states) == 0):
		list_states.append(n_state)
	else:
		while index_left < index_right:
			cand = (index_right + index_left) // 2
			if n_state.score > list_states[cand].score:
				index_left = cand + 1
			else:
				index_right = cand
		cand = max(index_right, index_left)
		list_states.insert(cand, n_state)

def smart_insert(list_states, list_newtaquins, hash_states, state_actu):
	for t, m in list_newtaquins:
		if t.hash() not in hash_states:
			state_actu.liste_history.append(m)
			n_state = State(t, state_actu.taille_history + 1, state_actu.liste_history)
			insert_in_list(list_states, n_state)
			hash_states[t.hash()] = True

def solver(taquin):
	is_running = True
	list_states = []
	hash_states = {}
	list_states.append(State(taquin, 0, []))
	hash_states[taquin.hash()] = True
	result = None

	iterator = 0;

	while is_running:
		# print("size states : " + str(len(list_states)))
		state_actu = list_states.pop(0)
		# print(state_actu)
		# print(state_actu.taquin.hash())
		# print(hash_states)
		taq_actu = state_actu.taquin
		if state_actu.score == 0:
			is_running = False
			result = taq_actu
		else:
			moves = taq_actu.get_possible_moves()
			smart_insert(list_states, moves, hash_states, state_actu)

		if (iterator % 1000 == 0):
			print("turn " + str(iterator))
		# for s in list_states:
		# 	print(s)
		# if iterator >= 2:
		# 	is_running = False
		iterator += 1
		# input()

	print(iterator)
	print(result)
