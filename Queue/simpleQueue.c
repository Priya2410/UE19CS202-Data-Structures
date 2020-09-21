#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void insertAtRear(int ele,int *r,int *q)
{
    if(*r==SIZE-1)
    {
        printf("The queue is full\n");
        return;
    }
    else
    {
        *r=*r+1;
        q[*r]=ele;
    }
}

int deleteAtFront(int *f,int *r,int *q)
{
    if(*f>*r)
    {
        return -1;
    }
    else
    {
        return q[(*f)++];
    }
}
void display(int *f,int *r,int *q)
{
    if(*f>*r)
    {
        printf("The queue is empty");
        return;
    }
    else
    {
        for(int i=0;i<=*r;i++)
        {
            printf("%d ",q[i]);
        }
    }
}
int main()
{
    int choice;
    int q[SIZE];
    int r,f;
    r=-1;
    f=0;
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
                insertAtRear(ele,&r,q);
                break;
            
            case 2:
                data=deleteAtFront(&f,&r,q);
                if(data==-1)
                    printf("The queue is empty\n");
                else
                    printf("The element deleted is:%d\n",data);
                break;
            
            case 3:
                display(&f,&r,q);
                break;
            
            case 4:
                exit(0);
        }
    }
}