//sjf with arrival time
#include<stdio.h>
#include<stdlib.h>
int main()
{
int at[20],j,i,n,k,tt[20],wt[20],bt[20],p[20],temp,smallest,index,tat,twt;
float avgwt,avgtt;
printf("Enter the no. of processes\n");
scanf("%d",&n);
printf("Enter the burst time\n");
for(i=0;i<n;i++)
{
printf("p%d :",i+1);
scanf("%d",&bt[i]);
p[i]=i;
}
printf("Enter the arrival time\n");
for(i=0;i<n;i++)
{
printf("a%d :",i+1);
scanf("%d",&at[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(at[j+1]<at[j])
{
temp=at[j];
at[j]=at[j+1];
at[j+1]=temp;

temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;

temp=bt[j];
bt[j]=bt[j+1];
bt[j+1]=temp;
}
}
}
tt[0]=tat=bt[0];
wt[0]=twt=at[0];
for(i=1;i<n;i++)
{
smallest=bt[i];
index=i;
for(j=i+1;j<n;j++)
{
if(at[j]<=tt[i-1] && bt[j]<smallest)
{
smallest=bt[j];
index=j;
}
}
tt[i]=bt[index]+tt[i-1];
tat+=tt[i];
temp=p[i];
p[i]=p[index];
p[index]=temp;

temp=at[i];
at[i]=at[index];
at[index]=temp;

temp=bt[i];
bt[i]=bt[index];
bt[index]=temp;
wt[i]=tt[i]-at[i]-bt[i];
twt+=wt[i];
}
avgwt=(float) twt/n;
avgtt=(float)tat/n;
printf("process\tat\tbt\twt\ttt\n");
 for(i=0;i<n;i++)
 {
 printf("p %d\t %d\t %d\t %d\t %d\n",p[i]+1,at[i],bt[i],wt[i],tt[i]);
 }
 printf("avg wt=%f\n",avgwt);
 printf("avg tt=%f\n",avgtt);
 }
