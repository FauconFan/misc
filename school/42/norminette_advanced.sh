#!/bin/sh

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

STEP1="1	-	Vérification que les dossiers et les fichiers sont en Unix Case."
STEP2="2	-	Seuls les caractères de la table ascii sont autorisés."
STEP3="3	-	Compter le nombre de variables globales."
STEP4="4	-	Vérifier que le header est présent dans les Makefile."
STEP5="5	-	Vérifier que le sizeof est bien utilisé sans espace après."
STEP6="6	-	Indentation dans des formules booléennes dans les if/while."
STEP7="7	-	Vérifier qu'un opérateur est bien en début de ligne (et pas à la fin)."
STEP8="8	-	Prototype de fonction sans argument avec void."
STEP9="9	-	Pas de define autre que pour des constantes (entières et string)."
STEP10="10	-	Vérifier l'utilisation de headers interdit."
STEP11="11	-	Vérifier les VLAs."
STEP12="12	-	Vérifier que les 5 règles standards sont présents dans les Makefiles."

## Colors
_RED=$(tput setaf 1 2> /dev/null || echo "")
_GREEN=$(tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(tput setaf 3 2> /dev/null || echo "")
_BLUE=$(tput setaf 4 2> /dev/null || echo "")
# _PURPLE=$(tput setaf 5 2> /dev/null || echo "")
# _CYAN=$(tput setaf 6 2> /dev/null || echo "")
# _WHITE=$(tput setaf 7 2> /dev/null || echo "")
_END=$(tput sgr0 2> /dev/null || echo "")

VERBOSE=""

if [ "$#" = "1" ] && [ "$1" = "verbose" ]; then
	VERBOSE="activated"
fi

print_ok() {
	printf "%s[ OK ]%s\\n" "$_GREEN" "$_END"
}

print_ko() {
	printf "%s[FAIL]%s\\n" "$_RED" "$_END"
}

print_warn() {
	printf "%s[WARN]%s\\n" "$_YELLOW" "$_END"
}

print_info() {
	printf "%s[INFO]%s\\n" "$_BLUE" "$_END"
}

MAKEFILES=$(find . -name "Makefile" | sort)
C_FILES=$(find . -name "*.c")
H_FILES=$(find . -name "*.h")
CH_FILES=$(find . -name "*.[ch]")

step1() {
	printf "%s\\n" "$STEP1"
	OUT=$(find . -type d | grep -v '.git' | grep -v '^.[\/\_a-z0-9]*$')

	if [ "$OUT" = "" ]; then
		print_ok
	else
		print_ko
		if [ "$VERBOSE" ]; then
			echo "Voici les dossiers :"
			echo "$OUT"
		fi
	fi
}

step2() {
	printf "%s\\n" "$STEP2"
	IS_OK="0"
	for file in $CH_FILES; do
		OUT=$(grep -P '[^\x00-\x7f$]' "${file}")
		if [ "$OUT" ]; then
			IS_OK="1"
		fi
	done

	if [ "$IS_OK" = "0" ]; then
		print_ok
	else
		print_ko
	fi

	if [ "$VERBOSE" ]; then
		for file in $CH_FILES; do
			OUT=$(grep -nP '[^\x00-\x7f$]' "${file}")
			if [ "$OUT" ]; then
				printf "On file %s\\n" "${file}"
				echo "${OUT}"
			fi
		done
	fi
}

step3() {
	printf "%s\\n" "$STEP3"
	GLOBALS=$(grep -oh '[^a-zA-Z0-9_]g_[a-zA-Z0-9_]*' $C_FILES | grep -oh 'g_[a-zA-Z0-9_]*' | sort | uniq)
	NUMBER=$(echo "$GLOBALS" | wc -l)

	if [ "$NUMBER" = "0" ]; then
		print_ok
	else
		print_warn
		printf "%d Globals variables\\n" "$NUMBER"
		if [ "$VERBOSE" ]; then
			printf "Voici les variables globales\\n"
			for var in ${GLOBALS}; do
				echo "$var"
			done
		fi
	fi
}

step4() {
	printf "%s\\n" "$STEP4"
	HEADERS=$(grep '#    Created' $MAKEFILES -l)
	NM=$(echo "$MAKEFILES" | wc -l)
	NH=$(echo "$HEADERS" | wc -l)
	if [ "$NM" = "$NH" ]; then
		print_ok
	else
		print_ko
		if [ "$VERBOSE" ]; then
			echo "$MAKEFILES" | sort > a
			echo "$HEADERS" | sort > b
			diff a b
			rm -f a b
		fi
	fi
}

step5() {
	printf "%s\\n" "$STEP5"
	OUT=$(grep -h 'sizeof' $C_FILES | grep -v 'sizeof(')
	if [ -z "$OUT" ]; then
		print_ok
	else
		print_ko
		if [ "$VERBOSE" ]; then
			echo "$OUT"
		fi
	fi
}

step6() {
	printf "%s\\n" "$STEP6"
	print_info
	printf "Cannot test this one, but you can test it by yourself, with this command:\\n"
	printf "$> grep -G -C 10 'if\|while' **/*.c\\n"
}

step7() {
	printf "%s\\n" "$STEP7"
	print_info
	printf "Cannot test this one, but you can test it by yourself, with this command:\\n"
	printf "$> grep -E '[=+\-\*&\^%%><\/]$' **/*.c\\n"
}

step8() {
	printf "%s\\n" "$STEP8"
	OUT=$(grep '();' $H_FILES)
	if [ -z "$OUT" ]; then
		print_ok
	else
		print_ko
		if [ "$VERBOSE" ]; then
			echo "$OUT"
		fi
	fi
}

step9() {
	printf "%s\\n" "$STEP9"
	OUT=$(grep -hE '^# ?define ' $CH_FILES | grep -Ev "(_H|[0-9]|'|\")$")
	if [ -z "$OUT" ]; then
		print_ok
	else
		print_ko
		print_info
		printf "It may have some issues\\n"
		if [ ! "$VERBOSE" ]; then
			echo "Do vervose for more information"
		else
			echo "$OUT"
		fi
	fi
}

step10() {
	printf "%s\\n" "$STEP10"
	echo "$MAKEFILES" | sort > a
	grep -l '#    Created' $MAKEFILES | sort > b
	OUT=$(diff a b)
	rm a b
	if [ -z "$OUT" ]; then
		print_ok
	else
		print_ko
		if [ "$VERBOSE" ]; then
			echo "$OUT"
		fi
	fi
}

step11() {
	printf "%s\\n" "$STEP11"
	print_info
	printf "Cannot test this one, but you can test it by yourself, with this command:\\n"
	printf "$> grep '];' **/*.[ch]\\n"
}

step12() {
	printf "%s\\n" "$STEP12"
	printf "Cannot test this one, but you can test it by yourself, with these commands:\\n"
	printf "$> grep '\$(NAME)' **/Makefile\\n"
	printf "$> grep 'clean' **/Makefie\\n"
	printf "$> grep 'fclean' **/Makefile\\n"
	printf "$> grep 're' **/Makefile\\n"
	printf "$> grep 'all' **/Makefile\\n"
}

step1
step2
step3
step4
step5
step6
step7
step8
step9
step10
step11
step12
