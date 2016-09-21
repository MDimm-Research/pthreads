###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# keys/Makefile
#
# makefile for the example programs
#

CC = cc
CFLAGS = -std1 -warnprotos -g
THREAD_CFLAGS = -pthread ${CFLAGS}
THREAD_LOADLIBS = -lpthread ${LOADLIBS}

all : specific

specific: specific.o
	${CC} ${THREAD_CFLAGS} specific.o -o specific ${THREAD_LOADLIBS}

clean :
	rm -f *.o *~ *# core  \
	specific

