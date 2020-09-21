#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void push(int ele,int *top,int a[])
{
	if(*top==SIZE-1)
	{
		printf("stack overflow");
		return;
	}
	*top=*top+1;
	a[*top]=ele;
}
int pop(int *top,int a[])
{
	if(*top==-1)
	{
		return(0);
	}
	int del_ele=a[(*top)--];
	return(del_ele);
}
void display(int *top,int a[])
{
	if(*top==-1)
	{
		printf("stack is empty");
		return;
	}
	for(int i=*top;i>=0;i--)
		printf("%d\n",a[i]);
}


int main() 
{
    int top=-1,s[SIZE];
   	int choice,option=1,n,ele;
	
	while(option)
	{
		printf("1.push\n 2.pop\n 3.display\n 4.exit\n");
		printf("enter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the element to be inserted\n");
					scanf("%d",&ele);
					push(ele,&top,s);
					break;
			case 2: n=pop(&top,s);
					if(n==0)
					{
						printf("underflow\n");
					}
					else
						printf("%d is deleted",n);			
					
									
					break;
			case 3: display(&top,s);
					break;
			case 4: exit(0);
		}
		printf("do you want to continue type 0 or1\n");
		scanf("%d",&option);
	}
	return(0);
}
		
			
	

 
