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
    
int main() 
{ 
    struct node *root = newNode(1); 
  
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);  
    
    printf("Height of tree is %d", maxDepth(root)); 
    
    getchar(); 
    return 0; 
} 