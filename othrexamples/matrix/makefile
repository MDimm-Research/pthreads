###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# matrix/Makefile
#
# makefile for the example programs
#

CC = cc
CFLAGS = -std1 -warnprotos -g 
THREAD_CFLAGS = -pthread ${CFLAGS}
THREAD_LOADLIBS = -lc_r -lmach -lbsd ${LOADLIBS}

all : matrix_serial matrix_threads

matrix_serial : matrix_serial.o
	${CC} ${CFLAGS} matrix_serial.o -o matrix_serial

matrix_threads : matrix_threads.o
	${CC} ${THREAD_CFLAGS} matrix_threads.o -o matrix_threads $(THREAD_LOADLIBS) 

clean :
	rm -f *.o *~ *# core  \
	matrix_serial matrix_threads


