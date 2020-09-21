#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void insert_front(int ele,int *q,int *f,int *r)
{
	if(*f==0&& *r==-1)
	{
		q[++(*r)]=ele;
		return;
	}
	if(*f!=0)
	{
		q[--(*f)]=ele;
		return;
	}
	else{
		printf("front insertion not possible");
	}
}
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
int delete_rear(int *q,int *f,int *r)
{
	int ele;
	if(*f>*r)
		return -1;
	ele=q[(*r)--];
	if(*f>*r)
		*f=0,*r=-1;
	return ele;
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
	   printf("1.insert at front\n 2.Insert at rear\n 3.delete front \n 4.Delete rear\n 5.Display\n  6.Exit\n");
	   printf("enter the choice\n");
	   scanf("%d",&choice);
	   switch(choice)
	   {
		   case 1: printf("enter the ele");
					scanf("%d",&ele);
					insert_front(ele,q,&front,&rear);
					break;
			case 2:	printf("enter the ele");
					scanf("%d",&ele);
					insert_rear(ele,&rear,q);
					break;
			case 3: ele=delete_front(&front,&rear,q);
					if(ele==-1)
					{
						printf("Queue is empty");
					}
					else
					{
						printf("element deleted is:%d",ele);
					}
					break;
			case 4:	ele=delete_rear(q,&front,&rear);
					if(ele==-1)
					{
						printf("Queue is empty");
					}
					else
					{
						printf("element deleted is:%d",ele);
					}
					break;
			case 5:
					display(front,rear,q);
					break;
			default: exit(0);
	   }
   }
}
					