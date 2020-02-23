import numpy

if __name__ == "__main__":
    n, m = list(map(int, input().split()))
    li = []
    for _ in range(n):
        li.append(list(map(int, input().split())))
    print(numpy.transpose(li))
    print(numpy.array(li).flatten())