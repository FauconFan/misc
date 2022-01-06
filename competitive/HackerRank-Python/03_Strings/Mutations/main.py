def mutate_string(string, position, character):
    new_str = list(string)
    new_str[position] = character
    return ''.join(new_str)