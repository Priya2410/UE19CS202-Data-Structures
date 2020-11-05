#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
    //TODO 
    tree=(Tree*)malloc(sizeof(Tree));
    tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
// TODO : Insert element to create a BST
  Node *temp=(Node *)malloc(sizeof(Node));
  Node *r=tree->root;
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
  if(tree->root==NULL)
  {
    tree->root=temp;
    return;
  }
  else
  {
    Node *cur=tree->root,*prev=NULL;
    while(cur!=NULL)
    {
      prev=cur;
      if(data<cur->data)
      {
        cur=cur->left;
      }
      else if(data>cur->data)
      {
        cur=cur->right;
      }
      else if(data==cur->data)
      {
				free(temp);
				return;
      }
    }
    if(data<prev->data)
    {
      prev->left=temp;
    }
    else
    {
      prev->right=temp;
    }
  }
}
void tree_delete(Tree *tree, int element)
{
   // TODO : Delete elements from BST  
  Node *cur,*parent,*q,*succ;
  q=NULL;
  if(tree->root==NULL)
  {
    return;
  }
 parent=NULL;
  cur=tree->root;
  while(cur!=NULL)
  {
    if(element==cur->data)
    break;
    parent=cur;
    if(element<cur->data)
    cur=cur->left;
    else
    cur=cur->right;
  }
  if(cur==NULL)
  {
    return;
  }
  else if(cur->left==NULL)
  q=cur->right;
  else if(cur->right==NULL)
  q=cur->left;
  else
  {
    succ=cur->right;
    while(succ->left!=NULL)
    {
      succ=succ->left;
    }
    succ->left=cur->left;
    q=cur->right;
  }
  if(parent==NULL)
  {
  tree->root=q;
  }
  else if(cur==parent->left)
  {
    parent->left=q;
  }
  else
  {
    parent->right=q;
  }
  free(cur);
}


void tree_inorder(Node *r)
{
 	//TODO :  use printf to print inorder 
   if(r==NULL)
   return ;
   else{
     tree_inorder(r->left);
     printf("%d ",r->data);
     tree_inorder(r->right);
   }
}

void tree_preorder(Node *r)
{
    //TODO :  use printf to print preorder
  if(r==NULL)
      return ;
   else
   {
     printf("%d ",r->data);
     tree_preorder(r->left);
     tree_preorder(r->right);
   }
}

void tree_postorder(Node *r)
{
    //TODO :  use printf to print postorder
    if(r==NULL)
      return ;
   else
   {
     tree_postorder(r->left);
     tree_postorder(r->right);
     printf("%d ",r->data);
   }
}

void postorder(Tree *t)
{
   //TODO
  tree_postorder(t->root);
}

void preorder(Tree *t)
{
     //TODO
   tree_preorder(t->root);
}

void inorder(Tree *t)
{
  //TODO 
  tree_inorder(t->root);
}

void destroy(Node *r)
{
  //TODO 
  if(r==NULL)
  return;
  destroy(r->left) ;
  destroy(r->right) ;
}

void tree_destroy(Tree *t)
{ 
//TODO    
destroy(t->root);
free(t);
}
