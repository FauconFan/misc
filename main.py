
import sys
from copy import deepcopy

from src.parser import parse
from src.Environment import create_table_of_truth, Environment

def disjonction(env):
    k = env.getFirstUndefined()
    if k == None:
        return
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
    while True:
        copy = deepcopy(env)
        env.applyRules()
        if copy == env:
            disjonction(env)
        if copy == env:
            break

def answer(queries, env):
    for q in queries:
        try:
            answer = env.table_of_truth[q]
            if answer == None:
                answer = "Undefined"
            print("{} : {}".format(q, answer))
        except KeyError:
            print("This query is related to no rule")
        except Exception as e:
            print(e)

def main():
    if len(sys.argv) != 2:
        sys.exit(1)
    axioms, queries, list_rules = parse(sys.argv[1])
    # print("axioms:", axioms)
    # print("queries:", queries)
    # print("list_rules")
    # for i in list_rules:
    #     print(str(i))

    try:
        table = create_table_of_truth(list_rules, axioms)
    except Exception as e:
        print(e)
        sys.exit(1)
    env = Environment(list_rules, table)
    try:
        algo(env)
    except Exception as e:
        print(e)
    print(env)
    answer(queries, env)

if __name__ == "__main__":
    main()
