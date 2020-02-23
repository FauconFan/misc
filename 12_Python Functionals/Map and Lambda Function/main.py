cube = lambda x: x ** 3

def fibonacci(n):
    if n <= 0: return []
    elif n == 1: return [0]
    elif n == 2: return [0, 1]
    res = fibonacci(n - 1)
    size = len(res)
    return res + [res[size - 1] + res[size - 2]]
