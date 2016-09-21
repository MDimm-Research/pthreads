###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# signals/makefile
#
# makefile for the example programs
#

CC = cc
CFLAGS = -std1 -g -warnprotos -pthread

all : sig stat_sigwait

sig : sig.o
	${CC} ${CFLAGS} ${THREAD_CFLAGS} sig.o -o sig 

stat_sigwait : stat_sigwait.o
	${CC} ${CFLAGS} ${THREAD_CFLAGS} stat_sigwait.o -o stat_sigwait

clean :
	rm -f *.o *~ *# core  \
	sig stat_sigwait 
