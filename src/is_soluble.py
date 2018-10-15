#!/usr/bin/python3

def d_manhattan(x1, y1, x2, y2):
    return abs(x2 - x1) + abs(y2 - y1)

def calculate_modif_succ_vide(taquin):
    size = taquin.size
    i0, j0 = taquin.find_case(0);
    tx0, ty0 = taquin.get_right_positions(0);
    return d_manhattan(i0, j0, tx0, ty0)

def switch_normals(taquin):
    ret = 0
    size = taquin.size
    taquin_copy = taquin.clone()
    i = 0
    while i < size:
        j = 0
        while j < size:
            value = taquin_copy.dico[(i, j)]
            tx0, ty0 = taquin.get_right_positions(value)
            if i != tx0 or j != ty0:
                taquin_copy.swap_values(i, j, tx0, ty0)
                ret = ret + 1
            else:
                j = j + 1
        i = i + 1
    return ret

def is_soluble(taquin):
    permu0 = calculate_modif_succ_vide(taquin)
    permun = switch_normals(taquin)
    return (permu0 % 2 == permun % 2)
