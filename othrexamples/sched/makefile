###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# sched/makefile
#
# makefile for the example programs
#

CC = cc
CFLAGS = -std1 -warnprotos -g
THREAD_CFLAGS = -pthread ${CFLAGS}
THREAD_LOADLIBS = ${LOADLIBS}

all : sched

sched: sched.o
	${CC} ${THREAD_CFLAGS} sched.o -o sched ${THREAD_LOADLIBS}

clean :
	rm -f *.o *~ *# core  \
	sched 

