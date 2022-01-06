from itertools import combinations

if __name__ == "__main__":
    line = input().split()
    word = line[0]
    word = list(word)
    word.sort()
    word = ''.join(word)
    n = int(line[1])
    for i in range(1, n + 1):
        li = list(combinations(word, i))
        for elem in li:
            print(''.join(list(elem)))