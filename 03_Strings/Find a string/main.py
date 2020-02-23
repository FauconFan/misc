def count_substring(string, sub_string):
    res = 0
    for i in range(len(string) - len(sub_string) + 1):
        b = 1
        for j in range(len(sub_string)):
            if string[i + j] != sub_string[j]:
                b = 0
                break
        if b == 1:
            res += 1
    return res