#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
static volatile int got_interrupt = 0;

void sighandler(int i)
{
	got_interrupt = 1;
}
//infinity loop program
int main(int argc, char* argv[])
{
	signal(SIGINT,sighandler);
	while(1)
	{
		if(got_interrupt)
		{
				printf("Here we got an interrupt\n");
				got_interrupt = 0;
		}
	}
	return 0;
}
