//  Author:  Cory A. Olmo 
//  Date:    January 20, 2000
//  File:    timer.h 
//  Purpose: To provide a convenient set of routines for timing a
//           program, routine, or block of code's execution.



#include <sys/time.h>
#include <sys/resource.h>


// Structure representing the start and end times for the timer

struct proc_time
{
  struct rusage init_usage;
  struct rusage end_usage;
  struct rusage tot_usage;
};


// Initialize the timer structure
struct proc_time *init_timer();

// Get the current rusage times for initial time values
void start_timer( struct proc_time * );

// Get the current rusage times for the end time values
void stop_timer( struct proc_time * );

// Can handle printing out the rusage structure
void print_time_interval( struct proc_time * );

