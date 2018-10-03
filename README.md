# 42_N-Puzzle

# Organisation

* Quelle langage de programmation : Python

4 fichiers:
main.py
parser.py
is_soluble.py
solve.py

# Differentes tâches

 - [ ] Initialisation projet
 - [ ] Parser / Lexer
 - [ ] Est soluble ?
 - [ ] Core

## Représentation d'un taquin

2 Dictionnaires:

### Le taquin

 'taille' : N
 'contenu' : liste de liste d'entiers

0 c'est le vide
1 à (N * N - 1) les differentes cases.

### L'état (state)

 'taquin' : UP
 'score' : int
 'taille_history' : int
 'liste_history' : liste de mouvements
