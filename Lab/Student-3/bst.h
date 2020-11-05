#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree
{
    Node *root;
} Tree;

void tree_initialize(Tree *tree);
void tree_insert(Tree *tree, int data);
void inorder(Tree *tree);
void preorder(Tree *tree);
void postorder(Tree *tree);
void tree_delete(Tree *tree, int data);
void tree_destroy(Tree *tree);

