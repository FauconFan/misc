
if __name__ == '__main__':
	input()
	M = set(map(int, input().split()))
	input()
	N = set(map(int, input().split()))
	P = M.difference(N).union(N.difference(M))
	list1 = list(P)
	list1.sort()
	for elem in list1:
		print(elem)
