if __name__ == '__main__':
    tab = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        tab.append([name, score])
    min = tab[0][1]
    res = 0
    index = 1
    while index < len(tab):
    	if min != tab[index][1]:
    		if min > tab[index][1]:
    			res = min
    			min = tab[index][1]
    		else:
    			res = tab[index][1]
    		break
    	index += 1
    index += 1
    while index < len(tab):
    	if tab[index][1] != min and tab[index][1] != res:
    		if tab[index][1] < min:
    			res = min
    			min = tab[index][1]
    		elif tab[index][1] < res:
    			res = tab[index][1]
    	index += 1
    names = []
    for elem in tab:
    	if elem[1] == res:
    		names.append(elem[0])
    names.sort()
    for elem in names:
    	print(elem)
