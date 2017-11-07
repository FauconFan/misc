#!/bin/sh
gcc -L../ -lft main_p1.1.c -o tmp/exec1_p1 -I../
gcc  main_p1.2.c -o tmp/exec2_p1 -I../
./tmp/exec1_p1 > tmp/tmp1.txt
./tmp/exec2_p1 > tmp/tmp2.txt
diff -a tmp/tmp1.txt tmp/tmp2.txt
