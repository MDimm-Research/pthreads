/********************************************************
 * An example source module to accompany...
 *
 * "Using POSIX Threads: Programming with Pthreads"
 *     by Brad nichols, Dick Buttlar, Jackie Farrell
 *     O'Reilly & Associates, Inc.
 *
 ********************************************************
 * simple_threads.c
 *
 * Simple multi-threaded example.
 */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

#include "timer.h"

void do_one_thing(int *);
void do_another_thing(int *);
void do_wrap_up(int, int);
void mon(int );

int r1 = 0, r2 = 0;

//  pthread_t       thread1, thread2;
int i;
struct proc_time *timer;


pthread_mutex_t printfLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t xx = PTHREAD_MUTEX_INITIALIZER;

main(void)
{
 
  pthread_t       thread1[5], thread2;
  int ii;
  time_t t1, t2;
  timer = init_timer();

   time(&t1);
   start_timer(timer);

   for (i = 0; i < 5; ++i)  {
//    sleep(2);
      if (pthread_create(&(thread1[i]), NULL, (void *) do_one_thing, 
           (void *) &i) != 0)
    perror("pthread_create"), exit(1); 
   }

//  if (pthread_create(&thread2, NULL, (void *) do_another_thing,
//       (void *) &r2) != 0)
//   perror("pthread_create"), exit(1); 
  
  for (ii = 0; ii < 5;ii++)
     if (pthread_join(thread1[ii], NULL) != 0)
      perror("pthread_join"),exit(1);

//  if (pthread_join(thread2, NULL) != 0)
//   perror("pthread_join"),exit(1);

//  do_wrap_up(r1, r2);

stop_timer(timer);
print_time_interval(timer);
printf("\nThe loop ran for %ld.%06ld seconds\n",
timer->tot_usage.ru_utime.tv_sec,
timer->tot_usage.ru_utime.tv_usec);

time(&t2);
printf("my diff time %d \n",t2-t1);

  return 0; 
}

void do_one_thing(int *thindx)
{
//   sleep(10);
      printf("doing one thing %d \n", * thindx); 
      printf("the thread id is %d \n",pthread_self());
      mon(* thindx);
}
/*
void do_another_thing(int *pnum_times)
{
   int i, j, x;
  
//   sleep(10);
   for (i = 0;  i < 100000000; i++) {
//      printf("doing another %d\n", thread2); 
//      sleep(1);
      (*pnum_times)++;
      mon(thread2);
  }

}
*/

void do_wrap_up(int one_times, int another_times)
{
   int total;

   total = one_times + another_times;
   printf("All done, one thing %d, another %d for a total of %d\n",
   one_times, another_times, total);
}

void mon(int th)
{
//  if (iam a producer)
   pthread_mutex_lock(&printfLock);

   printf("in the monitor %d\n",th);
    
   pthread_mutex_unlock(&printfLock);


   pthread_mutex_lock(&xx);

   printf("in the monitor %d\n",th);

   pthread_mutex_unlock(&xx);
   pthread_mutex_unlock(&xx);

}
