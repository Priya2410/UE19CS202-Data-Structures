#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Node {
    int data;
    struct Node *next;
};
void push(struct Node **top,int data)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=(*top);
    (*top)=temp;
}
void pop(struct Node **top)
{
    if((*top)==NULL)
    {
    printf("Stack is empty\n");
    }
    else
    {
    struct Node *p=(*top);
    int data=p->data;
    printf("Element popped is %d\n",data);
    (*top)=(*top)->next;
    free(p);
    }
}
void display(struct Node **top)
{
    if((*top)==NULL)
    printf("Stack is empty\n");
    else
    {
        while((*top)!=NULL)
        {
            printf("%d ",(*top)->data);
            (*top)=(*top)->next;
        }
    }
}
int main()
{
    int choice;
    int data;
    struct Node *root=NULL;
    while(1)
    {
        printf("\nEnter 1 for Push\n");
        printf("Enter 2 for Pop\n");
        printf("Enter 3 for Display\n");
        printf("Enter 4 for Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the data\n");
            scanf("%d",&data);
            push(&root,data);
            break;
            case 2:
            pop(&root);
            break;
            case 3:
            display(&root);
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Wrong Choice");
        }
    }
}