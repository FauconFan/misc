#!/usr/bin/python3
import sys
import taquin
		
def error_taquin_not_valid():
	print("taquin non valide")
	sys.exit(1)

def get_taquin(lines, tmp):
	#Recuperation du tmp

	hauteur = 0
	list_number = []
	dico = {}
	for i in lines:
		if len(i.split()) != tmp['size']:
			error_taquin_not_valid()
		for k,v in enumerate(i.split()):
			if not v.isdigit() or int(v) >= tmp['size'] * tmp['size'] or int(v) < 0:
				error_taquin_not_valid()
			dico[(hauteur, k)] = int(v)
			if v in list_number:
				error_taquin_not_valid()
			list_number.append(v)
		hauteur += 1
	if hauteur != tmp['size']:
		error_taquin_not_valid()
	return taquin.Taquin(tmp['size'], dico)



def get_size(lines, tmp):
	#Recuperation de la taille du tmp

	for i in lines:
		if i.isdigit():
			tmp = int(i)
			lines.remove(i)
			return (int(tmp))
		else:
			print("erreur ligne")
			sys.exit(1)

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
	tmp = {}
	try:
		with open(filename) as file:
			lines = file.read().splitlines()
	except FileNotFoundError:
		print('File not found')
		sys.exit(1)
	lines = clean_lines(lines)
	tmp['size'] = get_size(lines, tmp)
	return get_taquin(lines, tmp)
