###########################################################
# An example source module to accompany...
#
# "Using POSIX Threads: Programming with Pthreads"
#     by Brad nichols, Dick Buttlar, Jackie Farrell
#     O'Reilly & Associates, Inc.
#
###########################################################
#
# makefile
#
# makefile for automated teller machine (ATM) sr example program
#
# Initially setup for a DEC OSF/1 environment. Use on other platforms
# may require changes to LOADLIBS, CLAGS etc.
#
CC = cc 
CFLAGS = -g -std1 -warnprotos -non_shared
DB = atm_db.o

# Default (Sequential) Sr Objects
DSOBJS   = atm_svr_serial.o \
	   atm_com_svr.o \
	   ${DB} \
	   atm_svr_password.o

# Multi-Process Sr Objects
MSOBJS   = atm_svr_processes.o \
	   atm_com_svr.o \
	   ${DB} \
	   atm_svr_password.o

# Client Objects
COBJS    = atm_client.o \
           atm_com_client.o


$(DSOBJS)  : atm.h atm_com.h makefile atm_db.h atm_svr_password.h
$(MSOBJS)  : atm.h atm_com.h makefile atm_db.h atm_svr_password.h
$(COBJS)   : atm.h atm_com.h makefile

all        : atm_svr_serial atm_svr_processes  atm_client

atm_svr_serial : $(DSOBJS)
	${CC} ${CFLAGS} $(DSOBJS) ${NOTHREAD_FLAGS} -o atm_svr_serial

atm_svr_processes : $(MSOBJS)
	${CC} ${CFLAGS} $(MSOBJS) -o atm_svr_processes

atm_client : $(COBJS)
	${CC} ${CFLAGS} $(COBJS) -o atm_client

clean :
	rm -f *.o *~ *# core \
	atm_svr_processes atm_svr_serial atm_client \
	.atm_conn .atm_db .atm_pw 
