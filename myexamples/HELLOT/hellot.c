/******************************
**
** Multi-threaded "Hello World" program
**
*******************************/

#define _REENTRANT  
#include <pthread.h>
#include <stdio.h>
#include <sys/timeb.h>

/* function prototypes */
void * outputMsg( void*);

/* mutex variables */
pthread_mutex_t printfLock = PTHREAD_MUTEX_INITIALIZER;

int main(void)
{
   pthread_attr_t attr;
   int setscope_result = 0;
   pthread_t thr1, thr2, thr3, thr4;
   const char* msg1 = "Hello ";
   const char* msg2 = "world ";
   const char* msg3 = "Hello ";
   const char* msg4 = "World ";
   int i;
   struct timeb start, stop;
   double elapsed;

   setscope_result=pthread_attr_setscope(&attr,PTHREAD_SCOPE_PROCESS);
//   setscope_result=pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);

printf(" creating threads to run in parallel or not \n");
ftime(&start);
   pthread_create( &thr1, NULL, outputMsg, (void*)msg1);
   pthread_create( &thr2, NULL, outputMsg, (void*)msg2);
   pthread_create( &thr3, NULL, outputMsg, (void*)msg3);
   pthread_create( &thr4, NULL, outputMsg, (void*)msg4);

 //  printf("threads created\n\n");
  
   pthread_join(thr1, NULL);
   pthread_join(thr2, NULL);
   pthread_join(thr3, NULL);
   pthread_join(thr4, NULL);
ftime(&stop);
elapsed=((double) stop.time + ((double) stop.millitm * 0.001)) -
          ((double) start.time + ((double) start.millitm * 0.001));

printf("  It took %7.3f sec to execute this program \n", elapsed);


  
//   printf("\n");

   return 0;
}

void * outputMsg(void * msg)
{
   int i;
   int j;
   int z;
// for(z = 0; z < 8; z++) {
   // printf("running 4 times z = %d\n",z);
   for(i = 0; i < 1000000; i++)
      j = rand();
//}
      
   return NULL;
}
