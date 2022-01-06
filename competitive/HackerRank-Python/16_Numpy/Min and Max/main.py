import numpy as np

if __name__ == "__main__":
    n, m = list(map(int, input().split()))
    source = " ".join(input() for _ in range(n))
    matrix1 = np.array(source.split(), int)
    matrix1.shape = (n, m)
    
    print(np.max(np.min(matrix1, axis = 1)))