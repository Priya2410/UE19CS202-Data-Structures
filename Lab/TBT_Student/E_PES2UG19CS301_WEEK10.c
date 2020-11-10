#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
    Node *new=(Node *)malloc(sizeof(Node));
        new->data=data;
        new->left=NULL;
        new->right=NULL;
        new->leftThread=1;
        new->rightThread=1;
    //If root node is empty then directly insert the root
    Node *temp=tree->root;
    if(temp==NULL)
    {
        tree->root=new;
        return;
    }
    while(1)
    {
        if(data < temp->data)
        {
            if(temp->leftThread == 0)
            {
                temp=temp->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(temp->rightThread == 0)
            {
                temp=temp->right;
            }
            else
            {
                break;
            }
        }
    }
        if(data < temp->data)
        {
            new->left = temp->left;
            new->right = temp;
            temp->leftThread =0;
            temp->left = new;
        }
        else
        {
            new->right = temp->right;
            new->left= temp;
            temp->rightThread=0;
            temp->right=new;
        }
}

Node *inorder_predecessor(Node *ptr)
{

   if(ptr==NULL)
   return NULL;
   if(ptr->leftThread==1)
   {
       ptr=ptr->left;
   }
   else
   {
       ptr=ptr->left;
       while(ptr->right!=NULL && ptr->rightThread==0)
       {
           ptr=ptr->right;
       }
   }
   return ptr;
}

Node *inorder_successor(Node *ptr)
{

      if(ptr==NULL)
   return NULL;
   if(ptr->rightThread==1)
   {
       ptr=ptr->right;
   }
   else
   {
       ptr=ptr->right;
       while(ptr->left!=NULL && ptr->leftThread==0)
       {
           ptr=ptr->left;
       }
   }
   return ptr;
}

void print_ascending(Tree *tree)
{
    Node *temp= tree->root;
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    while(temp->leftThread == 0)
    {
        temp=temp->left;
    }
    while(temp!=NULL)
    {
        printfun(temp->data);
        temp = inorder_successor(temp);
    }
    nextline();
    // TODO : Use printf() specified in tbtmain.c. Dont use printf statement
}

void print_descending(Tree *tree)
{
    Node * temp=tree->root;
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    while(temp->rightThread == 0)
    {
        temp=temp->right;
    }
    while(temp !=NULL)
    {
        printfun(temp->data);
        temp=inorder_predecessor(temp);
    }
    nextline();
// TODO : Use printf() specified in tbtmain.c. Dont use printf statement  
}

void destroy(Node *r)
{
    if(r==NULL)
    return;
    if(r->rightThread == 1 && r->leftThread==0)
    {
        free(r);
        return;
    }
    if(r->leftThread !=1)
    destroy(r->left);
    if(r->rightThread != 1)
    destroy(r->right);
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}
