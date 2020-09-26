#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("insufficient memory\n");
		return(NULL);
	}
	return(temp);
}

NODE insert(int ele, NODE root)
{
	NODE temp,cur,prev;
	temp=getnode();
	temp->data=ele;
	temp->rlink=temp->llink=NULL;
	if(root==NULL)
	{
		return temp;
	}
	prev=NULL;
	cur=root;
	while(cur!=NULL)
	{
		prev=cur;
		if(ele==cur->data)
		{
			printf("duplicate elements are not allowed\n");
			free(temp);
			return(root);
		}
		if(ele<cur->data)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if(ele<prev->data)
		prev->llink=temp;
	else
		prev->rlink=temp;
	return(root);
}

NODE search(int ele,NODE root)
{
	NODE cur;
	if(root==NULL)
		return NULL;
	cur=root;
	while(cur!=NULL)
	{
		if(ele==cur->data)
		{
			return(cur);
		}
		if(ele<cur->data)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	return(NULL);
}

/* recursive function for search*/
/*NODE search(int ele,NODE root)
{
	if(root==NULL)
		return root;
	if(ele==root->data)
		return root;
	if(ele<root->data)
		return(search(ele,root->llink));
	return(search(ele,root->rlink));
}*/

 /*void preorder (NODE root)
 {
	 if(root==NULL)
	 {
		 return;
	 }
	 printf("%d\t",root->data);
	 preorder(root->llink);
	 preorder(root->rlink);
 }*/
void postorder(NODE root)
{
		if(root==NULL)
		{
			return;
		}
		postorder(root->llink);
		postorder(root->rlink);
		printf("%d\t",root->data);
}
void inorder(NODE root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->llink);
	printf("%d\t",root->data);
	inorder(root->rlink);
}
void preorder(NODE root)
{
	NODE cur,s[20];
	int top=-1;
	if(root==NULL)
	{
		printf("tree is empty");
		return;
	}
	cur=root;
	for(;;)
	{
		while(cur!=NULL)
		{
			printf("%d\t",cur->data);
			s[++top]=cur;
			cur=cur->llink;
		}
		if(top!=-1)
		{
			cur=s[top--];
			cur=cur->rlink;
		}
		else{
			return;
		}
	}
}
NODE Maximum(NODE root)
{
	NODE cur;
	if(root==NULL)
		return root;
	cur=root;
	while(cur->rlink!=NULL)
	{
		cur=cur->rlink;
	}
	return(cur);
	
}

NODE delete(int ele,NODE root)
{
	NODE cur,parent,succ,q;
	if(root==NULL)
	{
		printf("tree is empty");
		return(NULL);
	}
	parent=NULL;
	cur=root;
	while(cur!=NULL)
	{
		if(ele==cur->data)
			break;
		parent=cur;
		if(ele<cur->data)
		cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if(cur==NULL)
	{
		printf("element no found\n");
		return(root);
	}
	if(cur->llink==NULL)
		q=cur->rlink;
	else if(cur->rlink==NULL)
		q=cur->llink;
	else{
		succ=cur->rlink;
		while(succ->llink!=NULL)
		{
			succ=succ->llink;
		}
		succ->llink=cur->llink;
		q=cur->rlink;
	}
	if(parent==NULL)
		return(q);
	if(cur==parent->llink)
		parent->llink=q;
	else
		parent->rlink=q;
	free(cur);
	return(root);
}
	
		

			
	
		
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
int main()
{
	NODE root=NULL,cur,maxi;
	int choice,ele;
	for(;;)
	{
		printf("1.insert \n 2. search\n 3.postorder\n 4.preorder\n 5.inorder\n 6. maximum\n 7.delete\n");
		printf("enter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the element\n");
			        scanf("%d",&ele);
					root=insert(ele,root);
					break;
			case 2: printf("enter the element to be searched\n");
					scanf("%d",&ele);
					cur=search(ele,root);
					if(cur==NULL)
					{
						printf("%d is not found\n",cur->data);
					}
					else
						printf("%d is found \n",cur->data);
					break;
			case 3:postorder(root);
					break;
			case 4:preorder(root);
					break;
			case 5: inorder(root);
					break;
			case 6:  maxi=Maximum(root);
					printf("maximum element=%d\n",maxi->data);
					break;
			case 7: printf("enter the node to be deleted\n");
					scanf("%d",&ele);
					root=delete(ele,root);
					break;
		
			default: exit(0);
		}
	}
}