#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node * link;
};
typedef struct Node* NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct Node));
	if(x==NULL)
	{
		printf("insufficient memory");
		return(0);
	}
	return(x);
}
NODE insert_front(int ele,NODE tail)
{
	NODE temp;
	temp=getnode();
	temp->data=ele;
	temp->link=NULL;
	if(tail==NULL)
	{
		tail=temp;
	}
	else
	{
		temp->link=tail->link;
	}
	tail->link=temp;
	return(tail);
}

void display(NODE tail)
{
	NODE cur;
	if(tail==NULL)
	{
		printf("list is empty");
		return;
	}
	cur=tail->link;
	while(cur!=tail)
	{
		printf("%d\t",cur->data);
		cur=cur->link;
	}
	printf("%d\t",cur->data);
}
NODE insert_rear(int ele,NODE tail)
{
	NODE temp;
	temp=getnode();
	temp->data=ele;
	temp->link=NULL;
	if(tail==NULL)
	{
		tail=temp;
	}
	else{
		temp->link=tail->link;
	}
	tail->link=temp;
	return(temp);
}

NODE delete_front(NODE tail)
{
	NODE first;
	if(tail==NULL)
	{
		printf("list is empty");
		return(NULL);
	}
	if(tail->link==tail)
	{
		printf("%d is deleted", tail->data);
		free(tail);
		return(NULL);
	}
	first=tail->link;
	tail->link=first->link;
	printf("%d is deleted",first->data);
	free(first);
	return(tail);
}
	
NODE delete_rear(NODE tail)
{
	NODE first;
	if(tail==NULL)
	{
		printf("list is empty");
		return(NULL);
	}
	if(tail->link==tail)
	{
		printf("%d is deleted",tail->data);
		free(tail);
		return(NULL);
	}
	first=tail->link;
	while(first->link!=tail)
	{
		first=first->link;
	}
	first->link=tail->link;
	printf("%d is deleted",tail->data);
	free(tail);
	return(first);
}