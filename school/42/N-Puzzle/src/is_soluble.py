#!/usr/bin/python3

def build_tiles(taquin):
	ret = []
	for i in range(taquin.size):
		for j in range(taquin.size):
			ret.append(taquin.dico[(i, j)])
	return ret

def build_tiles_objective(li_objective, size_row):
	ret = [None] * (size_row * size_row)
	index = 0
	for k in (li_objective):
		x0, y0 = k
		ret[x0 * size_row + y0] = index
		index += 1
	return ret

def inversions(li):
	ret = 0
	for i in range(len(li)):
		if li[i] == 0:
			continue
		for j in range(i + 1, len(li)):
			if li[j] != 0 and li[j] < li[i]:
				ret += 1
	return ret

def is_soluble(taquin):
	start = build_tiles(taquin)
	goal = build_tiles_objective(taquin.objective, taquin.size)
	inversion_start = inversions(start)
	inversion_goal = inversions(goal)

	if (taquin.size % 2 == 0):
		inversion_start += start.index(0) // taquin.size
		inversion_goal += goal.index(0) // taquin.size

	return (inversion_start % 2 == inversion_goal % 2)
