#!/bin/sh
# 
## auteur: jpriou
## 42 school

## Ce programme à pour ambition de montrer toutes les erreurs de normes
## qui sont présentes dans 'The Norm' mais qui ne sont pas montrées par
## le programme 'norminette'

## On suppose que les fichiers que vous donnez à manger à ce script
## sont compilables et respectent déjà le programme norminette

## Ceci n'est pas un projet pour profiter aux correcteurs qui abusent de leurs
## pouvoirs pour mettre des fautes de Norme, mais au contraire, pour profiter
## à tout ceux qui s'intéressent au contenu de leur projet et non à des problèmes
## de norme.

## Voici les erreurs que ce script prétend corriger
## Si vous trouvez une erreur, je vous prie de le monter sur le forum

##	1	-	Vérifier que le dossiers et les fichiers sont en Unix Case
##	2	-	Les caractères ne faisant pas partie de la table ascii ne sont pas
##			autorisés
##	3	-	Nombre de variables globales
##	4	-	Vérifier que le header est présent dans tous les fichiers:
##			le code source (*.c, *.h), mais aussi les Makefiles
##	5	-	Vérifier que le sizeof est bien utilisé sans espace après
##	6	-	Indentation dans des formules booléennes dans les if/while
##	7	-	Vérifier qu'un opérateur est bien en début de ligne (et pas à la fin)
##	8	-	Prototype de fonction sans argument avec void
##	9	-	Pas de define autre que pour des constantes (entières et string)
##	10	-	Vérifier l'utilisation de headers interdit
##	11	-	Gestion des VLAs
##	12	-	Vérifier que les 5 règles standards sont présents dans les Makefiles

##	Faire un test anti correction dans toutes les fonctions

## Premier jet

# grep -E '[=+\-\*&\^%><\/]$' **/*.c
# ls -1 *.[ch] **/Makefile | wc -l
# grep Created *.[ch] **/Makefile | wc -l
# grep sizeof **/*.[ch]
# grep "()" **/*.[ch]
# grep "return" **/*.c
# grep define **/*.[ch]
# grep -n10 -E 'enum' **/*.[ch]
# grep "];" **/*.[ch]
# grep "\$(NAME)" **/Makefile
# grep "clean" **/Makefie
# grep "fclean" **/Makefile
# grep "re" **/Makefile
# grep "all" **/Makefile
# touch main.c && make && ls -la **/*.o
# ls -la doom-nukem