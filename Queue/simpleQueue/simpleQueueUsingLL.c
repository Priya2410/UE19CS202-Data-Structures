#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int data,struct Node **front,struct Node **rear)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if((*front)==NULL)
    {
       (*front)=(*rear)=temp;
    }
    else
    {
        (*rear)->next=temp;
        *rear=temp;
    }
}
int dequeue(struct Node **front,struct Node **rear)
{
    int data=-1;
    if(*front==NULL)
        return data;
    struct Node *p=*front;
    data=(*front)->data;
    *front=(*front)->next;
    free(p);
    return data;
}
void display(struct Node **front,struct Node **rear)
{
    struct Node *p=*front;
    if(*front==NULL)
    {
        printf("The queue is empty\n");
        return;
    }
    else
    {
        while(p!=(*rear)->next) 
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }
    
}
int main()
{
    int choice;
    int data;
    int ele;
    while(1)
    {
        printf("\nEnter 1 for insertion at rear\n");
        printf("Enter 2 for deletion at front\n");
        printf("Enter 3 for display \n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value for the element\n");
                scanf("%d",&ele);
                enqueue(ele,&front,&rear);
                break;
            
            case 2:
                data=dequeue(&front,&rear);
                if(data==-1)
                    printf("The queue is empty\n");
                else
                    printf("The element deleted is:%d\n",data);
                break;
            
            case 3:
                display(&front,&rear);
                break;
            
            case 4:
                exit(0);
        }
    }
}

