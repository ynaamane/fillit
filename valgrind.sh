#!/bin/sh
valgrind -v --leak-check=full ./fillit test
#!--show-leak-kinds=all  ./fillit test
