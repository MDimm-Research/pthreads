###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# tpool/Makefile
#
# makefile for the example programs for pthreads programming book
#

#include <pthread.h>
#include "tpool.h"

CC = cc
CFLAGS = -std1 -warnprotos -g 
THREAD_CFLAGS = ${CFLAGS} -pthread

all :  tpooltest

tpooltest: tpooltest.o tpool.o
	${CC} ${THREAD_CFLAGS} tpooltest.o tpool.o -o tpooltest 
bugtest: bugtest.o tpool.o
	${CC} ${THREAD_CFLAGS} bugtest.o tpool.o -o butest

clean :
	rm -f *.o *~ *# core  \
	tpooltest
