from itertools import product

if __name__ == "__main__":
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    pc = list(product(A, B))
    for elem in pc:
        print("{:} ".format(elem), end = "")