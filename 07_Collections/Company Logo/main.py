from collections import Counter, OrderedDict

class OrderedCounter(Counter, OrderedDict):
    pass

if __name__ == "__main__":
    list = OrderedCounter(sorted(input())).most_common(3)
    for c in list:
        print(*c)