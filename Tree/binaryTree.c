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
struct Node *search(int ele,struct Node *root)
{
    if(root==NULL)
        return root;
    else if(root->data==ele)
        return root;
    else
    {
        if(ele<root->data)
            return search(ele,root->llink);
        else
        {
           return  search(ele,root->rlink);
        }
    }
}
void preorder(struct Node *root)
{
    if(root==NULL)
        return;
    else
    {
        printf("%d ",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
    
}
int main()
{
    int choice;
    struct Node *root=NULL,*cur;
    int ele;
    while(1)
    {
        printf("\nEnter 1 for insertion\n");
        printf("Enter 2 for search\n");
        printf("Enter 3 to display in preorder\n");
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
            printf("Enter element\n");
            scanf("%d",&ele);
            cur=search(ele,root);
            if(cur!=NULL)
                printf("Element found!\n");
            else
            {
                printf("Element not found!\n");
            }
            
            break;

            case 3:
            preorder(root);
            break;

            case 4:
            exit(0);
            break;
            default:printf("Wrong Choice\n");
        }
    }
}