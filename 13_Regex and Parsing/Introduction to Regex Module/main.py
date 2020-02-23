import re

if __name__ == "__main__":
    for _ in range(int(input())):
        s = input()
        ans = True
        if bool(re.match(r"^[\+\-]?\d*\.\d+$", s)) == False:
            ans = False
        try:
            float(s)
        except:
            ans = False
        print(ans)
