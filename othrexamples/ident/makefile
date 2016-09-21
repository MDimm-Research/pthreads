###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
# ident/makefile
#

CC = cc
CFLAGS = -std1 -warnprotos -g 
THREAD_CFLAGS = ${CFLAGS} -pthread

all : tident exit_status exit_status_alternative


tident: tident.o
	${CC} ${THREAD_CFLAGS} tident.o -o tident

exit_status: exit_status.o
	${CC} ${THREAD_CFLAGS} exit_status.o -o exit_status

exit_status_alternative: exit_status_alternative.o
	${CC} ${THREAD_CFLAGS} exit_status_alternative.o -o exit_status_alternative

clean :
	rm -f *.o *~ *# core  \
	tident exit_status exit_status_alternative

