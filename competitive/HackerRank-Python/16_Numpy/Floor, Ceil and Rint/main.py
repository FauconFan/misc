import numpy

if __name__ == "__main__":
    li = numpy.array(list(map(float, input().split())))
    print(numpy.floor(li))
    print(numpy.ceil(li))
    print(numpy.rint(li))