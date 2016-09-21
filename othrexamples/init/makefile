###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# init/Makefile
#
# makefile for the example programs
#

CC = cc
CFLAGS = -std1 -warnprotos -g 
THREAD_CFLAGS = ${CFLAGS} -pthread

all : static_init mattr

static_init: static_init.o
	${CC} ${THREAD_CFLAGS} static_init.o -o static_init

mattr: mattr.o
	${CC} ${THREAD_CFLAGS} mattr.o -o mattr

clean :
	rm -f *.o *~ *# core  \
	static_init mattr
