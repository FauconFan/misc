#!/usr/bin/python3

class Result(object):
    """docstring for Result."""
    def __init__(self, final_state, time_complexity, space_complexity, eff_complexity):
        self.final_state = final_state
        self.time_complexity = time_complexity
        self.space_complexity = space_complexity
        self.eff_complexity = eff_complexity

    def __str__(self):
        s = ""
        s += "Complexity in Time :   " + str(self.time_complexity) + "\n"
        s += "Complexity in Space :  " + str(self.space_complexity) + "\n"
        s += "Effective Complexity : " + str(self.eff_complexity) + "\n"
        s += "Nb Moves :             " + str(self.final_state.taille_history) + "\n"
        return s

    def build_moves(self):
        str_moves = map(str, self.final_state.liste_history)
        return " ".join(str_moves)
