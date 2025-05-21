#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

void spin(int pid) {
	while(1){
		sleep(0);
		if(getsumticks() >= 1220){
			printpinfo(pid);
			kill(pid);
			break;
		}
	}
}

void printpinfo(int pid){
	struct pstat pi;
	if(getpinfo(&pi) < 0){
		printf(2, "Getting process-info failed");
	}
	int i;
    for (i = 0; i < NPROC; i++) {
        if(pi.pid[i] == pid) {
		    printf(1, "PID: %d, Tickets: %d, Ticks: %d, Inuse: %d\n", pi.pid[i], pi.tickets[i], pi.ticks[i], pi.inuse[i]);
        }
    }
}

int
main(int argc, char *argv[])
{
    resetticks();
	settickets(10);
	int pid1 = fork(); 
    if (!pid1) {
        settickets(10);
        spin(getpid());
        exit(); 
    }
    
    int pid2 = fork();
    if (!pid2) {
        settickets(20);
        spin(getpid());
        exit();
    }
    
    int pid3 = fork();
    if (!pid3) {
        settickets(30);
        spin(getpid());
        exit();
    }

    wait();
    wait();
    wait();
    exit();
}
