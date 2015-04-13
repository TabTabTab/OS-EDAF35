#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

static volatile int got_USR2_signal=0; 
struct sigaction action;
struct sigaction action2;
int procced =1;
/*
void usr2_sig_handler(int signal_code){
	printf("USR2-Signal\n");
}
void int_sig_handler(int signal_code){
	sigemptyset(&action2.sa_mask);
	action2.sa_handler = usr2_sig_handler;
	sigaction(SIGUSR2,&action2,NULL);
	while(1){
		
	}
}
*/
void alarm_handler(int signal_code){
	procced =0;
}


int main(){
	signal(SIGALRM,alarm_handler);
	alarm(12);

	unsigned long long int counter =0;
	while(procced){
		counter++;	
	}
	printf("Number of iterations of the loop: %llu",counter);


/*
	time_t endwait;
    time_t start = time(NULL);
    time_t seconds = 10;

    endwait = start + seconds;


	sigset_t signal_set;
	sigemptyset(&signal_set);
	sigaddset(&signal_set,SIGUSR1);
	sigaddset(&signal_set,SIGUSR2);
	sigprocmask(SIG_BLOCK,&signal_set,NULL);
	sigset_t pending_set;
	printf("Before loop\n");
	while(start<endwait){
		start = time(NULL);
	}
	sigpending(&pending_set);
	/*if(sigismember(&pending_set,SIGUSR1)){
		printf("we got the USR1 - signal!");
	} */
/*
	int i;
	for(i=0; i < _NSIG-1; ++i){
		if(sigismember(&pending_set, i)) {
			fprintf(stderr, "BLOCKED: SIG-%d\n", i );
		}
	}

	
	printf("after loop\n"); */
}
