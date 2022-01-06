def ln(n):
    if (n < 10) : return 1
    return 1 + ln(n // 10)

def addnext(x, n):
    return x * (10 ** ln(n)) + n

if __name__ == '__main__':
    n = int(input())
    i = 1
    res = 0
    while (i <= n):
        res = addnext(res, i)
        i += 1
    print(res)
