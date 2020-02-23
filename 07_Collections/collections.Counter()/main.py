from collections import Counter

if __name__ == "__main__":
    input()
    cnt = Counter(list(map(int, input().split())))
    n = int(input())
    res = 0
    for _ in range(n):
        line = list(map(int, input().split()))
        if cnt[line[0]] != 0:
            res += line[1]
            cnt[line[0]] -= 1
    print(res)