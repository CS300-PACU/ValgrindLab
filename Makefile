#############################################################################
# File name:  Makefile
# Author:     Computer Science, Pacific University
# Date:       9.28.16
# Class:      CS 300
# Assignment: In Class Dynamic Memory Lab
# Purpose: 	  This is the Makefile for the In Class Dynamic Memory Lab    
#############################################################################

CC=gcc

# the -w command disables all warnings
# You should never use this.  It is used here merely as an exercise.
CFLAGS=-g -w
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all 

.PHONY: all clean

TARGETS= bin bin/mainList bin/mainArrays

all: ${TARGETS}

bin:
	mkdir -p bin
	
bin/mainList: bin/mainList.o
	${CC} ${CFLAGS} -o bin/mainList bin/mainList.o

bin/mainList.o: src/mainList.c
	${CC} ${CFLAGS} -c -o bin/mainList.o src/mainList.c
	
bin/mainArrays: bin/mainArrays.o
	${CC} ${CFLAGS} -o bin/mainArrays bin/mainArrays.o

bin/mainArrays.o: src/mainArrays.c
	${CC} ${CFLAGS} -c -o bin/mainArrays.o src/mainArrays.c

clean:
	rm -rf bin/*.o ${TARGETS} vgcore*
	
valgrindList: bin/mainList
	valgrind ${VALGRIND_FLAGS} bin/mainList

valgrindArrays: bin/mainArrays
	valgrind ${VALGRIND_FLAGS}   bin/mainArrays

#printMain:
#	enscript -C -T 2 -p - -M Letter -Ec --color -fCourier8 src/main.c  | ps2pdf - bin/main.pdf
