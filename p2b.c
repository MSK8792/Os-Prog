// SJF without arr time

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int bur[10],n,i,j,pr[10],turn_time[10],wait_time[10],temp;
	float avgWT=0,avgTAT=0;
	printf("Enter number of processes\n");
	scanf("%d",&n);
	printf("Enter burst times\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bur[i]);
	}
	for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
				{
					if(bur[j]>bur[j+1])
						{
							temp=bur[j];
							bur[j]=bur[j+1];
							bur[j+1]=temp;
							
							temp=pr[j];
							pr[j]=pr[j+1];
							pr[j+1]=temp;
						}
				}
		}
	wait_time[0]=0;
	turn_time[0]=bur[0];	
	for(i=1;i<n;i++)
	{
		wait_time[i]=wait_time[i-1]+bur[i-1];
		turn_time[i]=turn_time[i-1]+bur[i];
		avgWT+=wait_time[i];
		avgTAT+=turn_time[i];
	}
	
	/*
	Gaant chart
	printf("-----------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("P%d	  |",pr[i]+1);
	}
	printf("\n-----------------------------------\n");
	completion[0]=0;
	
	*/
	printf("\nProcess\tBT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\n",i+1,bur[i],turn_time[i],wait_time[i]);
	}
	printf("\nAverage Waiting time: %f\n ms\nAverage Turnaround time: %f\n ms",(avgWT/n),(avgTAT/n));
	
}
		
					

