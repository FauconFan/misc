import email.utils
import re

if __name__ == "__main__":
    for _ in range(int(input())):
        user, mail = email.utils.parseaddr(input())
        m = re.match(r'(?P<first_name>[a-zA-Z][\w\.-]+)@(?P<server>[a-zA-Z]+)\.(?P<extension>[a-zA-Z]+)$', mail)
        res = True
        if m == None or bool(m) == False:
            res = False
        else:
            l = len(m.group('extension'))
            if l == 0 or l > 3:
                res = False
        if res:
            print(email.utils.formataddr((user, mail)))