#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data)
{
	Node *temp=(Node *)malloc(sizeof(Node));
	temp->data=data;
	temp->link=NULL;
	if(list->head==NULL)
	{
		list->head=temp;
		list->number_of_nodes+=1;
	}
	else
	{
		Node *p=list->head;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
		list->number_of_nodes+=1;
	}
}

void list_delete_front(List* list) {
	
	if(list->head!=NULL)
	{
		Node *p=list->head;
		list->head=list->head->link;
		free(p);
		list->number_of_nodes-=1;
	}

}

void list_insert_at (List *list, int data, int position)
{
	Node *temp=(Node *)malloc(sizeof(Node));
	temp->data=data;
	if(position<0 || position>list->number_of_nodes+1)
		return;
	else if(position==0)
		{
			
			temp->link=list->head;
			list->head=temp;
			list->number_of_nodes+=1;
		}
	else
		{
			Node *p=list->head;
			for(int i=0;i<position-1;i++)
			{
				p=p->link;
			}
			temp->link=p->link;
			p->link=temp;
			list->number_of_nodes+=1;
		}
}

void list_reverse(List* list)
{
 	struct Node *prev,*next=NULL;
	struct Node *curr=list->head;
	while(curr!=NULL)
	{
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	list->head=prev;
}


