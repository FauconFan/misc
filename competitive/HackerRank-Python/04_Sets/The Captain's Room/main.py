if __name__ == "__main__":
    k = int(input())
    arr = list(map(int, input().split()))
    s = set(arr)
    sum_tot = sum(s) * k - sum(arr)
    print(sum_tot // (k - 1))