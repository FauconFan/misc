#!/bin/bash

PROG="java -jar GraphTXT.jar -q"
FILES_GOOD=$(find resources/basic_good -name "*.gtxt")
FILES_BAD=$(find resources/basic_bad -name "*.gtxt")

_RED=$(tput setaf 1)
_GREEN=$(tput setaf 2)
_YELLOW=$(tput setaf 3)
_BLUE=$(tput setaf 4)
_PURPLE=$(tput setaf 5)
_CYAN=$(tput setaf 6)
_WHITE=$(tput setaf 7)
_END=$(tput sgr0)


printf "\\n\\t%sGood Files%s\\n\\n" "${_YELLOW}" "${_END}"
for i in ${FILES_GOOD}; do
	${PROG} "${i}" >/dev/null 2>&1
	if [ $? = 0 ]; then
		printf "%sOK <= " "${_GREEN}"
	else
		printf "%sKO <= " "${_RED}"
	fi
	printf "%s%s%s\\n" "${_CYAN}" "${i}" "${_END}"
done

printf "\\n\\t%sBad Files%s\\n\\n" "${_YELLOW}" "${_END}"
for i in ${FILES_BAD}; do
	${PROG} "${i}" >/dev/null 2>&1
	if [ ! $? = 0 ]; then
		printf "%sOK <= " "${_GREEN}"
	else
		printf "%sKO <= " "${_RED}"
	fi
	printf "%s%s%s\\n" "${_CYAN}" "${i}" "${_END}"
done 