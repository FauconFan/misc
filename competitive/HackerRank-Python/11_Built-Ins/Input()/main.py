if __name__ == "__main__":
    preset = list(map(int, input().split()))
    x = preset[0]
    print(eval(input()) == preset[1])