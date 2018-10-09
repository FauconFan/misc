#!/usr/bin/python3

def d_eucli(x1, y1, x2, y2):
    return abs(x2 - x1) + abs(y2 - y1)

def find_emptycase(taquin):
    for i in range(0, taquin['size']):
        for j in range(0, taquin['size']):
            id = taquin[(i, j)]
            if id is 0:
                return (i, j)
    return (-1, -1)

def calculate_modif_succ_vide(taquin):
    size = taquin['size']
    i0, j0 = find_emptycase(taquin)
    return d_eucli(i0, j0, size - 1, size - 1)

def switch_normals(taquin):
    taquin_copy = {}
    ret = 0
    size = taquin['size']
    taquin_copy['size'] = size
    for i in range(size):
        for j in range(size):
            taquin_copy[(i, j)] = taquin[(i, j)]
    i = 0
    while i < size:
        j = 0
        max_size = size
        if i is size - 1:
            max_size = max_size - 1
        while j < max_size:
            if taquin_copy[(i, j)] != (i * size) + j + 1:
                real_x = (taquin_copy[(i, j)] - 1) // size
                real_y = (taquin_copy[(i, j)] - 1) % size
                if taquin_copy[(i, j)] is 0:
                    real_x = size - 1
                    real_y = size - 1
                tmp = taquin_copy[(real_x, real_y)]
                taquin_copy[(real_x, real_y)] = taquin_copy[(i, j)]
                taquin_copy[(i, j)] = tmp
                ret = ret + 1
            else:
                j = j + 1
        i = i + 1
    return ret

def is_soluble(taquin):
    permu0 = calculate_modif_succ_vide(taquin)
    permun = switch_normals(taquin)
    return (permu0 % 2 == permun % 2)
