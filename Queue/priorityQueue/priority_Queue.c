#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void insert_ele(int ele,int *q,int *r)
{
	int j;
	if(*r==SIZE-1)
	{
		printf("Queue is full");
		return;
	}
	j=*r;
	while(j>=0 &&ele <q[j])
	{
		q[j+1]=q[j];
		j--;
	}
	q[j+1]=ele;
	*r=*r+1;
}
int delete_front(int *f,int *r,int 
q[])
{
	if(*f>*r)
	{
		return -1;
	}
	return (q[(*f)++]);
}
void display(int f,int r,int q[])
{
	if(f>r)
	{
		printf("queue is empty");
		return;
	}
	for(int i=f;i<=r;i++)
	{
		printf("%d\t",q[i]);
	}
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
					insert_ele(ele,q,&rear);
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
					
		
