#include "6b.h"
stack* stack_initialize(int size)
{
//TODO
stack *ptr_stack=(stack*)malloc(sizeof(stack));
ptr_stack->arr=(int *)malloc(size);
ptr_stack->top=-1;
return ptr_stack;
}

void stack_push(stack *ptr_stack, int key) 
{
//TODO
if(ptr_stack->top<=2000-1)
{
    ptr_stack->top+=1;
    ptr_stack->arr[ptr_stack->top]=key;
}

}

void stack_pop(stack *ptr_stack)
{
//TODO
if(stack_is_empty(ptr_stack)!=1)
    ptr_stack->top-=1;

}

int stack_is_empty(stack *ptr_stack)
{
//TODO
if(ptr_stack->top==-1)
   return 1;
else
{
    return 0;
}

}

int stack_peek(stack *ptr_stack) 
{
//TODO
int up;
up=ptr_stack->arr[ptr_stack->top];
return up;
}

void stack_destroy(stack *ptr_stack) 
{
//TODO
free(ptr_stack);
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
//TODO
    stack* ptr_stack;
    int size=2000;
    ptr_stack=stack_initialize(size);
    int i=0,k=0;
    char ch,a,end;
    while(i<strlen(source_infix))
    {
        ch=source_infix[i];
        if(ch=='(' || ch=='{' || ch=='[')
        {
            stack_push(ptr_stack,(ch));
        }
        else if(ch=='+' || ch=='-')
        {
            if(stack_is_empty(ptr_stack)==1)
                    {
                        stack_push(ptr_stack,ch);
                    }
            else
            {
                a=stack_peek(ptr_stack);
                if(stack_peek(ptr_stack)=='*' || stack_peek(ptr_stack)=='/')
                {
                    while(a=='*' || a=='/')
                    {
                        target_postfix[k++]=stack_peek(ptr_stack);
                        stack_pop(ptr_stack);
                        a=stack_peek(ptr_stack);
                    }
                    stack_push(ptr_stack,ch);
                }
                else
                {
                    stack_push(ptr_stack,ch);
                }
            }
        }
            else if(ch=='*' || ch=='/')
            {
                stack_push(ptr_stack,ch);
            }
           else if(ch==')' || ch=='}' || ch==']')
           {
               if(stack_is_empty(ptr_stack)==1)
                    return;
                switch(ch)
                {
                    case ')':end='(';break;
                    case '}':end='{';break;
                    case ']':end='[';break;
                }
                a=stack_peek(ptr_stack);
                while(a!=end)
                {
                    target_postfix[k++]=a;
                    stack_pop(ptr_stack);
                    a=stack_peek(ptr_stack);
                }
                stack_pop(ptr_stack);
           } 
           else
           {
               if(((ch>='A') && (ch<='Z')) || ((ch>='a') && (ch<='z')))
                        target_postfix[k++]=ch;
                else if(ch>='0' && ch<='9')
                        target_postfix[k++]=ch;
                else
                {
                }
           }
            i++;
    }
    while(stack_is_empty(ptr_stack)!=1)
    {
        a=stack_peek(ptr_stack);
        stack_pop(ptr_stack);
        target_postfix[k++]=a;
    }
    target_postfix[k]='\0';
    stack_destroy(ptr_stack);
}

