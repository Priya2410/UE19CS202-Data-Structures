#include"dll.h"
int count_nodes(List* dll)
{
	int count=1;
	Node *p=dell->next;
	while(p->next!=NULL)
	{
	count++;
	p=p->next;
	}
	return count;
}

void insert_front(List* dll, int data)
{
  	Node *head=dll->head;
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->prev=NULL;
    if(dll->head->next==NULL)
    {
    dll->head=temp;
    dll->number_of_nodes++;
    }
    else
    {
    temp->next=head->next;
    head->prev=temp;
    head=temp;
    dll->number_of_nodes++;
    }
}

void dllist_delete_beginning(List* list)
{
    Node *head=dll->head;
   	if(head->next==NULL)
   	{
   	free(dll->head);
   	dll->number_of_nodes--;
   	}
   	else
   	{
	dll->head=dll->head->next;
	free(head);
	dll->head->prev=NULL;
	dll->number_of_nodes--;
   	}
}


void position_delete(List* dll, int pos)
{
    //TODO
    Node *head=dll->head;
    if(head->next==NULL)
   	{
   	free(dll->head);
   	dll->number_of_nodes--;
   	}
   	else
   	{
   	for(int i=0;i<pos-1;i++)
   	{
   	head=head->next;
   	}
   	head->prev->next=head->next;
   	if(head->next!=NULL)
   	head->next->prev=head->prev;
   	dll->number_of_nodes--;
   	}
}

int search_list(List* dll,int key)
{
	int pos=-1;
    Node *head=dll->head;
    if(head->data==key)
    return 0;
    while(head->next!=NULL)
    {
    pos++;
    if(head->data==key)
    return pos;
    head=head->next;
    }
    
}


void reverse_list(List* dll)
{
    //TODO
   Node *temp=NULL;
 Node *current=dll->head;
 while(current !=NULL){
 temp=current->prev;
 current -> prev= current -> next;
 current -> next= temp;
 current = current -> prev;
}
if(temp!=NULL)
dll->head=temp->prev;
}


