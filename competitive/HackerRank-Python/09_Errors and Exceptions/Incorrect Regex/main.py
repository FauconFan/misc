import re

if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        ans = True
        try :
            reg = re.compile(input())
        except:
            ans = False
        print(ans)