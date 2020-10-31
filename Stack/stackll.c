#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *push(struct Node *top,int data)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=top;
    top=temp;
    return top;
}
struct Node *pop(struct Node *top)
{
    if(top==NULL)
    {
    printf("Stack is empty\n");
    return top;
    }
    struct Node *p=top;
    int data=p->data;
    printf("Element popped is %d\n",data);
    top=top->next;
    free(p);
    return top;
}
void display(struct Node *top)
{
    if(top==NULL)
    printf("Stack is empty\n");
    else
    {
        while(top!=NULL)
        {
            printf("%d ",top->data);
            top=top->next;
        }
    }
}
void peek(struct Node *top)
{
    if(top==NULL)
    {printf("STack is empty\n");
    return ;}
    else
        printf("%d",(top)->data);
}
int main()
{
    int choice;
    int data;
    struct Node *top=NULL;
    while(1)
    {
        printf("\nEnter 1 for Push\n");
        printf("Enter 2 for Pop\n");
        printf("Enter 3 for Display\n");
        printf("Enter 4 for Peek\n");
        printf("Enter 5 for Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the data\n");
            scanf("%d",&data);
            top=push(top,data);
            break;
            case 2:
            top=pop(top);
            break;
            case 3:
            display(top);
            break;
            case 4:
            peek(top);
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Wrong Choice");
        }
    }
}