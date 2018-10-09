#!/usr/bin/python3
import sys

def error_taquin_not_valid():
	print("Taquin non valide")
	sys.exit(1)

def get_taquin(lines, taquin):
	#Recuperation du taquin

	hauteur = 0
	list_number = []
	for i in lines:
		if len(i.split()) != taquin['size']:
			error_taquin_not_valid()
		for k,v in enumerate(i.split()):
			if not v.isdigit() or int(v) >= taquin['size'] * taquin['size'] or int(v) < 0:
				error_taquin_not_valid()
			taquin[(hauteur, k)] = int(v)
			if v in list_number:
				error_taquin_not_valid()
			list_number.append(v)
		hauteur += 1
	if hauteur != taquin['size']:
		error_taquin_not_valid()
	return taquin



def get_size(lines, taquin):
	#Recuperation de la taille du taquin

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
	taquin = {}
	try:
		with open(filename) as file:
			lines = file.read().splitlines()
	except FileNotFoundError:
		print('File not found')
		sys.exit(1)
	lines = clean_lines(lines)
	taquin['size'] = get_size(lines, taquin)
	return get_taquin(lines, taquin)
