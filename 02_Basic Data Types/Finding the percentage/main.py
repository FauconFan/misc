if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    tab = student_marks[query_name]
    avg = 0.0
    for elem in tab:
    	avg += elem
    print("{:.2f}".format(avg / len(tab)))
