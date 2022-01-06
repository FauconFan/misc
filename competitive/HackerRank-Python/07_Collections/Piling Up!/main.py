from collections import deque

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        input()
        d = deque(list(map(int, input().split())))
        arr = []
        Y = 1
        while len(d) != 0:
            actu = d[0]
            what = 1
            if d[-1] > actu:
                actu = d[-1]
                what = 0
            if what == 1:
                d.pop()
            else:
                d.popleft()
            if arr == []:
                arr.append(actu)
            else:
                if arr[-1] < actu:
                    Y = 0
                    break
                else:
                    arr.append(actu)
        if Y == 1:
            print("Yes")
        else:
            print("No")
                