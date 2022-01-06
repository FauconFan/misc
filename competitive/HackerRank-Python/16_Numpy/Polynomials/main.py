import numpy

if __name__ == "__main__":
    pol = list(map(float, input().split()))
    x = float(input())
    print(numpy.polyval(pol, x))