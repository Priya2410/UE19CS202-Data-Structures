#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct stack
{
	int a[SIZE];
	int top;
};
void inittop(struct stack *s)
{
	s->top=-1;
}

void push(struct stack *s,int ele)
{
	
	if(s->top==SIZE-1)
	{
		printf("overflow condition\n");
		return;
	}
	else{
		s->top++;
		s->a[s->top]=ele;
	}
}
void display(struct stack *s)
{
	if(s->top==-1)
	{
		printf("underflow\n");
		return;
	}
	else{
		for(int i=s->top;i>=0;i--)
		{
			printf("%d\n",s->a[i]);
		}
	}
}
int pop(struct stack *s)
{
	int num;
	if(s->top==-1)
	{
		printf("underflow\n");
		return(s->top);
	}
	else{
		num=s->a[s->top];
		s->top--;
		return(num);
	}
}
		




int main(void)
{
	int choice,option=1,n,ele;
	struct stack ptr;
	inittop(&ptr);
	
	while(option)
	{
		printf("1.push\n 2.pop\n 3.display\n 4.exit\n");
		printf("enter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the element to be inserted\n");
					scanf("%d",&ele);
					push(&ptr,ele);
					break;
			case 2: n=pop(&ptr);
					printf("%d is deleted\n",n);
					break;
			case 3: display(&ptr);
					break;
			case 4: exit(0);
		}
		printf("do you want to continue type 0 or1\n");
		scanf("%d",&option);
	}
	return(0);
}
		
			
	

	