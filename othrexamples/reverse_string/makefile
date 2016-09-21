###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# reverse_string/Makefile
#
# makefile for the example programs 
#

CC = cc
CFLAGS = -std1 -warnprotos -g 
THREAD_CFLAGS = ${CFLAGS} -pthread

all : reverse_string

reverse_string: reverse_string.o
	${CC} ${THREAD_CFLAGS} reverse_string.o -o reverse_string

clean :
	rm -f *.o *~ *# core  \
	reverse_string
