import numpy

if __name__ == "__main__":
    data = list(map(int, input().split()))
    print(numpy.eye(data[0], data[1], k = 0))