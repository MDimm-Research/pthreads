//
//  Author:  Cory A. Olmo
//  Date:    January 20, 2000
//  File:    timer.c
//  Purpose: To provide a convenient set of routines for timing the execution
//           of a program, routine, or block of code.
//           


#include "timer.h"
#include <stdlib.h>
#include <stdio.h>

// Before making use of the timer routines you need to call this function
// to create the timer structure that will be used by the other functions

struct proc_time * init_timer()
{
  struct proc_time *p_time;

  p_time = (struct proc_time*)malloc(sizeof(struct proc_time));
  return p_time;
}


// Just insert the call to this function with the struct proc_time *,
// that init_timer() returned, where ever you would like the timer to 
// begin timing program execution.

void start_timer( struct proc_time *p_time )
{
  getrusage( RUSAGE_SELF, &(p_time->init_usage) );
}


// Just insert the call to this function with the struct proc_time *,
// that init_timer() returned, where ever you would like the timer to 
// end timing program execution.

void stop_timer( struct proc_time *p_time )
{
  getrusage( RUSAGE_SELF, &(p_time->end_usage) );

  // Calculate the ending time stats
  p_time->tot_usage.ru_utime.tv_sec = p_time->end_usage.ru_utime.tv_sec - 
    p_time->init_usage.ru_utime.tv_sec;
  p_time->tot_usage.ru_utime.tv_usec = p_time->end_usage.ru_utime.tv_usec - 
    p_time->init_usage.ru_utime.tv_usec;
  if ( p_time->tot_usage.ru_utime.tv_usec < 0 )
    p_time->tot_usage.ru_utime.tv_usec = 
            1000000 + p_time->tot_usage.ru_utime.tv_usec;
   p_time->tot_usage.ru_utime.tv_sec -= 1; // added by Chris
  p_time->tot_usage.ru_stime.tv_sec = p_time->end_usage.ru_stime.tv_sec - 
    p_time->init_usage.ru_stime.tv_sec;
  p_time->tot_usage.ru_stime.tv_usec = p_time->end_usage.ru_stime.tv_usec - 
    p_time->init_usage.ru_stime.tv_usec;
  if ( p_time->tot_usage.ru_stime.tv_usec < 0 )
    p_time->tot_usage.ru_stime.tv_usec = 
            1000000 + p_time->tot_usage.ru_stime.tv_usec;
    p_time->tot_usage.ru_stime.tv_sec -= 1; // added by Chris
}

// This function just prints out the usage times like so
// CPU usage: User = 0.080000 secs, System = 0.010000 secs

void print_time_interval( struct proc_time *p_time )
{
  printf("CPU usage: User = %ld.%06ld secs, System = %ld.%06ld secs\n", 
         p_time->tot_usage.ru_utime.tv_sec, 
         p_time->tot_usage.ru_utime.tv_usec,
         p_time->tot_usage.ru_stime.tv_sec, 
         p_time->tot_usage.ru_stime.tv_usec);
}

