import numpy as np

if __name__ == "__main__":
    n, m, p = map(int, input().split())
    source = " ".join(input() for _ in range(n))
    matrix1 = np.array(source.split(), int)
    matrix1.shape = (n, p)

    source = " ".join(input() for _ in range(m))
    matrix2 = np.array(source.split(), int)    
    matrix2.shape = (m, p)

    print(np.concatenate((matrix1, matrix2), axis = 0))