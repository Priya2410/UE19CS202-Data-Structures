//Height using recursion
//Idea is to call max(height of left subtree , height of right subtree)
#include<stdio.h> 
#include<stdlib.h> 
struct node  
{ 
    int data; 
    struct node* left; 
    struct node* right; 
};
int maxDepth(struct node* root)  
{ 
   if (root==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = maxDepth(root->left); 
       int rDepth = maxDepth(root->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}

struct node* newNode(int data)  
{ 
    struct node* node = (struct node*) malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
} 
int numberofnodes(struct node *root)
{
    if(root==NULL)
    return 0;
    else
    return 1+numberofnodes(root->left)+numberofnodes(root->right);
}
int numberofleafnodes(struct node *root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;
    else
    return numberofleafnodes(root->left)+numberofleafnodes(root->right);
}
    
int main() 
{ 
    struct node *root = newNode(1); 
  
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);  
    
    printf("Height of tree is %d\n", maxDepth(root)); 
    printf("Number of nodes in a tree is %d\n", numberofnodes(root)); 
    printf("Number of leaf nodes in a tree is %d\n", numberofleafnodes(root));
    getchar(); 
    return 0; 
} 