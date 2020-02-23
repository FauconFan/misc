#!/bin/python3

from operator import itemgetter

if __name__ == "__main__":
    n, m = input().split(' ')
    n, m = [int(n), int(m)]
    arr = []
    for arr_i in range(n):
        arr_t = [int(arr_temp) for arr_temp in input().strip().split(' ')]
        arr.append(arr_t)
    k = int(input())
    arr = sorted(arr, key = itemgetter(k))
    for elem in arr:
        print(*elem)
