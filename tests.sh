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
	* )
		exit 1
		;;
esac
