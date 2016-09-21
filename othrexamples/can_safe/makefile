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
# makefile for the example programs 
#

CC = cc
CFLAGS = -std1 -warnprotos -g 
THREAD_CFLAGS = ${CFLAGS} -pthread

all : async_safe

async_safe: async_safe.o
	${CC} ${THREAD_CFLAGS} async_safe.o -o async_safe

clean :
	rm -f *.o *~ *# core async_safe
