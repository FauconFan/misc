from itertools import product

def func(nums):
    return sum(x*x for x in nums) % M

if __name__ == "__main__":
    K, M = [int(x) for x in input().split()]
    arrayN = []
    for _ in range(K):
        arrayN.append([int(x) for x in input().split()[1:]])
    possible_combination = list(product(*arrayN))
    print(max(list(map(func, possible_combination))))