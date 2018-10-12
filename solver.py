#!/usr/bin/python3

from state import State

def smart_insert

def solver(taquin):
	is_running = True
	list_states = []
	list_states.append(State(taquin, 0, []))

	while is_running:
		state_actu = list_states.pop()
		taq_actu = state_actu.taquin
		if state_actu.score == 0:
			is_running = False
		else:
			moves = taq_actu.get_possible_moves()
			for t, m in moves:
				print(m)
				print(t)

		is_running = False