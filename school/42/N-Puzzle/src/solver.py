#!/usr/bin/python3

from src.state import State
from src.result import Result

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
				index_right = cand - 1
		cand = max(index_right, index_left)
		if n_state.score > list_states[cand].score:
			cand += 1
		list_states.insert(cand, n_state)

def smart_insert(list_states, list_newtaquins, hash_states, state_actu):
	for t, m in list_newtaquins:
		hashed = hash(t)
		if hashed not in hash_states:
			new_history = state_actu.liste_history.copy()
			new_history.append(m)
			n_state = State(t, state_actu.taille_history + 1, new_history)
			insert_in_list(list_states, n_state)
			hash_states[hashed] = True

def solver(taquin):
	is_running = True
	list_states = []
	hash_states = {}
	list_states.append(State(taquin, 0, []))
	hash_states[hash(taquin)] = True
	result = None
	time_complexity = 1
	space_complexity = 1

	iterator = 0;

	while is_running:
		state_actu = list_states.pop(0)
		taq_actu = state_actu.taquin
		if state_actu.score == 0:
			is_running = False
			result = state_actu
		else:
			moves = taq_actu.get_possible_moves()
			time_complexity += len(moves)
			smart_insert(list_states, moves, hash_states, state_actu)
			space_complexity = max(space_complexity, len(list_states))

		iterator += 1
		if (iterator % 1000 == 0):
			print("turn " + str(iterator))

	return Result(result, time_complexity, space_complexity, iterator)
