#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 5
char stack[SIZE];
int top=-1;
void push(char ele)
{
    stack[++top]=ele;
}
int main(void)
{
    char infix[10],postfix[10],ch,ele;
    int i=0,k=0;
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    push("(");
    strcat(infix,")");
    while((ch==infix[i])!='\0')
    {
        if(ch=='(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            postfix[k++]=ch;
        }
        else if(ch==")")
        {
            while(stack[top]!='(')
            {
                postfix[k++]=pop();
            }
            ele=pop();
        }
        else
        {
            {
                while(pr(stack[top]>=pr(ch))
                {
                    postfix[k++]=pop();
                }
                push(ch);
            }
        }
        
    }
}