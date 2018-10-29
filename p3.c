//Round Robin

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,n,t,bur[10],wt[10],tat[10],ct[10],temp;
	float avgWT=0,avgTAT=0,tempo=0;
	printf("\n Enter number of processes: ");
	scanf("%d",&n);
	printf("\n Enter burst times :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bur[i]);
		ct[i]=bur[i];
	}
	printf("\n Enter time quantum :");
	scanf("%d",&t);
	temp=bur[0];
	for(i=1;i<n;i++)
	{
		if(temp<bur[i])
			temp=bur[i];
	}
	for(j=0;j<(temp/t)+1;j++)
	{
		for(i=0;i<n;i++)
		{
			if(bur[i]!=0)
				if(bur[i]<=t)
				{
					tat[i]=tempo+bur[i];
					tempo=tempo+bur[i];
					bur[i]=0;
				}
				else
				{
					bur[i]=bur[i]-t;
					tempo=tempo+t;
				}
		}
	}
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-ct[i];
		avgTAT+=tat[i];
		avgWT+=wt[i];
	}
	printf("\nProcess\tBT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%d\t%d\t%d\n",i+1,ct[i],tat[i],wt[i]);
	}
	printf("\n Avg WT : %f ms\n Avg TAT : %f ms",(avgWT/n),(avgTAT/n));
	return 0;
}
