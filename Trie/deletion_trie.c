//trie implementation
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define alphabet_size 26

int count;
struct trie{
	struct trie *children[alphabet_size];
	bool endofword;
};
struct trie* getnode()
{
	struct trie *temp=NULL;
	temp=(struct trie *)malloc(sizeof(struct trie));
	if(temp)
	{
		temp->endofword=false;
		for(int i=0;i<alphabet_size;i++)
		{
			temp->children[i]=NULL;
		}
	}
	return(temp);
}
void insert(struct trie *head,char *str)
{
	struct trie *cur=head;
	while(*str)
	{
		if(cur->children[*str-'a']==NULL)
		{
			cur->children[*str-'a']=getnode();
		}
		cur=cur->children[*str-'a'];
		str++;
	}
	cur->endofword=true;
}
void display(struct trie* root,char str[],int level)
{
	if(root->endofword!=false&&level==count)
	{
		str[level]='\0';
		printf("%s\n",str);
	}
	for(int i=0;i<alphabet_size;i++)
	{
		if(root->children[i])
		{
			str[level]=i+'a';
			display(root->children[i],str,level+1);
		}
	}
}
bool search(struct trie*root,char *key)
{
	if(root==NULL)
		return(false);
	struct trie *cur=root;
	while(*key)
	{
		cur=cur->children[*key-'a'];
		if(cur==NULL)
			return(false);
		key++;
	}
	return(cur->endofword);
}
bool isempty(struct trie *root)
{
	for(int i=0;i<alphabet_size;i++)
	{
		if(root->children[i])
			return(false);
	}
	return(true);
}
struct trie *delete(struct trie*root,char *key,int depth)
{
	if(!root)
	{
		return(NULL);
	}
	if(depth==strlen(key))
	{
		if(root->endofword)
			root->endofword=false;
		if(isempty(root))
		{
			free(root);
			root=NULL;
		}
	return(root);
	}
	int index=key[depth]-'a';
	root->children[index]=delete(root->children[index],key,depth+1);
	if(isempty(root)&&root->endofword==false)
	{
		free(root);
		root=NULL;
	}
	return(root);
}
			
		

			
		
int main()
{
	char keys[][8]={"peter","piper","picked","peck","pickled","pepper","act","actor","active"};
	struct trie *root=getnode();
	char str[20];
	int level=0;
	char key[10];
	int choice;
	int depth=0;
	bool b;
	for(int i=0;i<9;i++)
	{
		insert(root,keys[i]);
	}
	while(1)
	{
		printf("1.Delete 2.search 3.Display\n");
		printf("Enter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("enter the key to be deleted\n");
					scanf("%s",key);
					delete(root,key,depth);
					break;
			case 2:	printf("enter the key to be searched\n");
					scanf("%s",key);
					b=search(root,key);
					if(b==true)
						printf("found");
					else
						printf("not found");
					break;
			case 3: printf("enter the count\n");
			        scanf("%d",&count);
			        display(root,str,level);
			          break;
			default: exit(0);
		}
	}
}
	
	