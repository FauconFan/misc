if __name__ == '__main__':
    n = int(input())
    b = -1
    if n % 2 == 1:
        b = 1
    else:
        if n >= 2 and n <= 5:
            b = 0
        elif n >= 6 and n <= 20:
            b = 1
        else:
            b = 0
    if b == 1:
        print("Weird")
    elif b == 0:
        print("Not Weird")
