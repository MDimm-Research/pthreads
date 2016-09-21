###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# mutex/makefile
#
# makefile for the example programs
#

CC = cc
CFLAGS = -std1 -warnprotos -g 
THREAD_CFLAGS = ${CFLAGS} -pthread

all : process_shared_mutex mutex_priority mutex_ceiling

process_shared_mutex: process_shared_mutex.o
	${CC} ${THREAD_CFLAGS} process_shared_mutex.o -o process_shared_mutex

mutex_priority: mutex_priority.o
	${CC} ${THREAD_CFLAGS} mutex_priority.o -o mutex_priority

mutex_ceiling: mutex_ceiling.o
	${CC} ${THREAD_CFLAGS} mutex_ceiling.o -o mutex_ceiling

clean :
	rm -f *.o *~ *# core  \
	process_shared_mutex mutex_priority mutex_ceiling
