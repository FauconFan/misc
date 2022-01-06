from itertools import permutations

if __name__ == "__main__":
    line = input().split()
    word = line[0]
    word = list(word)
    word.sort()
    word = ''.join(word)
    n = int(line[1])
    li = list(permutations(word, n))
    for elem in li:
        print(''.join(list(elem)))