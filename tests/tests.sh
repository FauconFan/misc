#!/usr/bin/env bash

CMD="python3 ./main.py"

SOLUBLE_FOLDER="tests/soluble/"
NON_SOLUBLE_FOLDER="tests/non_soluble/"

function test_soluble()
{
	for file in ${SOLUBLE_FOLDER}*; do
		printf "Testing %s " "${file}"
		${CMD} ${file} | grep True > /dev/null 2>&1
		printf "OK\\n"
	done
}

function test_non_soluble()
{
	for file in ${NON_SOLUBLE_FOLDER}*; do
		printf "Testing %s " "${file}"
		${CMD} ${file} | grep False > /dev/null 2>&1
		printf "OK\\n"
	done
}

if [ ! $# = 1 ]; then
	exit 1
fi

case $1 in
	soluble )
		time test_soluble
		;;
	non_soluble )
		time test_non_soluble
		;;
	* )
		exit 1
		;;
esac
