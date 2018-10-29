def clean_lines(lines):
	#Mise Au propre de la recuperation sur l'entree standard

	new_lines = []
	for i in lines:
		val = i
		if '#' in i.strip():
			val = i[:i.index("#")]
		if len(val.strip()) > 0:
			new_lines.append(val.strip())
	return new_lines

def parse(filename):
	try:
		with open(filename) as file:
			lines = file.read().splitlines()
	except FileNotFoundError:
		print('File not found')
		sys.exit(1)
	except IsADirectoryError:
		print('The argument is a directory')
		sys.exit(1)
	except:
		print('Unexpected error')
		sys.exit(1)
	lines = clean_lines(lines)
