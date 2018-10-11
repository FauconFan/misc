# 42_N-Puzzle

# Organisation

* Quelle langage de programmation : Python

4 fichiers:
 - main.py
 - parser.py
 - is_soluble.py
 - solve.py

# Differentes tâches

 - [x] Initialisation projet
 - [x] Parser / Lexer
 - [x] Est soluble ?
 - [ ] Core

## Représentation d'un taquin

2 Dictionnaires:

### Le taquin

 - 'taille' : N
 - '(x, y)' : les coordonnées de notre taquin, 0 <= x < N, 0 <= y < N, avec une valeur compris entre 0 et N * N - 1

0 désigne la case vide

### L'état (state)

 - 'taquin' : UP
 - 'score' : int
 - 'taille_history' : int
 - 'liste_history' : liste de mouvements
