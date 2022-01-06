import numpy as np

if __name__ == "__main__":
    n = int(input())
    source = " ".join(input() for _ in range(n))
    matrix1 = np.array(source.split(), float)
    matrix1.shape = (n, n)
    
    print(np.linalg.det(matrix1))