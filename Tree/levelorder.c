#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

struct node* queue[100];
int front=-1,rear=-1;
void enqueue(struct node* root)
{
     if(root==NULL)
         return;
    else
    {
        if(front==-1)
        {
            front++;
            rear++;
            queue[front]=root;
            return;
        }
        rear++;
        queue[rear]=root;
    }
}

struct node* dequeue()
{
     struct node* temp;
    if(front==-1)
        return NULL;
   
   else
   {
       temp=queue[front];
       if(front==rear)
       {
           front=rear=-1;
       }
       else
       {
           front++;
       }
           
   }
    return temp;
}
int empty()
{
    if(front==-1)
        return 1;
    else
        return 0;
}
void levelOrder(struct node * root) {
       
        
        enqueue(root);
        struct node* temp;
        while(empty()==0)
        {
            temp=dequeue();
            if(temp!=NULL)
            {
                enqueue(temp->left);
                enqueue(temp->right);
                printf("%d ",temp->data);
            }
        }
    }

