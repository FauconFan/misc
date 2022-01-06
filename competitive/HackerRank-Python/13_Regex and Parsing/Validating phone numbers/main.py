import re

if __name__ == "__main__":
    for _ in range(int(input())):
        str = input()
        b = bool(re.match(r'[789](\d{9})$', str))
        print("YES" if b else "NO")