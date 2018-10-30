#include<stdio.h>
int wt[10],tat[10],bt[10],n,ct[10],s[10],at[10];
float avgwt,avgtat;
void avg(){
	int i;
	avgwt=avgtat=0;
	for(i=0;i<n;i++){
		avgwt+=(float)wt[i]/n;
		avgtat+=(float)tat[i]/n;
	}
	printf("The average turn around time is %f\n",avgtat);
	printf("The average wait time is %f\n",avgwt);
}
void calc(){
	int i;
	for(i=0;i<n;i++){
		tat[s[i]]=ct[s[i]]-at[s[i]];
		wt[s[i]]=tat[s[i]]-bt[s[i]];
	}
}
void sort(int l,int n,int s[],int x[],int y){
	int i,j,temp,t[10];
	for(i=l;i<n;i++){
		if(y==1)s[i]=i;else if(y==2)s[i]=bt[i];else if(y==3)s[i]=at[i];
		t[i]=x[i];
	}
	for(i=l;i<n;i++)
		for(j=l;j<n-1;j++)
			if(t[j]>t[j+1]){
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
}
void sjf(){
	int i,j,lim,sorted_bt[10],sorted_at[10];
	sort(0,n,s,at,1);
	sort(0,n,sorted_bt,at,2);
	sort(0,n,sorted_at,at,3);
	ct[s[0]]=at[s[0]]+bt[s[0]];
	for(i=0;i<n;i+=lim){
		for(j=i+1;j<n;j++)
			if(sorted_at[j]<=ct[s[i]]) lim=j;
			else break;
		sort(i+1,lim+1,s,sorted_bt,0);
		for(j=i+1;j<=lim;j++) ct[s[j]]=ct[s[j-1]]+bt[s[j]];
	}
	calc();
}
void disp(){
	int i;
	printf("PROCESS\tA.T\tB.T\tC.T\tT.A.T\tW.T\n");
	for(i=0;i<n;i++) printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	avg();
}
void main(){
	int i;
	printf("Enter the number of processes ");
	scanf("%d",&n);
	printf("Enter the arrival times of the processes\n");
	for(i=0;i<n;i++) scanf("%d",&at[i]);
	printf("Enter the burst times of the processes\n");
	for(i=0;i<n;i++) scanf("%d",&bt[i]);
	printf("\nNon Preemptive SJF\n");
	sjf();
	disp();
	
}
