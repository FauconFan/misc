from collections import defaultdict

if __name__ == "__main__":
    d = defaultdict(list)
    line = list(map(int, input().split()))
    for i in range(1, line[0] + 1):
        d[input()].append(i)
    for j in range(line[1]):
        index = input()
        if d[index] == []:
            print(-1)
        else:
            print(*d[index])