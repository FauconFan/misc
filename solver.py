#!/usr/bin/python3

from state import State

def smart_insert(list_states, list_newtaquins, hash_states, state_actu):
	for t, m in list_newtaquins:
		if t.hash() not in hash_states:
			state_actu.liste_history.append(m)
			n_state = State(t, state_actu.taille_history + 1, state_actu.liste_history)
			list_states.append(n_state)
			hash_states[t.hash()] = True
	list_states.sort()

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
