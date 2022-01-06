def merge_the_tools(string, k):
    for i in range(0, len(string), k):
    	sub = string[i:i + k]
    	str = ""
    	for x in range(len(sub)):
    		to_print = 1
    		for y in range(x):
    			if sub[x] == sub[y]:
    				to_print = 0
    				break
    		if to_print == 1:
    			str += sub[x]
    	print(str)
