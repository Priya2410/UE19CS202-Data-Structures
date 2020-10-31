//Single Paranthesis
#include<stdio.h>
#include<stdlib.h>

//declare structure
struct stack
{
    int size;
    int top;
    char *arr;
};
//If stack is empty then return 1 else return 0
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//If stack is full then return 1 else return 0
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr,char data)
{
    if(isFull(ptr)==1)
    {
    printf("Stack is full\n");
    return;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}

char pop(struct stack *ptr)
{
    if(isEmpty(ptr)==1)
    {
    printf("Stack is empty\n");
    return -1;
    }
    else
    {
        char c=ptr->arr[ptr->top];
        ptr->top--;
        return c;
    }
}

char peek(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
int match(char a,char b)
{
    if(a=='(' && b==')')
    return 1;
    else if(a=='[' && b==']')
    return 1;
    else if(a=='{' && b=='}')
    return 1;
    else
    return 0;
}
int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));

    char popped_ch;
    //We will check if the top character and the top of stack match each other or not
    for(int i=0;exp[i]!='\0';i++)
    {
        //if its an opening bracket we have to push it
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        push(sp,exp[i]);

        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(isEmpty(sp)==1)
            return 0;//basically the exp is not balanced
            else
            {
            popped_ch=pop(sp);
            if(!match(popped_ch,exp[i]))
            return 0;
            }
        
        }
    }
    if(isEmpty(sp)==1)
    return 1;
    else
    return 0;
}

int main()
{
    char * exp = "[4-6]((8){(9-8)})";
    
    if(parenthesisMatch(exp)){
        printf("The parenthesis is balanced");
    }
    else{
        printf("The parenthesis is not balanced");
    }
    return 0;
}