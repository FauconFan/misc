import numpy as np

if __name__ == "__main__":
    n = int(input())
    source = " ".join(input() for _ in range(n))
    matrix1 = np.array(source.split(), int)
    matrix1.shape = (n, n)
    
    source = " ".join(input() for _ in range(n))
    matrix2 = np.array(source.split(), int)
    matrix2.shape = (n, n)
    
    print(np.dot(matrix1, matrix2))