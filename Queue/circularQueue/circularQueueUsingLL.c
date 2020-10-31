#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *front=NULL,*rear=NULL;

void enqueue( int ele ,struct Node **front, struct Node ** rear)
{
    struct Node *q;
    q = malloc ( sizeof ( struct Node ) ) ;
    q -> data = ele ;

    /* if the queue is empty */
    if ( *front == NULL )
        *front = q ;
    else
        ( *rear ) -> next = q ;
         *rear= q ;
        ( *rear ) -> next = *front ;
}
int dequeue(struct Node **front,struct Node **rear)
{
    if(*front==NULL)
    {
        return -1;
    }
    else if(*front==*rear)
    {
        int data= (*front)->data;
        *front=*rear=NULL;
        return data;

    }
    else
    {
        struct Node *p=*front;
        int data=p->data;
        *front=(*front)->next;
        free(p);
        return data;
    }
}
void display ( struct Node **front,struct Node **rear)
{
    struct Node *q = *front;
    if(q==NULL)
    {
    printf("The queue is empty\n");
    return;
    }
    while ( q != *rear)
    {
        printf ("%d ", q -> data) ;

        q = q -> next ;
    }
    printf("%d \n",(*rear)->data);
}
int main()
{
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
