#!/usr/bin/python3

def d_eucli(x1, y1, x2, y2):
    return abs(x2 - x1) + abs(y2 - y1)

def calculate_modif_succ_vide(taquin):
    size = taquin.size
    i0, j0 = taquin.find_case(0);
    return d_eucli(i0, j0, size - 1, size - 1)

def switch_normals(taquin):
    ret = 0
    size = taquin.size
    taquin_copy = taquin.clone()
    i = 0
    while i < size:
        j = 0
        max_size = size
        if i is size - 1:
            max_size = max_size - 1
        while j < max_size:
            value = taquin_copy.dico[(i, j)]
            if value != (i * size) + j + 1:
                real_x, real_y = taquin_copy.get_right_positions(value)
                taquin_copy.swap_values(i, j, real_x, real_y)
                ret = ret + 1
            else:
                j = j + 1
        i = i + 1
    return ret

def is_soluble(taquin):
    permu0 = calculate_modif_succ_vide(taquin)
    permun = switch_normals(taquin)
    return (permu0 % 2 == permun % 2)
