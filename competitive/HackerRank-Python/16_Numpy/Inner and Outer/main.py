import numpy as np

if __name__ == "__main__":
    A = np.array(list(map(int, input().split())))
    B = np.array(list(map(int, input().split())))
    
    print(np.inner(A, B))
    print(np.outer(A, B))