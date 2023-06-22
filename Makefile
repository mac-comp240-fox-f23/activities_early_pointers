# Makefile for Activity 3

CC=gcc -std=c99

ptrs: activity3.c string_funcs.c
	${CC} -o ptrs activity3.c string_funcs.c

clean:
	rm -f ptrs
