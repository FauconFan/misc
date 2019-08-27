#!/usr/bin/python

import lldb
import commands
import subprocess
import os
import random
import time

la = ["          ", "          ", "  /$$$$$$ ", " |____  $$", "  /$$$$$$$", " /$$__  $$", "|  $$$$$$$", " \\_______/", "          ", "          ", "          "]
lb = ["  /$$     ", "| $$      ", "| $$$$$$$ ", "| $$__  $$", "| $$  \\ $$", "| $$  | $$", "| $$$$$$$/", "|_______/ ", "          ", "          ", "          "]
lc = ["          ", "          ", "  /$$$$$$$", " /$$_____/", "| $$      ", "| $$      ", "|  $$$$$$$", " \\_______/", "          ", "          ", "          "]
ld = ["        /$$", "      | $$ ", "  /$$$$$$$ ", " /$$__  $$ ", "| $$  | $$ ", "| $$  | $$ ", "|  $$$$$$$ ", " \\_______/ ", "           ", "           ", "           "]
le = ["          ", "          ", "  /$$$$$$ ", " /$$__  $$", "| $$$$$$$$", "| $$_____/", "|  $$$$$$$", " \\_______/", "          ", "          ", "          "]
lf = ["   /$$$$$$", " /$$__  $$", "| $$  \\__/", "| $$$$    ", "| $$_/    ", "| $$      ", "| $$      ", "|__/      ", "          ", "          ", "          "]
lg = ["          ", "          ", "  /$$$$$$ ", " /$$__  $$", "| $$  \\ $$", "| $$  | $$", "|  $$$$$$$", " \\____  $$", " /$$  \\ $$", "|  $$$$$$/", " \\______/ "]
lh = ["  /$$     ", "| $$      ", "| $$$$$$$ ", "| $$__  $$", "| $$  \\ $$", "| $$  | $$", "| $$  | $$", "|__/  |__/", "          ", "          ", "          "]
li = ["  /$$", "|__/ ", " /$$ ", "| $$ ", "| $$ ", "| $$ ", "| $$ ", "|__/ ", "     ", "     ", "     "]
lj = ["          ", "          ", "       /$$", "      |__/", "       /$$", "      | $$", "      | $$", "      | $$", " /$$  | $$", "|  $$$$$$/", " \\______/ "]
lk = ["  /$$     ", "| $$      ", "| $$   /$$", "| $$  /$$/", "| $$$$$$/ ", "| $$_  $$ ", "| $$ \\  $$", "|__/  \\__/", "          ", "          ", "          "]
ll = ["  /$$", "| $$ ", "| $$ ", "| $$ ", "| $$ ", "| $$ ", "| $$ ", "|__/ ", "     ", "     ", "     "]
lm = ["              ", "              ", " /$$$$$$/$$$$ ", "| $$_  $$_  $$", "| $$ \\ $$ \\ $$", "| $$ | $$ | $$", "| $$ | $$ | $$", "|__/ |__/ |__/", "              ", "              ", "              "]
ln = ["          ", "          ", " /$$$$$$$ ", "| $$__  $$", "| $$  \\ $$", "| $$  | $$", "| $$  | $$", "|__/  |__/", "          ", "          ", "          "]
lo = ["          ", "          ", "  /$$$$$$ ", " /$$__  $$", "| $$  \\ $$", "| $$  | $$", "|  $$$$$$/", " \\______/ ", "          ", "          ", "          "]
lp = ["          ", "          ", "  /$$$$$$ ", " /$$__  $$", "| $$  \\ $$", "| $$  | $$", "| $$$$$$$/", "| $$____/ ", "| $$      ", "| $$      ", "|__/      "]
lq = ["          ", "          ", "  /$$$$$$ ", " /$$__  $$", "| $$  \\ $$", "| $$  | $$", "|  $$$$$$$", " \\____  $$", "      | $$", "      | $$", "      |__/"]
lr = ["          ", "          ", "  /$$$$$$ ", " /$$__  $$", "| $$  \\__/", "| $$      ", "| $$      ", "|__/      ", "          ", "          ", "          "]
ls = ["          ", "          ", "  /$$$$$$$", " /$$_____/", "|  $$$$$$ ", " \\____  $$", " /$$$$$$$/", "|_______/ ", "          ", "          ", "          "]
lt = ["    /$$   ", "  | $$    ", " /$$$$$$  ", "|_  $$_/  ", "  | $$    ", "  | $$ /$$", "  |  $$$$/", "   \\___/  ", "          ", "          ", "          "]
lu = ["          ", "          ", " /$$   /$$", "| $$  | $$", "| $$  | $$", "| $$  | $$", "|  $$$$$$/", " \\______/ ", "          ", "          ", "          "]
lv = ["           ", "           ", " /$$    /$$", "|  $$  /$$/", " \\  $$/$$/ ", "  \\  $$$/  ", "   \\  $/   ", "    \\_/    ", "           ", "           ", "           "]
lw = ["              ", "              ", " /$$  /$$  /$$", "| $$ | $$ | $$", "| $$ | $$ | $$", "| $$ | $$ | $$", "|  $$$$$/$$$$/", " \\_____/\\___/ ", "              ", "              ", "              "]
lx = ["          ", "          ", " /$$   /$$", "|  $$ /$$/", " \\  $$$$/ ", "  >$$  $$ ", " /$$/\\  $$", "|__/  \\__/", "          ", "          ", "          "]
ly = ["          ", "          ", " /$$   /$$", "| $$  | $$", "| $$  | $$", "| $$  | $$", "|  $$$$$$$", " \\____  $$", " /$$  | $$", "|  $$$$$$/", " \\______/ "]
lz = ["          ", "          ", " /$$$$$$$$", "|____ /$$/", "   /$$$$/ ", "  /$$__/  ", " /$$$$$$$$", "|________/", "          ", "          ", "          "]

alphabet = [la, lb, lc, ld, le, lf, lg, lh, li, lj, lk, ll, lm, ln, lo, lp, lq, lr, ls, lt, lu, lv, lw, lx, ly, lz]

## To generate all colors and choose
# import subprocess
# 
# sgr0 = subprocess.check_output(['tput', 'sgr0'])
# sgr0 = sgr0.decode()
# 
# for i in range(255):
#     actu = subprocess.check_output(['tput', 'setaf', str(i)])
#     actu = actu.decode()
#     print('For i = {} => normal{}text{}normal'.format(i, actu, sgr0))

def __getcolor(tag):
    actu = subprocess.check_output(['tput', 'setaf', str(tag)])
    actu = actu.decode()
    return (actu)

def __getsgr0():
    actu = subprocess.check_output(['tput', 'sgr0'])
    actu = actu.decode()
    return (actu)


SGR0 = __getsgr0()

# Must be of length 11
## It corresponds to a color by line
COLORS_LINES = []

random.seed(time.time())
random_base = random.randint(0, 28)
base = random_base * 6 + 58

for i in range(11):
    actu = base
    if i % 2 == 1:
        actu -= 36
    actu += i // 2
    COLORS_LINES.append(__getcolor(actu))

def __check_string(name):
    ca = ord('a')
    cz = ord('z')
    for ch in name:
        cc = ord(ch)
        if cc < ca or cc > cz:
            return False
    return True

def __print_name(name):
    if __check_string(name) == False:
        name = "nope"
    tab = []
    for _ in la:
        tab.append("\t\t")
    for ch in name:
        index = ord(ch) - ord('a')
        i = 0
        for line in alphabet[index]:
            tab[i] = tab[i] + line
            i = i + 1
    for i in range(11):
        print('{}{}{}'.format(COLORS_LINES[i], tab[i], SGR0))

# And the initialization code to add your commands
def __lldb_init_module(debugger, internal_dict):
    login = os.getenv("USER")
    __print_name(login)
    debugger.SetPrompt("(" + login + ") ")
