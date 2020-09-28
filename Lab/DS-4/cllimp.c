#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
    //TODO
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    if((pos>cll->length)|| (pos<0))
    {
        cll->length--;
    }
    else if(cll->head==NULL)
    {
        cll->head=cll->tail=temp;
        temp->next=temp;
    }
    else if(pos==0)
    {
        temp->next=cll->head;
        cll->head=temp;
        cll->tail->next=temp;
    }
    else if(pos==cll->length)
    {
        cll->tail->next=temp;
        temp->next=cll->head;
        cll->tail=temp;
    }
    else
    {
        Node *p=cll->head;
        int count=1;
        while(pos>count++)
            p=p->next;
        temp->next=p->next;
        p->next=temp;
    }
    cll->length++;
    
}

void position_delete(List* cll, int pos)
{
//TODO
    if((pos<0) || (pos>=cll->length) || (cll->length==0))
        return;
    else if( (pos==0) && (cll->length==1))
    {
        Node *p=cll->head;
        free(p);
        cll->head=cll->tail=NULL;
        cll->length--;
    }
    else if(pos==0)
    {
        Node *p=cll->head;
        cll->head=cll->head->next;
        free(p);
        cll->tail->next=cll->head;
        cll->length--;
    }
    else if(pos==cll->length-1)
    {
        Node *p=cll->head;
        while(p->next!=cll->tail)
        {
            p=p->next;
        }
        Node *q=p->next;
        p->next=cll->head;
        free(q);
        cll->tail=p;
        cll->length--;
    }
    else
    {   
        Node *p=cll->head;
        int count=1;
        while(pos>count++)
            p=p->next;
        Node *q=p->next;
        free(q);
        p->next=cll->head;
        cll->tail=p;
        cll->length--;
    }
    
}

int josephus(List* cll, int k)
{
//TODO
    Node *del=NULL;
   //Check for k's value
   if(k<0 || k>=cll->length ||cll->length==0){}
   else
   { 
       Node *p=cll->head;
       if(k==0)
       { 
           del=cll->head;
       } //If k=0 then we just return the data present there-because there is only one surviver
       else
       { 
           //This is for iterating till we get the next node to be deleted
           for(int i=0;i<k;i++)
           {
               p=p->next;
           }
           del=p; //del points to the previous node of the node to be deleted 
       }
       while(del!=NULL)
       {
           //We have to check if del==null 
           while(cll->length>1)
           {
               //we have to keep deleting till we reach one node left
           Node *del1=del->next;
           del->next=del->next->next;
           free(del1);
           cll->length--;
           del=del->next;
           }
           cll->tail=cll->head=del;
           return del->data; //To return the winner
       }
   }
   return 0;
}


