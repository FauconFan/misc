import calendar

if __name__ == "__main__":
    line = list(map(int, input().split()))
    index = calendar.weekday(line[2], line[0], line[1])
    print(calendar.day_name[index].upper())