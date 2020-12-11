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

// Algorithm 
//As long as the stack has elements we continue the process 
// Before entering the loop we insert the root
//Push right side
//Push left side
// Althought Preorder is root-left-right
// But since we want left to be above right we push right first

void preorder(struct Node *root)
{
    struct Node *s[50];
    int top=-1;
    struct Node *p=root;
    s[++top]=root->data;

    while(top!=-1)
    {
        p=s[top--];
        printf("%d",p->data);
        if(p->rlink!=NULL)
        {
            s[++top]=p->rlink;
        }
        if(p->llink != NULL)
        {
            s[++top]=p->llink;
        }
    }
}

// Algorithm :
// P intially points at root node 
// While p is not null 
// push p on to the stack 
// and move left 
// after it becomes null pop the top of the stack and them move p to right
// This process continues till the stack is empty and p is not null
//Uses explicit stack
void inorder(struct Node *root)
{   
    struct Node *p;
    p=root;
    struct Node *s[50]; // stack
    int top=-1;
    do{
        while(p!=NULL)
        {
            s[++top]=p;
            p=p->llink;
        }
        p=s[top--];
        printf("%d ",p->data);
        p=p->rlink;
    }while(top!=-1 || p!=NULL);

}

void postorder(struct Node *root)
{
    struct Node *s1[50];
    struct Node *s2[50];
    int top1=-1;
    int top2=-1;
    struct Node *p;
    // Push the root node first
    s1[++top1]=root->data;
    while(top1!=-1)
    {
        p=s1[top1--]; //Pop from stack 1
        s2[++top2]=p; // Push to stack 2
        if(p->llink!=NULL)
        {
            s1[++top1]=p->llink;
        }
        if(p->rlink!=NULL)
        {
            s1[++top1]=p->rlink;
        }
    }
    //To print stack contents of stack 2
    while(top2!=NULL)
    {
        p=s2[top2--];
        printf("%d",p->data);
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