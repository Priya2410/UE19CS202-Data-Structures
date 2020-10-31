#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct stack
{
	int a[SIZE];
	int top;
};
struct stack s;
void push()
{
	int ele;
	if(s.top==SIZE-1)
	{
		printf("overflow condition\n");
		return;
	}
	else{
		printf("enter the element to be inserted\n");
		scanf("%d",&ele);
		s.top=s.top+1;
		s.a[s.top]=ele;
	}
}
void display()
{
	if(s.top==-1)
	{
		printf("underflow\n");
		return;
	}
	else{
		for(int i=s.top;i>=0;i--)
		{
			printf("%d\n",s.a[i]);
		}
	}
}
int pop()
{
	int num;
	if(s.top==-1)
	{
		printf("underflow\n");
		return(s.top);
	}
	else{
		num=s.a[s.top];
		s.top=s.top-1;
		return(num);
	}
}
		




int main(void)
{
	int choice,option=1,n;
	s.top=-1;
	while(option)
	{
		printf("1.push\n 2.pop\n 3.display\n 4.exit\n");
		printf("enter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
					break;
			case 2: n=pop();
					printf("%d is deleted\n",n);
					break;
			case 3: display();
					break;
			case 4: exit(0);
		}
		printf("do you want to continue type 0 or1\n");
		scanf("%d",&option);
	}
	return(0);
}
		
			
	

	