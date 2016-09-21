###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# simple_once/makefile
#
# makefile for the example programs 
#

CC = cc
CFLAGS = -std1 -warnprotos -g
THREAD_CFLAGS =  ${CFLAGS}
THREAD_LOADLIBS = -lc_r -lpthread -lmach -lbsd ${LOADLIBS}

all : once

once: once.o
	${CC} ${THREAD_CFLAGS} once.o -o once ${THREAD_LOADLIBS}

clean :
	rm -f *.o *~ *# core  \
	once

