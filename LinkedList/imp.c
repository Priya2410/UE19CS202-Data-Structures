#include"dll.h"
int count_nodes(List* dll)
{
	int count=1;
	Node *p=dll->head;
  if(p==NULL)
    return 0;
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
    temp->next=NULL;
    if(head==NULL)
    {
    dll->head=temp;
    dll->number_of_nodes++;
    }
    else
    {
    temp->next=head;
    head->prev=temp;
    dll->head=temp;
    dll->number_of_nodes++;
    }
}

void dllist_delete_beginning(List* list)
{
    Node *head=list->head;
    if(head==NULL)
    {
      return ;
    }
   	if(head->next==NULL)
   	{
   	free(list->head);
   	list->number_of_nodes--;
   	}
   	else
   	{
	list->head=list->head->next;
	free(head);
	list->head->prev=NULL;
	list->number_of_nodes--;
   	}
}


void position_delete(List* dll, int pos)
{
    //TODO
    Node *head=dll->head;
    if(head==NULL)
      return;
    if(pos>dll->number_of_nodes)
      return;
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
    Node *head=dll->head;
    int flag=-1;
    int pos=-1;
    while(head!=NULL)
    {
    pos++;
    if(head->data==key)
    {
    flag=pos;
    }
    head=head->next;
    }
    if(flag>-1)
      return flag;
    else 
      return -1;
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
