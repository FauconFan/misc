import re

if __name__ == "__main__":
    str = input()
    cons = '[qwrtypsdfghjklzxcvbnm]'
    tab = re.findall('(?<=' + cons +')([aeiou]{2,})' + cons, str, re.I)
    print('\n'.join(tab or ['-1']))²