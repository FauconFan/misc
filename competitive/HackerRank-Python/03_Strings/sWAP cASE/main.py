import string

def swap_case(s):
    res = ""
    for c in s:
        if c in string.ascii_lowercase:
            res += c.upper()
        elif c in string.ascii_uppercase:
            res += c.lower()
        else:
            res += c
    return res
