#!/usr/bin/python3

from state import State

def smart_insert(list_states, list_newtaquins, hash_states, state_actu):
	for t, m in list_newtaquins:
		hash_t = hash(t)
		if hash_t not in hash_states:
			state_actu.liste_history.append(m)
			n_state = State(t, state_actu.taille_history + 1, state_actu.liste_history)
			list_states.append(n_state)
			hash_states.append(hash_t)
	list_states.sort()

def solver(taquin):
	is_running = True
	list_states = []
	hash_states = []
	list_states.append(State(taquin, 0, []))
	hash_states.append(hash(taquin))
	result = None

	iterator = 0;

	while is_running:
		print("size states : " + str(len(list_states)))
		state_actu = list_states.pop(0)
		# print(state_actu)
		taq_actu = state_actu.taquin
		if state_actu.score == 0:
			is_running = False
			result = taq_actu
		else:
			moves = taq_actu.get_possible_moves()
			smart_insert(list_states, moves, hash_states, state_actu)

		# print("turn " + str(iterator))
		# for s in list_states:
		# 	print(s)
		# if iterator >= 2:
		# 	is_running = False
		# iterator += 1

	print(result)
