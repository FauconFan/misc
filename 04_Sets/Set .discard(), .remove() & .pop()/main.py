if __name__ == '__main__':
	input()
	s = set(map(int, input().split())) 
	n = input()
	for i in range(n):
		tab = input().split()
		if tab[0] == "pop":
			s.pop()
		elif tab[0] == "remove":
			s.remove(int(tab[1]))
		elif tab[0] == "discard":
			s.discard(int(tab[1]))
	print(sum(s))