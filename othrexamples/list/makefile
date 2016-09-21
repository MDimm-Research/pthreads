###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
###########################################################
# list/makefile
#
# makefile for the example programs 
#


CC = cc
CFLAGS = -std1 -warnprotos -g 
THREAD_CFLAGS = ${CFLAGS} -pthread

all : llist_test llist_test_threads llist_test_threads_rw

llist_test: llist_test.o llist.o llist.h
	${CC} llist.o llist_test.o -o llist_test

llist_test_threads: llist_test_threads.o llist_threads.o llist_threads.h
	${CC} ${THREAD_CFLAGS} llist_threads.o llist_test_threads.o -o llist_test_threads

llist_test_threads_rw: llist_test_threads_rw.o llist_threads_rw.o rdwr.o llist_threads_rw.h
	${CC} ${THREAD_CFLAGS} llist_threads_rw.o llist_test_threads_rw.o rdwr.o -o llist_test_threads_rw

clean :
	rm -f *.o *~ *# core  \
	llist llist_test llist_test_threads \
	llist_test_threads_rw
