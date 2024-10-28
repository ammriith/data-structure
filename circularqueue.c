#include<stdio.h>
#include<stdlib.h>
#define size 4
int que[size];
int front=0,rear=0;
void main()
{
void insertq(int);
int deleteq();
int serq(int);
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
printf("search data :");
scanf("%d",&data);
if(serq(data)==1)
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
int trear;
trear=(rear+1)%size;
if(trear==front)
printf("Queue is full \n ");
else
{
rear=trear;
que[rear]=item;
}
}

int deleteq()
{
if(front==rear)
{
printf("Queue is empty \n");
exit(1);
}
else
front=(front+1)%size;

return que[front];
}
int serq(int item)
{
int tfront;
tfront=(front+1)%size;
while(tfront!=rear&&que[tfront]!=item)
tfront=(tfront+1)%size;
if(que[tfront]==item)
return 1;
return 0;
}
