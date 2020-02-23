import re

if __name__ == "__main__":
    str = input()
    sea = input()
    pattern = re.compile(sea)
    r = pattern.search(str)
    if not r:
        print("(-1, -1)")
    while r:
        print("({0}, {1})".format(r.start(), r.end() - 1))
        r = pattern.search(str,r.start() + 1)