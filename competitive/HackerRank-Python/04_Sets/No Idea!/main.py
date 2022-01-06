if __name__ == '__main__':
	input()
	list1 = list(map(int, input().split()))
	A = set(map(int, input().split()))
	B = set(map(int, input().split()))
	happiness = 0
	for elem in list1:
		if elem in A:
			happiness += 1
		if elem in B:
			happiness -= 1
	print(happiness)
