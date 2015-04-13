#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static volatile int got_USR2_signal=0; 
struct sigaction action;
struct sigaction action2;

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



int main(){

	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask,SIGUSR1);
	action.sa_handler = int_sig_handler;
	sigaction(SIGINT,&action,NULL);

	
	while(1){
	}
}
