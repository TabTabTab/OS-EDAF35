#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static volatile int gotSignal=0; 


void ctrlCHandler(int signalCode){
	gotSignal=1;
}


//Varför kan vi bara ta ett CTRL-C interupt
//varför kan man inte använda printf i signalhandlern? och kan man printa på något sätt där?

int main(){
	signal(SIGINT,ctrlCHandler);
	while(1){
		if(gotSignal){
			printf("we got a ctrl-C signal (SIGINT)\n");
			gotSignal=0;	
		}
	}
}
