#!/bin/sh

gcc test0.c -o test0
gcc test1.c -o test1
gcc test2.c -o test2
gcc test3.c -o test3
gcc test3++.c -o test3++
gcc test4.c -o test4
gcc test0.c -o test0

cp ../*.so ./