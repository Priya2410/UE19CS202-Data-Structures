#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct stack
{
	int top;
	int a[SIZE];
}s;
void push()
{
	if(s.top==SIZE)
	{
		printf("%s\n","Stack is full-overflow");
		return;
	}
	else
	{
		s.top=s.top+1;
		int ele;
		printf("%s\n","Enter the element");
		scanf("%d",&ele);
		s.a[s.top]=ele;
	}
}
int pop()
{
	int num;
	if(s.top==-1)
	{
		printf("%s\n","Stack is empty" );
		return -1;
	}
	else if (s.top==0)
	{
		s.top=-1;
		return -1;
	}
	else
	{
		num=s.a[s.top];
		s.top=s.top-1;
		return num;
	}
}
void display()
{
	int i;
	if(s.top==-1)
	{
		printf("%s\n","Stack is empty");
	}
	else
	{
		for(i=s.top;i>0;i--)
		{
			printf("%d ",s.a[i]);
		}
	}
}
int main()
{
	int choice;
	int n;
	s.top=-1;
	while(1)
	{
		printf("\n%s\n","Enter 1 for push");
		printf("\n%s\n","Enter 2 for pop");
		printf("\n%s\n","Enter 3 for display");
		printf("\n%s\n","Enter 4 for exit");
		printf("\n%s\n","Enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			push();
			break;
			case 2:
			n=pop();
			if(n==-1)
				printf("%s\n","No element is popped");
			else
			{
			printf("%s","Element popped is:");
			printf("%d\n",n);
			}
			break;
			case 3:
			display();
			break;
			case 4:
			exit(0);
			break;
		}
	}
}