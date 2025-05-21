# Adding a Lottery Scheduler to Xv6-kernel
Modify scheduler() in proc.c: a random-number processor, a lottery scheduler, regular information printing(for testing), ticks calculator, global varaible --- sumticks & lastticks, etc
· sumticks: ticks that all processes have been running
· lastticks: to prevent sumticks from falling back after the child process exits ()
test.c: Two system calls, getsumticks() (to monitor value of sumticks and terminate the process in a timely manner) & resetticks() (reset sumticks and lastticks to 0)
