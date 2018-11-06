
import sys

def log_helper():
    s = "set Verbosity level.\n"
    s += "(0) -> Just print the result. (default)\n"
    s += "(1) -> Print choices of the algorithm at every step.\n"
    s += "(2) -> Print table of truth at every step.\n"
    return s

def log_set_interactive():
    logconfig.interactive = True

def log_set_verbose(v):
    logconfig.verbose = v

def logconfig():
    logconfig.c = logconfig.c + 1
    if logconfig.verbose >= 1:
        print("Step %d:" % logconfig.c)
        print("Depth %d:" % logconfig.depthdij)

logconfig.c = 0
logconfig.interactive = False
logconfig.verbose = 0
logconfig.depthdij = 0

def loginteractive():
    if logconfig.interactive:
        print("Press enter to go next:")
        while True:
            try:
                input()
                break
            except:
                print()


def print_with_depth(li):
    if logconfig.verbose >= 1:
        real_li = []
        for i in li:
            for j in i.split("\n"):
                if j != "":
                    real_li.append(j)
        if logconfig.depthdij == 0:
            for i in real_li:
                print(i)
        else:
            for i in real_li:
                print("%s %s" % ("+" * logconfig.depthdij, i))

def log(env, s, formula):
    if len(s) > 0:
        logconfig()

        li = []
        li.append("From this formula : %s" % str(formula))
        li.append("We know:")
        for dd in s:
            li.append("\t%s is %s" % (dd, str(env.getEnv(dd))))
        if logconfig.verbose >= 2:
            li.append(env.StrTableOfTruth())
        print_with_depth(li)
        loginteractive()

def logdijunction(env, str):
    logconfig()
    li = []
    li.append("We cannot deduce anything from the sets of rules...")
    li.append("So we are doing a dijunction on the variable %s" % str)
    if logconfig.verbose >= 2:
        li.append(env.StrTableOfTruth())
    print_with_depth(li)
    logconfig.depthdij = logconfig.depthdij + 1
    loginteractive()

def logdijunctionValue(env, s, value):
    logconfig()
    li = []
    li.append("We suppose that %s is %s" % (s, str(value)))
    if logconfig.verbose >= 2:
        li.append(env.StrTableOfTruth())
    print_with_depth(li)
    loginteractive()

def logdijunctionMessage(msg, msgVerbose = None):
    logconfig()
    li = []
    li.append(msg)
    if logconfig.verbose >= 2 and msgVerbose != None:
        li.append(msgVerbose)
    print_with_depth(li)
    loginteractive()

def logdijunctionend():
    logconfig.depthdij = logconfig.depthdij - 1
