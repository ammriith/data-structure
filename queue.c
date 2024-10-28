#include<stdio.h>
#include<stdlib.h>
#define size 4
int que[size];
int front=-1,rear=-1;
void main()
{
void insertq(int);
int deleteq();
int searchq(int);
int data,opt;
do
{
printf("\n 1.insert \n");
printf("2.delete \n");
printf("3.search \n");
printf("4.exit \n");
printf("Enter your choice:");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("Data:");
scanf("%d",&data);
insertq(data);
break;
case 2:
data=deleteq();
printf("Deleted item: %d \n",data);
break;
case 3:
printf("item to search:");
scanf("%d",&data);
if(searchq(data)==1)
printf("found \n");
else
printf("Not found \n");
break;
case 4:
exit(0);
}
}
while(1);
}
void insertq(int item)
{
if(rear==size-1)
printf("Queue is full \n");
else
que[++rear]=item;
}
int deleteq()
{
if(front==rear)
{
printf("Queue is empty \n");
exit(0);
}
else
return que[++front];
}
int searchq(int item)
{
if(front==rear)
return 0;
int tfront=front+1;
while(tfront!=rear&&que[tfront]!=item)
++tfront;
if(que[tfront]==item)
return 1;
return 0;
}





