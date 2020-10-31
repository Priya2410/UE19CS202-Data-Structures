#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void insert_rear(int ele,int *r,int *q)
{
	if(*r==SIZE-1)
	{
		printf("Queue is full\n");
		return;
	}
	*r=*r+1;
	q[*r]=ele;
}
int delete_front(int *f,int *r,int *q)
{
	if(*f>*r)
		return -1;
	else
		return q[(*f)++];
}
void display(int f,int r,int q[])
{
	if(f>r)
	{
		printf("Queue is empty");
		return;
	}
	printf("contents are:\n");
	for(int i=f;i<=r;i++)
		printf("%d\n",q[i]);
}
void display(int f,int r,int q[])
{
	if(f>r)
	{
		printf("Queue is empty");
		return;
	}
	printf("contents are:\n");
	for(int i=f;i<=r;i++)
		printf("%d\n",q[i]);
}
void main()
{
	
   int front =0;
   int rear=-1,ele;
   int choice,q[SIZE];
   for(;;)
   {
	   printf("1.insert\n 2.delete\n 3. Display\n  4.Exit\n");
	   printf("enter the choice\n");
	   scanf("%d",&choice);
	   switch(choice)
	   {
		   case 1: printf("enter the ele");
					scanf("%d",&ele);
					insert_rear(ele,&rear,q);
					break;
			case 2: ele=delete_front(&front,&rear,q);
					if(ele==-1)
					{
						printf("Queue is empty");
					}
					else
					{
						printf("element deleted is:%d",ele);
					}
					break;
			case 3:
					display(front,rear,q);
					break;
			default: exit(0);
	   }
   }
}
					
	   