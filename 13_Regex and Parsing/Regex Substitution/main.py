import re

if __name__ == "__main__":
    for _ in range(int(input())):
        str = input()
        while 1:
            cpy = re.sub(" \&\& ", lambda x : " and ", str)
            if cpy == str:
                break
            str = cpy
        while 1:
            cpy = re.sub(" \|\| ", lambda x : " or ", str)
            if cpy == str:
                break
            str = cpy
        print(str)