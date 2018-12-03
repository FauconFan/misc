#!/usr/bin/python3

import argparse
import sys

def getDataFromFile(pathfile):
    res = {"header" : None, "contents" : []}
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
            if res["header"] is None:
                res["header"] = (data[0], data[1])
            else:
                for d in data:
                    if not d.isdigit():
                        print("Invalid data")
                        sys.exit(1)
                res["contents"].append(data)
    return res

def normalizeData(data):
    if len(data["contents"]) == 0:
        return
    min0 = data["contents"][0]
    max0 = data["contents"][0]
    min1 = data["contents"][1]
    max1 = data["contents"][1]
    for i in range(1, len(data["contents"])):
        elem0, elem1 = data["contents"][i]
        

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("file", help="pathfile of the data")
    args = parser.parse_args()

    file = args.file
    data = getDataFromFile(file)
    for d in data["contents"]:
        print(d)


if __name__ == "__main__":
    main()
