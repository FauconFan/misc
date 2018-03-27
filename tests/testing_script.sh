#!/bin/bash

PROG="java -jar GraphTXT.jar -q"
FILES_BASIC_GOOD=$(find resources/basic_good -name "*.gtxt")
FILES_BASIC_BAD=$(find resources/basic_bad -name "*.gtxt")
FILES_SYS_GOOD=$(find resources/sys_good -name "*.gtxt")
FILES_SYS_BAD=$(find resources/sys_bad -name "*.gtxt")

_RED=$(tput setaf 1)
_GREEN=$(tput setaf 2)
_YELLOW=$(tput setaf 3)
_BLUE=$(tput setaf 4)
_PURPLE=$(tput setaf 5)
_CYAN=$(tput setaf 6)
_WHITE=$(tput setaf 7)
_END=$(tput sgr0)

function print_title_good()
{
	printf "\\n\\t%sGood Files%s\\n\\n" "${_YELLOW}" "${_END}"
}

function print_title_bad()
{
	printf "\\n\\t%sBad Files%s\\n\\n" "${_YELLOW}" "${_END}"
}

function print_good()
{
	printf "%sOK <= %s%s%s\\n" "${_GREEN}" "${_CYAN}" "${1}" "${_END}"
}

function print_bad()
{
	printf "%sKO <= %s%s\\n" "${_RED}" "${1}" "${_END}"
}

function do_all_tests_good()
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

function do_all_tests_bad()
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

function do_basic_test()
{
	print_title_good
	do_all_tests_good ${FILES_BASIC_GOOD}

	print_title_bad
	do_all_tests_bad ${FILES_BASIC_BAD}
}

function do_sys_test()
{
	print_title_good
	do_all_tests_good ${FILES_SYS_GOOD}

	print_title_bad
	do_all_tests_bad ${FILES_SYS_BAD}
}

function main()
{
	if [ $# -gt 1 ]; then
		exit 1
	fi

	printf "%sBuilding project%s\\n" "${_BLUE}" "${_END}"
	make -s -C . all 2>&1 > /dev/null
	printf "%sProject built successfully%s\\n" "${_GREEN}" "${_END}"

	if [ $# = 0 ]; then
		do_basic_test
		do_sys_test
	else
		case ${1} in
			"sys" ) do_sys_test;;
			"basic" ) do_basic_test;;
		esac
	fi
	make -s -C . fclean 2>&1 > /dev/null
}

main $@

