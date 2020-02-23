import re

if __name__ == "__main__":
    str = input()
    print(bool(re.match(r'M{,3}(C{,3}|CD|DC{,3}|CM)(X{,3}|XL|LX{,3}|XC)(I{,3}|IV|VI{,3}|IX)$', str)))