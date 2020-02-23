def capitalize(string):
    str = ""
    mode = 1
    for c in string:
    	d = c
    	if c == ' ':
    		mode = 1
    	elif mode == 1:
    		d = c.upper()
    		mode = 0
    	str += d
    return str
