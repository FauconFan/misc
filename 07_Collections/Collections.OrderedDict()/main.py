from collections import OrderedDict

if __name__ == "__main__":
    od = OrderedDict()
    n = int(input())
    for _ in range(n):
        line = input().split()
        name = ' '.join(line[:-1])
        value = int(line[-1])
        if name in od:
            od[name] += value
        else :
            od[name] = value
    for elem in od:
        print("{:} {:}".format(elem, od[elem]))