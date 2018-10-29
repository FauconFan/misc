from Formule import Formule, Operator

class LineParser():
    def __init__(self, string):
        self.string = [c for c in string if c is not ' ']
        self.operators = ['+', '|', '^', '!']

    def create_formula(self, op, left, right):
        formule = Formule(op, str(left), str(right))
        print(formule)

    def parse(self):
        print(self.string)
        for index, c in enumerate(self.string):
            if c in self.operators:
                left = self.string[0:index]
                right = self.string[index + 1:]
                if len(left) == 1 and len(right) == 1:
                    self.create_formula(c, left, right)
                # else:
                #     ## not a simple exp
                #     pass
