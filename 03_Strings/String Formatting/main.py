def print_formatted(number):
    index = 1
    max_len = len("{:b}".format(number))
    while index <= number:
        print("{:>{padding}d} {:>{padding}o} {:>{padding}X} {:>{padding}b}"
        	.format(index, index, index, index, padding = max_len))
        index += 1