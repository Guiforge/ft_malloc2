#! /usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys

BIN_FOLDER = "./bin/"
SOURCES_FOLDER = "./sources/"
TESTS_FILES = ["test0.c", "test1.c", "test2.c", "test3.c", "test3++.c", "test4.c"]

def execute_sys(command):
	print(command)
	return os.system(command)


def compile():
	print "############ COMPILATION TESTS ############"
	for files in TESTS_FILES:
		execute_sys("gcc -o " + BIN_FOLDER + files[:-2] + " " + SOURCES_FOLDER + files)


if (execute_sys("make -C ../") != 0):
	exit()
if (execute_sys("mkdir -p ./bin") != 0):
	exit()
compile()
if (execute_sys("cp ../*.so ./") != 0):
	exit()
