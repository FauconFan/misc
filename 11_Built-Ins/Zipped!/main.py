if __name__ == "__main__":
    data = list(map(int, input().split()))
    tab_tot = []
    for _ in range(data[1]):
        tab_tot.append(list(map(float, input().split())))
    for elem in zip(*tab_tot):
        print(sum(elem) / len(elem))