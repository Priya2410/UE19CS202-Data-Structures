#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE;
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

NODE create(char *postfix)
{
	NODE temp,st[20];
	int i,k=0;
	char symb;
	for(i=0;(symb=postfix[i])!='\0';i++)
	{
		temp=getnode();
		temp->data=symb;
		temp->rlink=temp->llink=NULL;
	
	if(isalnum(symb))
	{
		st[k++]=temp;
	}
	else
	{
		         temp->rlink=st[--k];
				 temp->llink=st[--k];
				 st[k++]=temp;
	}
	}
	return(st[--k]);
}
float eval(NODE root)
{
	int num;
	switch(root->data)
	{
		case '+': return(eval(root->llink)+eval(root->rlink));
		case '-': return(eval(root->llink)-eval(root->rlink));
		case '*': return(eval(root->llink)*eval(root->rlink));
		case '/': return(eval(root->llink)/eval(root->rlink));
		case '$':
		case '^': return(pow(eval(root->llink),eval(root->rlink)));		
		default : if(isalpha(root->data))
		          {
					  printf("%c=",root->data);
					  scanf("%d",&num);
					  return(num);
				  }
				  else{
					  return(root->data-'0');
				  }
	}
}
			
int main()
{
		char postfix[20];
		float res;
		NODE root=NULL;
		printf("enter the postfix expression\n");
		scanf("%s",postfix);
		root=create(postfix);
		res=eval(root);
		printf("%f\n",res);
}

	
	
		