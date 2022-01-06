from itertools import groupby

if __name__ == "__main__":
    s = input()
    tab = groupby(s, int)
    for x, y in tab:
        print("({:}, {:}) ".format(len(list(y)), x), end = "")