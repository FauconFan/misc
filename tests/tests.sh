#!/usr/bin/env bash

set -e

CMD="python3 ./main.py"
CMD_GEN="python2 tests/npuzzle-gen.py"

SOLUBLE_FOLDER="tests/soluble/"
NON_SOLUBLE_FOLDER="tests/non_soluble/"

PUZ_RAN_PATH="puzzle_random.txt"

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

function test_random()
{
	while true ; do
		rm -f ${PUZ_RAN_PATH}
		N=$((RANDOM % 3 + 3))
		${CMD_GEN} $N > ${PUZ_RAN_PATH}
		printf "Testing size %d, " $N
		if grep unsolvable ${PUZ_RAN_PATH} > /dev/null 2>&1; then
			printf "unsolvable "
			${CMD} ${PUZ_RAN_PATH} | grep False > /dev/null 2>&1
		else
			printf "  solvable "
			${CMD} ${PUZ_RAN_PATH} | grep True > /dev/null 2>&1
		fi
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
	random )
		test_random
		;;
	* )
		exit 1
		;;
esac
