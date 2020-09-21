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
// #include <stdio.h>
// #include<stdlib.h>

// /* structure containing a data part and link part */
// struct node
// {
//     int data ;
//     struct node * link ;
// } ;

// void addcirq ( struct node **, struct node **, int ) ;
// int delcirq ( struct node **, struct node ** ) ;
// void cirq_display ( struct node * ) ;

// int main( )
// {
//     struct node *front, *rear ;

//     front = rear = NULL ;

//     addcirq ( &front, &rear, 10 ) ;
//     addcirq ( &front, &rear, 17 ) ;
//     addcirq ( &front, &rear, 18 ) ;
//     addcirq ( &front, &rear, 5 ) ;
//     addcirq ( &front, &rear, 30 ) ;
//     addcirq ( &front, &rear, 15 ) ;

//     printf ("Before deletion:\n") ;
//     cirq_display( front ) ;

//     delcirq ( &front, &rear ) ;
//     delcirq ( &front, &rear ) ;
//     delcirq ( &front, &rear ) ;

//     printf ("\\n\\nAfter deletion:") ;
//     cirq_display( front ) ;
// }

// void addcirq ( struct node **f, struct node **r, int item )
// {
//     struct node *q ;

//     /* create new node */
//     q = malloc ( sizeof ( struct node ) ) ;
//     q -> data = item ;

//     /* if the queue is empty */
//     if ( *f == NULL )
//         *f = q ;
//     else
//         ( *r ) -> link = q ;

//     *r = q ;
//     ( *r ) -> link = *f ;
// }

// /* removes an element from front of queue */
// int delcirq ( struct node **f, struct node **r )
// {
//     struct node *q ;
//     int item ;

//     /* if queue is empty */
//     if ( *f == NULL )
//         printf ("queue is empty") ;
//     else
//     {
//         if ( *f == *r )
//         {
//             item = ( *f ) -> data ;
//             free ( *f ) ;
//             *f = NULL ;
//             *r = NULL ;
//         }
//         else
//         {
//             /* delete the node */
//             q = *f ;
//             item = q -> data ;
//             *f = ( *f ) -> link ;
//             ( *r ) -> link = *f ;
//             free ( q ) ;
//         }
//         return ( item ) ;
//     }
//     return 0;
// }

// /* displays whole of the queue */
// void cirq_display ( struct node *f )
// {
//     struct node *q = f, *p = NULL ;

//     /* traverse the entire linked list */
//     while ( q != p )
//     {
//         printf ("%d ", q -> data) ;

//         q = q -> link ;
//         p = f ;
//     }
// }