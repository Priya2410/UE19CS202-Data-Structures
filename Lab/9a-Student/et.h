#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Node
{
 struct Node *right,*left,*prev;
 char data;
} Node;

//Create Binary Expression tree from a string in postfix form  of length len 
Node * createExpressionTree(char* a,int len);


//print the preorder traversal of the Binary Expression Tree
void preorder(Node *);


//print the postorder traversal of the Binary Expression Tree
void postorder(Node *);


//print the inorder traversal of the Binary Expression Tree
void inorder(Node *);


//Frees the space used by the Binary Expression Tree
void freeTree(Node * root);


