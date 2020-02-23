import re

n, m = map(int,input().split())
matrix = []
for _ in range(n):
    matrix.append(input()+' ')
s = ''.join(matrix[i][j] for j in range(m) for i in range(n))
s1 = re.sub(r'(?<=[a-zA-Z0-9])[^a-zA-Z0-9]+(?=[a-zA-Z0-9])', ' ', s)
print(s1)