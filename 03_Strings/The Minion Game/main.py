
def minion_game(string):
    list_substring = []
    score_stuart = 0
    score_kevin = 0
    for i in range(0, len(string)):
        add = len(string) - i
        if string[i] in ['A', 'E', 'I', 'O', 'U']:
        	score_kevin += add
        else:
        	score_stuart += add
    if score_stuart > score_kevin :
        print("Stuart {:d}".format(score_stuart))
    elif score_stuart < score_kevin:
        print("Kevin {:d}".format(score_kevin))
    else:
        print("Draw")
