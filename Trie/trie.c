//trie implementation
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define alphabet_size 26
#define size(a) sizeof(a)/sizeof(a[0])


int count;
//Structure for Trie it has reference for all alphabets
//and also endofword which marks the end of a particular word
struct trie{
	struct trie *children[alphabet_size];
	bool endofword;
};
//To initalize all the references as NULL and endofword as false
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
	while(*str) //Traverse till you encounter Null
	{
		//Check if the current alphabet has a ref and if it doesnt create one
		//else do to the next alphabet
		if(cur->children[*str-'a']==NULL)
		{
			cur->children[*str-'a']=getnode();
		}
		cur=cur->children[*str-'a'];
		str++;
	}
	cur->endofword=true;
}
//store the word in str till you finish end of word
//when endofword become true print the word
//here level is used for indexing of str
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
struct trie* remov(struct trie *root,char *key,int depth)
{
	if(!root)
		return(NULL);
	if(depth==strlen(key))
	{
		if(root->endofword)
			root->endofword=false;
	    if(root==NULL){
			free(root);
	        root=NULL;
	}
	return(root);
    }
int index=key[depth]-'a';
root->children[index]=remov(root->children[index],key,depth+1);
if(root==NULL &&root->endofword==false)
{
	free(root);
	root=NULL;
}
return(root);
}

//Search if a word is present 

	bool search(struct trie*root,char *key)
{
	if(root==NULL)
		return(false);
	struct trie *cur=root;
	while(*key)
	{
		cur=cur->children[*key-'a'];
		if(cur==NULL) //If the alphabet has no ref node then the word isnt present
			return(false);
		key++;
	}
	return(cur->endofword);
}
	

		
int main()
{
	char keys[][8]={"peter","piper","picked","peck","pickled","pepper"};
	struct trie *root=getnode();
	char str[20];
	int level=0;
	for(int i=0;i<size(keys);i++)
	{
		insert(root,keys[i]);
	}
	printf("contents are");
	
	printf("enter the count\n");
	scanf("%d",&count);
	display(root,str,level);
	/*char key[10];
	printf("enter the key to be searched");
	scanf("%s",&key);
	bool b=search(root,key);
	if(b==false)
		printf("not found");
	else
		printf("found");*/
	/*printf("enter the prefix");
	char prefix[10];
	scanf("%s",prefix);
	display_prefix(root,prefix,str,level);
	//printf("%d",wordcount(root));*/
	printf("enter the word to delet");
	char *word;
	scanf("%s",word);
	root=remov(root,word,0);
	bool b=search(root,"peck");
	if(b==false)
		printf("not found");
	else
		printf("found");
	
}