from itertools import combinations

if __name__ == "__main__":
    input()
    tab = list(input().split())
    k = int(input())
    li = list(combinations(tab, k))
    nb = 0
    actu = 0
    for elem in li:
        nb += 1
        if 'a' in list(elem):
            actu += 1
    print(actu / nb)