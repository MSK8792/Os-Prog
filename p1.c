#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	pid_t child;
	child=fork();
	if(child==0)
	{
		printf("\nChild process");
		printf("\n My pid=%d My parent id=%d",getpid(),getppid());
		exit(0);
	}
	else
	{
		wait();
		printf("\n Parent process\n");
		printf("my pid=%d My child id=%d\n",getpid(),child);
	}
}
