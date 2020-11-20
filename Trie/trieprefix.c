#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct trienode
{
	struct trienode *child[255];
	int endofword;
};
int length=0;
char str[100];

struct trienode* getnode()
{
	struct trienode*temp;
	temp=(struct trienode*)malloc(sizeof(struct trienode));
	for(int i=0;i<255;i++)
		temp->child[i]=NULL;
	temp->endofword=0;
	return(temp);
}
void insert(struct trienode* root,char key[10])
{
	struct trienode *cur;
	int i,index;
	cur=root;
	for(i=0;key[i]!='\0';i++)
	{
		index=key[i];
		if(cur->child[index]==NULL)
			cur->child[index]=getnode();
		cur=cur->child[index];
	}
	cur->endofword=1;
}
void display(struct trienode* cur)
{
	int i,j;
	
	
	for(i=0;i<255;i++)
	{
		if(cur->child[i]!=NULL)
		{
			str[length++]=i;
			if(cur->child[i]->endofword==1)
			{
				printf("\n");
				for(int j=0;j<length;j++)
				printf("%c",str[j]);
			}
			display(cur->child[i]);
		}
	}
	length--;
}

void display_prefix(struct trienode *root,char*prefix)
{
	struct trienode*cur;
	cur=root;
	int index;
	for(int i=0;prefix[i]!='\0';i++)
	{
		index=prefix[i];
		if(cur->child[index]!=NULL)
		{
			str[length++]=index;
			cur=cur->child[index];
		}
		
	}
	if(cur->endofword==1)
	{
		for(int j=0;j<length;j++)
			printf("%c",str[j]);
	}
	display(cur);
}
		
int main()
{
	struct trienode*root;
	root=getnode();
	char input[100],prefix[100];
	int choice;
	while(1)
	{
	printf("1.insert 2.delete 3.prefix\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:	printf("enter the input\n");
				scanf("%s",input);
				insert(root,input);
				break;
		case 2: length=0;
				display(root);
				break;
		case 3: length=0;
				printf("enter the prefix\n");
				scanf("%s",prefix);
				display_prefix(root,prefix);
				break;		
		default : exit(0);
	}
	}
	
}
	
	