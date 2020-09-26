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
    struct Node *cur=root;
    if(root==NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    int s[20];int top=-1;
    for(;;)
    {
        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            s[++top]=cur->data;//adding the cur to the stack
            cur=cur->llink;
        }
        if(top!=-1)
        {
            cur->data=s[top--];
            cur=cur->rlink;
        }
        else
        {
            return;
        }
        
    }
    
}
void inorder(struct Node *root)
{   
    struct Node *cur=root;
    if(root==NULL)
        {
            printf("The tree is empty\n");
        }
    int s[20];int top=-1;
    for(;;)
    {
        while(cur!=NULL)
        {
            s[++top]=cur->data;//adding the cur to the stack
            cur=cur->llink;
        }
        if(top!=-1)
        {
            cur->data=s[top--];//pop the element
            printf("%d ",cur->data);
            cur=cur->rlink;
        }
        else
        {
            return;
        }
        
    }
}
void postorder(struct Node *root)
{
    if(root==NULL)
        {
            printf("The tree is empty\n");
        }
    int s[20];int top=-1;
    struct Node *cur=root;
    for(;;)
    {
        while(cur!=NULL)
        {
            s[++top]=cur->data;//adding the cur to the stack
            cur=cur->llink;
        }
        if(top!=-1)
        {
            cur->data=s[top--];//pop the element
            cur=cur->rlink;
            printf("%d ",cur->data);
        }
        else
        {
            return;
        }
        
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
        printf("Enter 4 to display in inorder\n");
        printf("Enter 5 to display in postorder\n");
        printf("Enter 6 to exit\n");
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
            inorder(root);
            break;

            case 5:
            postorder(root);
            break;

            case 6:
            exit(0);
            break;
            default:printf("Wrong Choice\n");
        }
    }
}