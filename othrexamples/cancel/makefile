###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# cancel/Makefile
#
# makefile for the example program
#
CC = cc
CFLAGS = -std1 -warnprotos -g 
THREAD_CFLAGS = ${CFLAGS} -pthread

all : cancel

cancel: cancel.o
	${CC} ${THREAD_CFLAGS} cancel.o -o cancel

clean :
	rm -f *.o *~ *# core  \
	cancel

