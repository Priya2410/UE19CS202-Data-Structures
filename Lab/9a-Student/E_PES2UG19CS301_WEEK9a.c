#include "et.h"

Node * createExpressionTree(char* a,int len)
{
    char sym;
    Node * st[len];
    int k=-1;//k is top of stack
    //here 'a' is a postfix expression and len is the length of postfix expression
    for(int i=0;i<len;i++)
    {
      Node *temp=(Node *)malloc(sizeof(Node));
      sym=a[i];
      temp->data=sym;
      temp->right=NULL;
      temp->left=NULL;
      temp->prev=NULL;
      if(sym== '+' || sym== '-' || sym=='*' || sym=='/' || sym=='%' || sym=='^')
      {
        temp->right=st[k--];
        temp->left=st[k--];
        st[++k]=temp;
      }
      else
      {
        st[++k]=temp;
      }
    }
    return st[k--]; //return top of the stack
}


void inorder(Node *root)
{
  if(root==NULL)
  return;
  else
  {
  inorder(root->left);
  printf("%c",root->data); 
  inorder(root->right);
  }
}

void preorder(Node *root)
{
  if(root==NULL)
  return;
  else
  {
  printf("%c",root->data);   
  preorder(root->left);
  preorder(root->right);
  }
}

void postorder(Node *root)
{
  if(root==NULL)
  return;
  else
  {
  postorder(root->left);
  postorder(root->right);
  printf("%c",root->data); 
  }
}

void freeTree(Node *root)
{
  if(root==NULL)
  return;
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

