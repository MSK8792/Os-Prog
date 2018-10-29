#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main()
{
int *p,flag[100],temp,i,j,m,n,process[100],alloc[100],mem1[100],mem2[100],ch;
printf("enter the no. of process\n");
scanf("%d",&n);
printf("enter each process memory size\n");
for(i=0;i<n;i++)
scanf("%d",&process[i]);
printf("enter the no. of memory blocks available\n");
scanf("%d",&m);
p=(int*)malloc(m*sizeof(int));
printf("enter the value of memory blocks\n");
for(i=0;i<m;i++)
{scanf("%d",(p+i));
mem1[i]=(*(p+i));
mem2[i]=(*(p+i));
}
while(1)
{
printf("1.first fit\t2.best fit\t3.worst fit\t4.exit\n");
printf("enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:for(i=0;i<n;i++)
       {
       for(j=0;j<m;j++)
       {
       if(process[i]<=(*(p+j)))
       {
       alloc[i]=*(p+j);
       *(p+j)=*(p+j)-process[i];
       flag[i]=0;
       break;
       }
       }
       if(j==m)
       {
       flag[i]=1;
       }
       }
       printf("allocation\n");
       for(i=0;i<n;i++)
       {
       if(flag[i]==0)
       printf("p%d of %d is allocated to %d\n",i+1,process[i],alloc[i]);
       else
       printf("p%d of %d must wait\n",i+1,process[i]);
       }
       break;
case 2:for(i=0;i<m;i++)
       {
       for(j=i+1;j<m;j++)
       {
       if(mem1[i]>mem1[j])
       {
       temp=mem1[i];
       mem1[i]=mem1[j];
       mem1[j]=temp;
       }}}
       printf("after sorting memory blocks available:\n");
       for(i=0;i<m;i++)
       {
       printf("%d\n",mem1[i]);
       }
       for(i=0;i<n;i++)
       {
       for(j=0;j<m;j++)
       {
        if(process[i]<=mem1[j])
       {
       alloc[i]=mem1[j];
       flag[i]=0;
       mem1[j]=0;
       break;
       }
       }
       if(j==m)
       flag[i]=1;
       }
       printf("allocation\n");
       for(i=0;i<n;i++)
       {
       if(flag[i]==0)
       printf("p%d of %d is allocated to %d\n",i+1,process[i],alloc[i]);
       else
       printf("p%d of %d must wait\n",i+1,process[i]);
       }
       break;
case 3:for(i=0;i<m;i++)
       {
       for(j=i+1;j<m;j++)
       {
       if(mem2[i]<mem2[j])
       {
       temp=mem2[i];
       mem2[i]=mem2[j];
       mem2[j]=temp;
       }
       }
       }
       for(i=0;i<n;i++)
       {
       for(j=0;j<m;j++)
       {
       if(process[i]<=mem2[j])
       {
       alloc[i]=mem2[j];
       flag[i]=0;
       mem2[j]=0;
       break;
       }}
       if(j==m)
       flag[i]=1;
       }
        printf("allocation\n");
       for(i=0;i<n;i++)
       {
       if(flag[i]==0)
       printf("p%d of %d is allocated to %d\n",i+1,process[i],alloc[i]);
       else
       printf("p%d of %d must wait\n",i+1,process[i]);
       }
       break;
case 4:return 0;
break;
}
}}
                    
              
              
