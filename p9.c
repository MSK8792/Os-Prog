#include<stdio.h>
#include<string.h>
struct
{
char dname[10],fname[10][10];
int fcnt;
}
dir[10];
void main()
{
int i,ch,dcnt,k;
char f[30],d[30];
dcnt=0;
while(1)
{
printf("\n\n 1.create directory\t 2.create file\t 3.delete file \t 4.search file\t 5.display \t 6.exit\n\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("enter name of directory\n");
	scanf("%s",dir[dcnt].dname);
	dir[dcnt].fcnt=0;
	dcnt++;
	printf("directory created\n");
	break;

case 2: printf("enter name of directory\n");
	scanf("%s",d);
	for(i=0;i<dcnt;i++)
	if(strcmp(d,dir[i].dname)==0)
        {
	 printf("enter name of the file\n");
	 scanf("%s",dir[i].fname[dir[i].fcnt]);
	 dir[i].fcnt++;
	 printf("file created\n");
	 break;
	}
	if(i==dcnt)
	printf("directory %s not found\n",d);
	break;

case 3: printf("\n enter name of the directory..");
	scanf("%s",d);
	for(i=0;i<dcnt;i++)
	{
	if(strcmp(d,dir[i].dname)==0)
	{
	printf("enter the name of the file\n");
	scanf("%s",f);
	for(k=0;k<dir[i].fcnt;k++)
	{
	if(strcmp(f,dir[i].fname[k])==0)
	{
	printf("file %s is deleted\n",f);
	dir[i].fcnt--;
	strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
	goto jmp;
	}
	}
	printf("file %s not found\n",f);
	goto jmp;
	}}
	printf("directory %s not found\n",d);
	jmp:break;

case 4: printf("enter name of directory\n");
	scanf("%s",d);
	for(i=0;i<dcnt;i++)
	{
	if(strcmp(d,dir[i].dname)==0)
	{
	printf("enter name of the file\n");
	scanf("%s",f);
	for(k=0;k<dir[i].fcnt;k++)
	{
	if(strcmp(f,dir[i].fname[k])==0)
	{
	printf("file %s is found",f);
	goto jmp1;
	}
	}
	printf("file %s not found",f);
	goto jmp1;
	}
	}
	printf("directory %s not found",d);
	jmp1:break;

case 5: if(dcnt==0)
	{
	printf("no directories\n");
	}
	else
	{
	printf("\n directory\t files");
	for(i=0;i<dcnt;i++)
	{
	printf("\n %s \t\t",dir[i].dname);
	for(k=0;k<dir[i].fcnt;k++)
	printf("\t %s",dir[i].fname[k]);
	}
	}break;
default: exit(0);
}
}
}






