#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int compute(char sym,int op1,int op2)
{
	switch(sym)
	{
	case '+':return op1+op2;
	case '-':return op1-op2;
	case '*':return op1*op2;
	case '/': return op1/op2;
	case '$':
	case '^': return(pow(op1,op2));
	default:return 0;
	}
}
int main()
{
	int s[10];
	int res,op1,op2;
	int top;
	char postfix[20];
	char sym;
	printf("enter the postfix expression\n");
	scanf("%s",postfix);
	top=-1;
	for(int i=0;i<strlen(postfix);i++)
	{
		sym=postfix[i];
		if(isdigit(sym))
		{
			s[++top]=sym-'0';
		}
		else
		{
			op2=s[top--];
			op1=s[top--];
			res=compute(sym,op1,op2);
			s[++top]=res;
		}
	}
	res=s[top--];
	printf("result of evaluvation=%d",res);
}

			