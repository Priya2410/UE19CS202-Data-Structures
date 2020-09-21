#include<stdio.h>
#include<stdlib.h>
#define max 5
void enqueue(int ele,int *front,int *rear,int *q)
{
    if((*front==0 && *rear==max-1)||((*rear)+1==*front))
    {
        printf("Queue is empty\n");
        return;
    }
    else 
    {
        if((*rear)==-1)
        {
            *rear=0;
            *front=0;
        }
        else if((*rear)==max-1)
        {
            *rear=0;
        }
        else
        {
            *rear=(*rear)+1;
        }
        q[*rear]=ele;
        
    }

}
int dequeue(int *front,int *rear,int *q)
{
    int data;
    if((*front==-1)||(*rear==-1))
    {
        return -1;
    }
    else
    {
        if((*front)==max-1)
        {
            data=q[*front];
            *front=(*front)+1;
        }
        else if((*front)==(*rear))
        {
            data=q[*front];
            *front=*rear=-1;
        }
        else
        {
            data=q[*front];
            *front=*front+1;
        }
        
    }
    return data;  
}
void display(int *front,int *rear,int *q)
{
    int i;
    if (*front > *rear)
    {
        for (i = *front; i < max; i++)
        {
            printf("%d ", q[i]);
        }
        for (i = 0; i <= *rear; i++)
            printf("%d ", q[i]);
    }
    else
    {
        for (i = *front; i <= *rear; i++)
            printf("%d ", q[i]);
    }
}
int main()
{
    int q[max];
    int front=-1;
    int rear=-1;
    int choice;
    int ele;int data;
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
                enqueue(ele,&front,&rear,q);
                break;
            
            case 2:
                data=dequeue(&front,&rear,q);
                if(data==-1)
                    printf("The queue is empty\n");
                else
                    printf("The element deleted is:%d\n",data);
                break;
            
            case 3:
                display(&front,&rear,q);
                break;
            
            case 4:
                exit(0);
        }
    }

}