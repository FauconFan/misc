#!/usr/bin/env bash

set -eu

deduction()
{
	find tests/deduction -name "*.txt" | sort | while read file; do
		printf "Testing %s " $file
		python3 main.py $file > /dev/null
		printf "OK\\n"
	done
}

correction()
{
	find tests/from_correction -name "*.txt" | sort | while read file; do
		printf "Testing %s " $file
		python3 main.py -p $file > /dev/null
		printf "OK\\n"
	done
}

pycodestyle()
{
	TEST_CMD="venv/bin/pycodestyle --ignore=W191,E501"
	test -d venv || python3 -m venv venv
	venv/bin/pip3 install --upgrade pip
	venv/bin/pip3 install pycodestyle
	FILES="$(find src -name "*.py")\nmain.py"
	echo "${FILES}" | sort | while read file; do
		printf "Testing %s\\n" $file
		${TEST_CMD} $file
	done
	printf "All good\\n"
}

if [ ! $# = 1 ]; then
	exit 2
fi

case $1 in
	deduction )
		deduction
		;;
	correction )
		correction
		;;
	pycodestyle )
		pycodestyle
		;;
	* )
		exit 1
		;;
esac
