#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 25

int top=-1;
int stack[MAX];//Array as stack

void push(char item)
{
    if(top==MAX-1)
    {
        printf("Stack is full\n");
        return;
    }
    stack[++top]=item;
}
char pop()
{
    char data;
    if(top==-1)
    {
        printf("The stack is empty\n");
        return '\0';
    }
    else
    {
        data=stack[top--];
        return data;
    }
    
}
//Checks whether the element popped is same as the exp[i]
int match(char a,char b)
{
    if(a=='(' && b==')')
    return 1;
    else if(a=='{' && b=='}')
    return 1;
    else if(a=='[' && b==']')
    return 1;
    else
    {
      return 0;  
    }
}

int check(char exp[])
{
    int i;
    char temp;
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        push(exp[i]);
        if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(top==-1)
            {
            printf("Invalid case\n");
            return 0;
            }
            temp =pop();
            if(!match(temp,exp[i]))
            {
                printf("invalid\n");
                 return 0;
            }
        }
    }   
if(top==-1)
    {
        printf("Expression is valid\n");
        return (1);
    }
    else
    {
        printf("The expression is unbalanced\n");
        return 0;
    }
}
int main()
{
    char exp[MAX];
    int flag;
    printf("Enter the expression\n");
    scanf("%s",exp);
    check(exp);
}
