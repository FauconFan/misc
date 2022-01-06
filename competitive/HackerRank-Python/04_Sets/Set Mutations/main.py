if __name__ == "__main__":
    input()
    A = set(map(int, input().split()))
    n = int(input())
    for i in range(n):
        cmd = (input().split())[0]
        B = set(map(int, input().split()))
        if cmd == "intersection_update":
            A.intersection_update(B)
        elif cmd == "difference_update":
            A.difference_update(B)
        elif cmd == "symmetric_difference_update":
            A.symmetric_difference_update(B)
        elif cmd == "update":
            A.update(B)
    print(sum(A))