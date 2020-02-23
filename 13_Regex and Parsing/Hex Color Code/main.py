import re

if __name__ == "__main__":
	status = 0
	for _ in range(int(input())):
		str = input()
		if status == 0:
			m = re.search('{', str)
			if bool(m) == True:
				status += 1
		else:
			tab = str.split(";")
			if tab[0] == '}':
				status -= 1
			elif tab[0] == '{':
				status += 1
			else:
				for elem in tab:
					li = re.findall(r'(#[0123456789ABCDEFabcdef]{6}|#[0123456789ABCDEFabcdef]{3})', elem)
					res = "\n".join(li)
					if res != "":
						print(res)
