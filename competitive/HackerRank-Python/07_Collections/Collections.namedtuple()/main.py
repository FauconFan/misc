from collections import namedtuple

if __name__ == "__main__":
    n = int(input())
    Stud = namedtuple('Stud', 'MARKS CLASS NAME ID')
    cols = input().split()
    listStud = []
    for _ in range(n):
        line = input().split()
        listStud.append(Stud(MARKS = int(line[cols.index('MARKS')]), CLASS = "", NAME = "", ID = ""))
    res = 0
    for elem in listStud:
        res += elem.MARKS
    print("{:.2f}".format(res / n))