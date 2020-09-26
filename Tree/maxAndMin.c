#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *rlink;
    struct Node *llink;
};
struct Node *insert(int ele,struct Node *root)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    struct Node *cur,*prev;
    temp->data=ele;
    temp->rlink=temp->llink=NULL;
    if(root==NULL)
    {
        root=temp;
        return root;
    }
    else
    {
        cur=root;
        while(cur!=NULL)
        {
            prev=cur;
            if(ele<cur->data)
                cur=cur->llink;
            else
                cur=cur->rlink;
        }
        if(ele<prev->data)
            prev->llink=temp;
        else
            prev->rlink=temp;
        return root;
    }
}


int main()
{
    int choice;
    struct Node *root=NULL,*max,*min;
    int ele;
    while(1)
    {
        printf("\nEnter 1 for insertion\n");
        printf("Enter 2 to display the max element\n");
        printf("Enter 3 to display the min element\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter element\n");
            scanf("%d",&ele);
            root=insert(ele,root);
            break;

            case 2:
            max=maximum(root);
            printf("%d is the maximum element\n",max->data);
            break;

            case 3:
            min=minimum(root);
            printf("%d is the maximum element\n",max->data);
            break;

            case 4:
            exit(0);
            break;
            default:printf("Wrong Choice\n");
        }
    }
}