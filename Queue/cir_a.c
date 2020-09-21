#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void insert(int *f,int *r,int q[],int ele)
{
	if(((*r+1)%SIZE)==*f)
	{
		printf("Circular queue is full\n");
		return;
	}
	if(*f==-1 && *r==-1)
	{
		*f=*r=0;
		q[*r]=ele;
	}
	else
	{
		*r=((*r+1)%SIZE);
		q[*r]=ele;
    }
}
void display(int *f,int *r,int q[])
{

	if(*f==-1&& *r==-1)
	{
		printf("underflow condition");
		return;
		
	}
	else{
		for(int i=*f;i!=*r;i++)
			printf("%d\t",q[i]);
		printf("%d\t",q[*r]);
	}
}

void delete(int *f,int *r,int q[])
{
	if(*f==-1 && *r==-1)
	{
		printf("underflow condition");
		return;
	}
	else if( *f==*r)
	{
		printf("%d is deleted\n",q[*f]);
		*r=*f=-1;
	}
	else
	{
		printf("%d is deleted",q[*f]);
		*f=((*f+1)%SIZE);
	}
}

void main()
{
	int f=-1,r=-1,q[SIZE], ele,choice;
	for(;;)
   {
	   printf("\n1.insert\n 2.delete\n 3. Display\n  4.Exit\n");
	   printf("enter the choice\n");
	   scanf("%d",&choice);
	   switch(choice)
	   {
		   case 1: printf("enter the ele\n");
					scanf("%d",&ele);
					insert(&f,&r,q,ele);
					break;
			case 2: delete(&f,&r,q);
					break;
			case 3:
					display(&f,&r,q);
					break;
			default: exit(0);
	   }
   }
}
	
		
		
		