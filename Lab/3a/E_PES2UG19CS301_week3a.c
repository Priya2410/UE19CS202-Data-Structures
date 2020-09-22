#include "poly.h"
#include<math.h>
void insert_at_end(List *list, int data) 
{
	//TODO
    Node *head=list->head;
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->link=NULL;
    if(list->head==NULL)
    {
        list->head=temp;
        list->number_of_nodes++;
    }
    else
    {
        Node *p=list->head;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
        list->number_of_nodes++;
    }
    
}

long long int evaluate(List *list, int x)
{
    //TODO
    Node *head=list->head;
    long long sum=0;
    int i=0;
    while(head!=NULL)
    {
        sum=sum+(head->data)*pow(x,i);
        i++;
        head=head->link;
    }
    return sum;
}
