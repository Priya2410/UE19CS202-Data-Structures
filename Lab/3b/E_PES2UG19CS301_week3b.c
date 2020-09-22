#include"dll.h"
int count_nodes(List* dll)
{
	//TODO
    int count=0;
    Node *head=dll->head;
    while(head!=NULL)
    {
        count=count+1;
        head=head->next;
    }
    return count;
}

void insert_front(List* dll, int data)
{
    //TODO
    Node *head=dll->head;
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
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
    //TODO
    Node *head=list->head;
    if(head==NULL)
        return;
    else if(head->next==NULL)
    {
        list->head=list->head->next;
        free(head);
        list->number_of_nodes--;
    }
    else
    {
        list->head=list->head->next;
        list->head->prev=NULL;
        free(head);
        list->number_of_nodes--;
    }
}


void position_delete(List* dll, int pos)
{
    //TODO
    Node *head=dll->head;
    if(head==NULL)
        return;
    else if(pos>dll->number_of_nodes)
        return;
    else if(pos==0)
    {
        dll->head=dll->head->next;
        free(head);
        dll->number_of_nodes--;
    }
    else
    {
        Node *p=dll->head;
        for(int i=0;i<pos-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next!=NULL)
            p->next->prev=p->prev;
        dll->number_of_nodes--;
    }
}

int search_list(List* dll,int key)
{
    //TODO
    Node *head=dll->head;
    int pos=-1;
    int i=0;
    while(head!=NULL)
    {
        if(head->data==key)
            {
                pos=i;
                return pos;
            }
        head=head->next;
        i++;
    }
    return -1;
}


void reverse_list(List* dll)
{
    //TODO
    Node *temp=NULL;
    Node *current=dll->head;
    while(current!=NULL)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if(temp!=NULL)
    {
        dll->head=temp->prev;
    }
}


