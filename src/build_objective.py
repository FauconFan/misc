#!/usr/bin/python3

def build_objective(size):
	number = 1
	dico = {}
	ret = None
	x = 0
	y = 0
	ptr4 = {'f': lambda x, y: (x - 1, y), 'next': None}
	ptr3 = {'f': lambda x, y: (x, y - 1), 'next': ptr4}
	ptr2 = {'f': lambda x, y: (x + 1, y), 'next': ptr3}
	ptr1 = {'f': lambda x, y: (x, y + 1), 'next': ptr2}
	ptr4['next'] = ptr1
	actu = ptr1

	while number < size * size:
		dico[(x, y)] = number
		number += 1
		new_x, new_y = actu['f'](x, y)
		if (new_x < 0 or new_x >= size or new_y < 0 or new_y >= size or (new_x, new_y) in dico):
			actu = actu['next']
			new_x, new_y = actu['f'](x, y)
		x, y = new_x, new_y
	dico[(x, y)] = 0
	ret = [(0, 0)] * size * size
	for k, v in dico.items():
		ret[v] = k
	return ret
