#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *rlink;
    struct Node *llink;
};
struct Node *create(char *postfix)
{
    int i,k=0;
    char sym; //To read each symbol in the expression
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));//Creation of node for each symbol.
    for(i=0;sym=postfix[i]!='\0';i++)
    {
        temp->rlink=NULL;
        temp->llink=NULL;
    }

}