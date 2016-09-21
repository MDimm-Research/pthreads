#
# makefile
#
# makefile for automated teller machine (ATM) sr example program
#
# Initially setup for a DEC OSF/1 environment. Use on other platforms
# may require changes to LOADLIBS, CLAGS etc.
#

CC = cc 
CFLAGS = -g -std1 -warnprotos -I../tpool -pthread
DB = atm_db.o

# Threaded Sr Objects
TSOBJS   = atm_svr.o \
	   atm_com_svr.o \
	   ${DB} \
	   atm_svr_password.o

# Threaded Sr Objects - single mutex
TSSMOBJS   = atm_svr_1mtx.o \
	   atm_com_svr.o \
	   ${DB} \
	   atm_svr_password.o

# Threaded Sr Objects - nosync
TSNSOBJS   = atm_svr_nosync.o \
	   atm_com_svr.o \
	   ${DB} \
	   atm_svr_password.o

# Broken Threaded Sr Objects
TSBOBJS   = atm_svr_broken.o \
	   atm_com_svr.o \
	   ${DB} \
	   atm_svr_password.o

# Threaded Svr Objects using thread pool
TSPOBJS   = atm_svr_tpool.o \
	   atm_com_svr.o \
	   ${DB} \
	   atm_svr_password.o\
           tpool.o

# Threaded Svr Objects with Cancellation Cleanup example
TSCOBJS   = atm_svr_cancel.o \
	   atm_com_svr.o \
	   ${DB} \
	   atm_svr_password.o

# Threaded Svr Objects with SIGUSR1 handling example
TSSIGOBJS   = atm_svr_signals.o \
	   atm_com_svr.o \
	   ${DB} \
	   atm_svr_password.o

# Client Objects
COBJS    = atm_client.o \
	   atm_com_client.o

# Load Test Objects
LTOBJS   = aldtest.o \
	   atm_com_client.o \
	   atm_client_rpc.o

$(STSOBJS) : atm.h atm_com.h makefile atm_db.h atm_svr_password.h
$(TSOBJS)  : atm.h atm_com.h makefile atm_db.h atm_svr_password.h
$(TSBOBJS)  : atm.h atm_com.h makefile atm_db.h atm_svr_password.h
$(TSPOBJS)  : atm.h atm_com.h makefile atm_db.h atm_svr_password.h
$(TSCOBJS)  : atm.h atm_com.h makefile atm_db.h atm_svr_password.h
$(TSSIGOBJS)  : atm.h atm_com.h makefile atm_db.h atm_svr_password.h
$(COBJS)   : atm.h atm_com.h makefile
$(TOBJS)   : atm.h atm_com.h makefile

all        : atm_svr atm_client aldtest atm_svr_broken atm_svr_cancel atm_svr_1mtx atm_svr_nosync atm_svr_tpool atm_svr_signals

atm_svr : $(TSOBJS)
	${CC} ${CFLAGS} $(TSOBJS) -o atm_svr 

atm_svr_1mtx.o : 
	${CC} ${CFLAGS} -c -DSINGLE_DATABASE_MUTEX_SYNC -o atm_svr_1mtx.o atm_svr.c

atm_svr_1mtx : $(TSSMOBJS)
	${CC} ${CFLAGS} $(TSSMOBJS) -o atm_svr_1mtx 

atm_svr_nosync.o : 
	${CC} ${CFLAGS} -c -DNO_DATABASE_SYNC -o atm_svr_nosync.o atm_svr.c

atm_svr_nosync : $(TSNSOBJS)
	${CC} ${CFLAGS} $(TSNSOBJS) -o atm_svr_nosync

atm_svr_broken : $(TSBOBJS)
	${CC} ${CFLAGS} $(TSBOBJS) -o atm_svr_broken 

tpool.o :
	${CC} -c ${CFLAGS} ../tpool/tpool.c -o ./tpool.o 

atm_svr_tpool : $(TSPOBJS)
	${CC} ${CFLAGS} $(TSPOBJS) -o atm_svr_tpool

atm_svr_cancel : $(TSCOBJS)
	${CC} ${CFLAGS} $(TSCOBJS) -o atm_svr_cancel

atm_svr_signals : $(TSSIGOBJS)
	${CC} ${CFLAGS} $(TSSIGOBJS) -o atm_svr_signals

atm_client : $(COBJS)
	${CC} ${CFLAGS} $(COBJS) -o atm_client

aldtest : $(LTOBJS)
	${CC} ${CFLAGS} $(LTOBJS) -o aldtest

clean :
	rm -f *.o *~ *# core \
	atm_svr atm_client aldtest .atm_db .atm_pw .atm_conn \
	atm_svr_broken atm_svr_cancel atm_svr_signals atm_svr_tpool \
	atm_svr_1mtx atm_svr_nosync
