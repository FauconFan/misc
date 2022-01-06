import numpy

if __name__ == "__main__":
    n, m = list(map(int, input().split()))
    source = " ".join(input() for _ in range(n))
    matrix1 = numpy.array(source.split(), int)
    
    source = " ".join(input() for _ in range(n))
    matrix2 = numpy.array(source.split(), int)
    
    for i in ['+','-','*','//','%','**']:
        print("[{:}]".format(eval('matrix1' + i + 'matrix2')), sep='\n')