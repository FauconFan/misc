if __name__ == '__main__':
    N = int(input())
    list = []
    str = ""
    index = 0
    while index < N:
        str = input()
        tab = str.split()
        if tab[0] == "insert":
        	list.insert(int(tab[1]), int(tab[2]))
        elif tab[0] == "print":
        	print(list)
        elif tab[0] == "remove":
        	list.remove(int(tab[1]))
        elif tab[0] == "append":
        	list.append(int(tab[1]))
        elif tab[0] == "sort":
        	list.sort()
        elif tab[0] == "pop":
        	list.pop()
        elif tab[0] == "reverse":
        	list.reverse()
        index += 1
