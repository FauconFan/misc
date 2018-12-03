
import sys

def getDataFromFile(pathfile):
    header = None
    contents = []
    with open(pathfile, 'r') as file:
        while True:
            line = file.readline()
            if len(line) == 0:
                break
            if line[-1] is '\n':
                line = line[:-1]
            data = line.split(',')
            if len(data) != 2:
                print("Invalid data")
                sys.exit(1);
            if header is None:
                header = (data[0], data[1])
            else:
                for d in data:
                    if not d.isdigit():
                        print("Invalid data")
                        sys.exit(1)
                idata = []
                for d in data:
                    idata.append(float(d))
                contents.append(idata)
    if header is None:
        print("Can't have empty file")
        sys.exit(1)
    if len(contents) <= 1:
        print("Must have at least 2 values in the csv")
        sys.exit(1)
    return (header, contents)

class Data():
    def __init__(self, pathfile):
        (header, contents) = getDataFromFile(pathfile)
        self.header = header
        self.contents = contents
        self.isNormalise = False
        # This stands for min0, max0, min1, max1
        self.metaNorm = (None, None, None, None)

    def normalise(self):
        if self.isNormalise:
            return
        def update(min, max, elem):
            if min > elem:
                min = elem
            elif max < elem:
                max = elem
            return (min, max)
        self.isNormalise = True
        min0 = self.contents[0][0]
        max0 = self.contents[0][0]
        min1 = self.contents[0][1]
        max1 = self.contents[0][1]
        for i in range(1, len(self.contents)):
            elem0, elem1 = self.contents[i]
            (min0, max0) = update(min0, max0, elem0)
            (min1, max1) = update(min1, max1, elem1)
        self.metaNorm = (min0, max0, min1, max1)
        print(self.metaNorm)
        e0 = max0 - min0
        e1 = max1 - min1
        for i in range(len(self.contents)):
            (x, y) = self.contents[i]
            x = (x - min0) / e0
            y = (y - min1) / e1
            self.contents[i] = (x, y)

    def unnormalise(self):
        if not self.isNormalise:
            return
        self.isNormalise = False
        (min0, max0, min1, max1) = self.metaNorm
        self.metaNorm = (None, None, None, None)
        e0 = max0 - min0
        e1 = max1 - min1
        for i in range(len(self.contents)):
            (x, y) = self.contents[i]
            x = x * e0 + min0
            y = y * e1 + min1
            self.contents[i] = (x, y)

    def getnormedt0t1(self, t0, t1):
        if not self.isNormalise:
            return (t0, t1)
        (min0, max0, min1, max1) = self.metaNorm
        e0 = max0 - min0
        e1 = max1 - min1
        t1 = (e1 / e0) * t1
        t0 = - (e1 / e0) * min0 + e1 * t0 + min1
        return (t0, t1)
