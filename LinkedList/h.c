#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int *a,int n)
{
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
} 
void delete_key(int key)
{
    struct Node *prev, *cur;

    /* Check if first node contains key */
    while (first != NULL && first->data == key)
    {
        // Get reference of first node
        prev = first;

        // Adjust first node link
        first = first->next;

        // Delete prev since it contains reference to first node
        free(prev);
    }

    prev = NULL;
    cur  = first;

    /* For each node in the list */
    while (cur != NULL)
    {
        // Current node contains key
        if (cur->data == key)
        {
            // Adjust links for previous node
            if (prev != NULL) 
                prev->next = cur->next;

            // Delete current node
            free(cur);
            return;
            // cur=prev->next;
            // No need to delete further
        } 
        else
        {
        prev = cur;
        cur = cur->next;
        }
    }
}


int main()
{
    int a[]={1,2,2,3,4,5};
    int ele;
    create(a,6);
    printf("%s\n","Enter the element to be searched" );
    scanf("%d",&ele);
    delete_key(ele);
    display(first);
}
