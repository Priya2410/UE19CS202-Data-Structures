#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void push(int data,int *a,int *top)
{
	if(*top==SIZE-1)
	{
		printf("%s\n","Stack is full");
		return;
	}
	else
	{
		a[++*top]=data;
	}

}
int pop(int *a,int *top)
{
	if(*top==-1)
	{
		return -1;
	}
	else
	{
		int data=a[*top];
		*top=*top-1;
		return data; 
	}
}
void display(int *top,int *a)
{
	if(*top==-1)
	{
		printf("%s\n","Stack is empty" );
		return;
	}
	else
	{
		for(int i=*top;i>=0;i--)
		{
			printf("%d ",a[i]);
		}
	}
}

int main()
{
	int top=-1;
	int s[SIZE];
	int data,n,option;
	while(1)
	{
		printf("\n1.push\n2.pop\n3.display\n4.exit\n");
		printf("%s\n","Enter the choice" );
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("%s\n","Enter the data");
			scanf("%d",&data);
			push(data,s,&top);
			break;
			case 2:
			n=pop(s,&top);
			if(n==-1)
				printf("%s\n","Stack is empty" );
			else
				printf("%d ",n );
				printf("Deleted\n");
			break;
			case 3:
			display(&top,s);
			break;
			case 4:
			exit(0);
			break;
		}
	}
}
