import re

if __name__ == "__main__":
    tab = re.split(",|\.", input())
    for elem in tab:
    	if len(elem) != 0:
        	print(elem)