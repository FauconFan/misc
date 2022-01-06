import math

if __name__ == "__main__":
    X = int(input())
    Y = int(input())
    print("{:}°".format(int(round(math.degrees(math.atan2(X, Y))))))