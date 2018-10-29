//FCFS

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[10],bur[10],n,i,j,sum=0,completion[10],turn_time[10],wait_time[10];
	float avgWT=0,avgTAT=0;
	printf("Enter number of processes\n");
	scanf("%d",&n);
	printf("Enter arrival times\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter burst times\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bur[i]);
	}
	for(i=0;i<n;i++)
	{
		sum=sum+bur[i];
		completion[i]=sum;
		turn_time[i]=completion[i]-arr[i];
		wait_time[i]=turn_time[i]-bur[i];
	}
	for(i=0;i<n;i++)
	{
		avgWT=avgWT+wait_time[i];
		avgTAT=avgTAT+turn_time[i];
	}
	
	/*
	Gaant Chart
	printf("-----------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("P%d	  |",i+1);
	}
	printf("\n-----------------------------------\n");
	printf("%d	",arr[0]);
	
	*/
	printf("\nProcess\tA.T\tB.T\tC.T\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,arr[i],bur[i],completion[i],turn_time[i],wait_time[i]);
	}
	printf("\n");
	printf("Average Waiting time: %f ms\n Average Turnaround time: %f ms\n",(avgWT/n),(avgTAT/n));
	
}
		
					

