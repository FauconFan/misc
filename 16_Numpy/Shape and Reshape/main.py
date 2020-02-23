import numpy

if __name__ == "__main__":
    n, m = list(map(int, input().split()))
    source = " ".join(input() for _ in range(n))
    matrix1 = numpy.array(source.split(), int)
    matrix1 = numpy.reshape(matrix1, (n, m))
    
    source = " ".join(input() for _ in range(n))
    matrix2 = numpy.array(source.split(), int)
    matrix2 = numpy.reshape(matrix2, (n, m))
    
    for i in ['+','-','*','//','%','**']:
        print(eval('matrix1' + i + 'matrix2'))
