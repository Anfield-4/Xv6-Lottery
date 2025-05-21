# Adding a Lottery Scheduler to Xv6-kernel

## Modify scheduler() in proc.c:
A random-number processor, a lottery scheduler, regular information printing (for testing), ticks calculator, global varaible --- *sumticks & lastticks*, etc.  
**sumticks**: ticks that all processes have been running  
**lastticks**: to prevent sumticks from falling back after the child process exits()  

## Add test.c:  
Two system calls, *getsumticks()* (to monitor value of sumticks and terminate the process in a timely manner) & *resetticks()* (reset sumticks and lastticks to 0);  
*main* process set 10 tickets, wait() for the child process, and then exit(). *main* process forks() three processes, sets 10, 20, and 30 tickets respectively, and makes each of them in the while(1) loop until sumticks reaches a certain value, then prints the information, kill() the process and exit().

## xv6-lottery.fig:  
It's a MATLAB figure of ticks obtained by each process in one scheduling.
