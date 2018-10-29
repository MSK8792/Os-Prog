#include<stdio.h>
#include<stdlib.h>

enum state
{ 
	eating,hungry,thinking
}

state[5];
int self[5];

int signal()
{
    return eating;
}
int wait()
{
 	return hungry;
}
void init(int n)
{
 	int i;
 	for(i=0;i<n;i++)
 	{
 		state[i]=thinking;
 	}
}

void test(int i,int n)
{
	if((state[(i+n-1)%n]!=eating) && (state[(i+1)%n]!=eating) && (state[i]==hungry))
	{
	      
	 	state[i]=eating;
	 	self[i]=signal();
	 }
}

void pickup(int i,int n)
{
	state[i]=hungry;
	test(i,n);
	if(state[i]!=eating)
	{
	   self[i]=wait();
	   printf("\nPhilosopher %d is hungry and waiting\n",i+1);
	}  
	else
	   printf("\nPhilosopher %d is eating\n",i+1);

}

void putdown(int i,int n)
{
	state[i]=thinking;
	printf("\nPhilosopher %d is thinking\n",i+1);
	test((i+n-1)%n,n);
	test((i+1)%n,n);
}
void showstatus(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(state[i] == eating)
			  printf("\nPhilosopher %d is eating\n",i+1);
		else if(state[i] == thinking)
			printf("\nPhilosopher %d is thinking\n",i+1);
		else
			printf("\nPhilosopher %d is hungry\n",i+1);
	}
}

int main()
{
	int ch,i=0,n;
	printf("\n Enter no of philosophers :");
	scanf("%d",&n);
	init(n);
	while(1)
	{
		printf("\n1.Pickup\t2.Putdown\t3.Show Status\t4.Exit\n");
		printf("\n Enter your choice :");   
		scanf("%d",&ch);
		switch(ch)
		{
		 	case 1: printf("\nEnter the Philosopher no :");
					scanf("%d",&i);
					pickup(i-1,n);
					break;
			case 2: printf("\nEnter the Philosopher no :");
					scanf("%d",&i);
					putdown(i-1,n);
					break;
			case 3:showstatus(n);
					break;
			case 4:return 0;
		}
 	}
 	return 0;
 }
