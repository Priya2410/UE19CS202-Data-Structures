#include<stdio.h>
#include<stdlib.h>
#define max 5
void enqueue(int ele,int *front,int *rear,int *q)
{
    if((*rear+1)%max==(*front))
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        if((*rear)==-1 && (*front)==-1)
        {
            *front=*rear=0;

        }
        else
        {
            *rear=((*rear+1)%max);
        }
          q[*rear]=ele;
    }
    

}
int dequeue(int *front,int *rear,int *q)
{
    int data;
    if((*front==-1)||(*rear==1))
    {
        return -1;
    }
    else
    {
        if((*front)==(*rear))
        {
            data=q[*front];
            *front=*rear=-1;
        }
        else
        {
            data=q[*front];
            *front=((*front+1)%max);
        }
        
    }
    return data;  
}
void display(int *front,int *rear,int *q)
{
    if((*front==-1)||(*rear==1))
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        for(int i=*front;i!=*rear;i++)
        {
            printf("%d ",q[i]);
        }
        printf("%d\n",q[*rear]);
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