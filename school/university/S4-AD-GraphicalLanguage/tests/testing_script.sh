#!/bin/bash

PROG="java -jar GraphTXT.jar -q"
FILES_BASIC_GOOD=$(find resources/basic_good -name "*.[g|G][t|T][x|X][t|T]")
FILES_BASIC_BAD=$(find resources/basic_bad -name "*.[g|G][t|T][x|X][t|T]")
FILES_SYS_GOOD=$(find resources/sys_good -name "*.[g|G][t|T][x|X][t|T]")
FILES_SYS_BAD=$(find resources/sys_bad -name "*.[g|G][t|T][x|X][t|T]")
FILES_BONUS_GOOD=$(find resources/bonus_good -name "*.[g|G][t|T][x|X][t|T]")

_RED=$(tput setaf 1)
_GREEN=$(tput setaf 2)
_YELLOW=$(tput setaf 3)
_BLUE=$(tput setaf 4)
#_PURPLE=$(tput setaf 5)
_CYAN=$(tput setaf 6)
#_WHITE=$(tput setaf 7)
_END=$(tput sgr0)

function print_title
{
	printf "\\n\\t%s%s%s\\n\\n" "${_YELLOW}" "${1}" "${_END}"
}

function print_good
{
	printf "%sOK <= %s%s%s\\n" "${_GREEN}" "${_CYAN}" "${1}" "${_END}"
}

function print_bad
{
	printf "%sKO <= %s%s\\n" "${_RED}" "${1}" "${_END}"
}

function do_all_tests_good_ast_tex
{
	for i in ${@}; do
		${PROG} --ast-tex "${i}" > /dev/null 2>&1
		if [ $? = 0 ]; then
			print_good "${i}"
		else
			print_bad "${i}"
		fi
	done
}

function do_all_tests_good
{
	for i in ${@}; do
		${PROG} "${i}" > /dev/null 2>&1
		if [ $? = 0 ]; then
			print_good "${i}"
		else
			print_bad "${i}"
		fi
	done
}

function do_all_tests_bad
{
	for i in ${@}; do
		${PROG} "${i}" > /dev/null 2>&1
		if [ $? ]; then
			print_good "${i}"
		else
			print_bad "${i}"
		fi
	done
}

function do_basic_test
{
	print_title "BASIC_GOOD"
	do_all_tests_good "${FILES_BASIC_GOOD}"

	print_title "BASIC_BAD"
	do_all_tests_bad "${FILES_BASIC_BAD}"
}

function do_sys_test
{
	print_title "SYS_GOOD"
	do_all_tests_good "${FILES_SYS_GOOD}"

	print_title "SYS_BAD"
	do_all_tests_bad "${FILES_SYS_BAD}"
}

function do_bonus_test
{
	print_title "BONUS_GOOD"
	do_all_tests_good "${FILES_BONUS_GOOD}"
}

function do_all_ast_tex
{
	print_title "BASIC_GOOD AST TEX"
	do_all_tests_good_ast_tex "${FILES_BASIC_GOOD}"

	print_title "SYS_GOOD AST TEX"
	do_all_tests_good_ast_tex "${FILES_SYS_GOOD}"

	print_title "BONUS_GOOD AST TEX"
	do_all_tests_good_ast_tex "${FILES_BONUS_GOOD}"
}

function main
{
	if [ $# -gt 1 ]; then
		exit 1
	fi

	printf "%sBuilding project%s\\n" "${_BLUE}" "${_END}"
	make -s -C . all > /dev/null 2>&1
	printf "%sProject built successfully%s\\n" "${_GREEN}" "${_END}"

	if [ $# = 0 ]; then
		do_basic_test
		do_sys_test
		do_bonus_test
		do_all_ast_tex
	else
		case ${1} in
			"sys" ) do_sys_test;;
			"basic" ) do_basic_test;;
			"bonus" ) do_bonus_test;;
		esac
	fi
	make -s -C . fclean > /dev/null 2>&1
}

main "$@"

