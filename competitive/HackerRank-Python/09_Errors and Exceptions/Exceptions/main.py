if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        line = input().split()
        try:
            print(int(line[0]) // int(line[1]))
        except (ZeroDivisionError, ValueError) as e:
            print("Error Code:", e)