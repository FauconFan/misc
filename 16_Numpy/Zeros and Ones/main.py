import numpy

if __name__ == "__main__":
    data = tuple(map(int, input().split()))
    print(numpy.zeros(data, dtype = numpy.int))
    print(numpy.ones(data, dtype = numpy.int))