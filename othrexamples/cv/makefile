###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# cv/Makefile
#
# makefile for the example programs 
#

CC = cc
CFLAGS = -std1 -warnprotos -g 
THREAD_CFLAGS = ${CFLAGS} -pthread

all : cvsimple

cvsimple: cvsimple.o
	${CC} ${THREAD_CFLAGS} cvsimple.o -o cvsimple

clean :
	rm -f *.o *~ *# core  \
	cvsimple
