import re

if __name__ == "__main__":
    s = input()
    c = "-1"
    m = re.search(r'([a-zA-Z0-9])\1+', s)
    if m :
        c = m.group(1)
    print(c)