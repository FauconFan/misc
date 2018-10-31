
import sys
from copy import deepcopy

from src.parser import parse
from src.Environment import create_table_of_truth, Environment

def disjonction(env):
    k = env.getFirstUndefined()
    envTrue = deepcopy(env)
    envFalse = deepcopy(env)
    envTrue.setEnv(k, True)
    envFalse.setEnv(k, False)
    is_ok_true = True
    is_ok_false = True
    try:
        algo(envTrue)
    except:
        is_ok_true = False
    try:
        algo(envFalse)
    except:
        is_ok_false = False
    if is_ok_true == True and is_ok_false == True:
        env.fusionUnionForDisjonction(envTrue, envFalse)
    elif is_ok_true == True:
        env.setEnv(k, True)
    elif is_ok_false == True:
        env.setEnv(k, False)
    else:
        raise Exception("Exception")


def algo(env):
    while env.stillHaveUndefined():
        copy = deepcopy(env)
        env.applyRules()
        if copy == env:
            disjonction(env)
        if copy == env:
            break

def main():
    if len(sys.argv) != 2:
        sys.exit(1)
    axioms, queries, list_rules = parse(sys.argv[1])
    # print("axioms:", axioms)
    # print("queries:", queries)
    # print("list_rules")
    # for i in list_rules:
    #     print(str(i))
    table = create_table_of_truth(list_rules, axioms)
    env = Environment(list_rules, table)
    try:
        algo(env)
    except Exception as e:
        print(e)
    print(env)

if __name__ == "__main__":
    main()
