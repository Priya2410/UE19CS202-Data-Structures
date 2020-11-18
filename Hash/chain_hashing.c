#include<stdio.h>
#include<stdlib.h>
#define hash_size 5
struct node
{
	int info;
	struct node *link;
};
typedef struct node*NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("insufficient memory in heap\n");
		exit(0);
	}
	return(temp);
}
NODE insert_rear(int ele,NODE first)
{
	NODE temp;
	NODE cur;
	temp=getnode();
	temp->info=ele;
	temp->link=NULL;
	if(first==NULL)
		return(temp);
	cur=first;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;
	return(first);
}
void insert_hash_table(int ele,NODE a[])
{
	int hashvalue;
	hashvalue=ele%hash_size;
	a[hashvalue]=insert_rear(ele,a[hashvalue]);
}
int search(int key,NODE a[])
{
	int hashvalue;
	NODE cur;
	hashvalue=key%hash_size;
	if(a[hashvalue]==NULL)
	{
		return(0);
	}
	cur=a[hashvalue];
	while(cur!=NULL)
	{
		if(key==cur->info)
			return(1);
		cur=cur->link;
	}
	return(0);
}
void display(NODE a[])
{
	NODE temp;
	int i;
	for(i=0;i<hash_size;i++)
	{
		printf("a[%d]=",i);
		temp=a[i];
		if(temp==NULL)
			printf("NULL");
		else
		{
			while( temp->link!=NULL)
			{
				printf("%d------->",temp->info);
				temp=temp->link;
			}
			printf("%d\n",temp->info);
		}
	}
}
void main()
{
	NODE a[10];
	int ele,key,choice,flag,i;
	for(i=0;i<hash_size;i++)
		a[i]=NULL;
	while(1)
	{
		printf("1.insert\n 2.search 3.display\n 4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the ele\n");
					scanf("%d",&ele);
					insert_hash_table(ele,a);
					break;
			case 2:printf("enter the key to be searched\n");
					scanf("%d",&key);
					flag=search(key,a);
					if(flag)
					{
						printf("found");
					}
					else
						printf("not found\n");
					break;
			case 3: printf("Contents of table\n");
					display(a);
					break;
			default:exit(0);
		}
	}
}
					

