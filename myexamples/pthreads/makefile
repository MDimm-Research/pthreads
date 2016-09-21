###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# simple/Makefile
#
# makefile for the example programs 
#

CC = cc
* CFLAGS = -std1 -warnprotos -g
THREAD_CFLAGS = ${CFLAGS} -pthread


all : simple simple_threads simple_processes simple_mutex 


simple : simple.o
	${CC} ${CFLAGS} simple.o -o simple

simple_threads : simple_threads.o timer.o
	${CC} ${THREAD_CFLAGS} simple_threads.o timer.o -o simple_threads 

simple_processes : simple_processes.o
	${CC} ${CFLAGS} simple_processes.o -o simple_processes

simple_mutex : simple_mutex.o
	${CC} ${THREAD_CFLAGS} simple_mutex.o -o simple_mutex

timer.o: timer.c timer.h
	$(CC) -c timer.c

clean :
	rm -f *.o *~ *# core  a.out\
	simple simple_threads simple_processes simple_mutex

