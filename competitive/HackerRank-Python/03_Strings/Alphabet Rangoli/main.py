import string

def print_rangoli(size):
    tab = []
    for index in range(0, size):
        str = string.ascii_lowercase[size - 1 - index]
        for i in range(1, index + 1):
            str = string.ascii_lowercase[size - 1 - index + i] + "-" + str + "-" + string.ascii_lowercase[size - 1 - index + i]
        tab.append(str.center(4 * (size - 1) + 1, "-"))
    for i in range(size):
        print(tab[i])
    for i in range(1, size):
        print(tab[size - 1 - i])
