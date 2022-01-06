from collections import OrderedDict

if __name__ == "__main__":
    d = OrderedDict()
    n = int(input())
    for _ in range(n):
        str = input()
        if str in d:
            d[str] += 1
        else:
            d[str] = 1
    print(len(d))
    for elem in d:
        print(d[elem], end = " ")