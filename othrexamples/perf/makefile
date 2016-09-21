###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# perf/makefile
#
# makefile for the example programs
#

CC = cc
CFLAGS = -std1 -warnprotos -g 
THREAD_CFLAGS = -pthread ${CFLAGS}
THREAD_LOADLIBS = -lpthread -lm 

all : goodlocks badlocks polling

polling: polling.o
	${CC} ${THREAD_CFLAGS} -o polling polling.o ${THREAD_LOADLIBS}

goodlocks: goodlocks.o
	${CC} ${THREAD_CFLAGS} -o goodlocks goodlocks.o ${THREAD_LOADLIBS}

badlocks: badlocks.o
	${CC} ${THREAD_CFLAGS} -o badlocks badlocks.o ${THREAD_LOADLIBS}

clean :
	rm -f *.o *~ *# core  \
	goodlocks badlocks polling
