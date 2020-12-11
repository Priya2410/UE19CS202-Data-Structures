#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
	Node *temp,*prev,*cur;
	temp=create_node(data);
	cur=cll->head;
	if(pos==0&&cur==NULL)
	{
		cll->length++;
		cll->head=temp;
		cll->tail=temp;
	}
	else if(pos==0)
	{
		cll->length++;
		temp->next=cur;
		cll->head=temp;
	}
	else 
	{	if(((cll->length)<pos)||pos<0)
		{
		}
		else
		{
			for(int i=0;i<pos;i++)
			{
				prev=cur;
				cur=cur->next;
			}
			cll->length++;
			if(cur==NULL)
			{
				prev->next=temp;
				cll->tail=temp;
			}
			else
			{
				temp->next=cur;
				prev->next=temp;
			}
		}
	}
	
}

void position_delete(List* cll, int pos)
{
	Node *temp,*prev,*cur;
	cur=cll->head;
	if(((cll->length)<=pos)||pos<0)
	{
			
	}
	else if(pos==0)
	{
		
        if(cur->next==NULL)
        {
            cll->head=cll->tail=NULL;
            free(cur);
        }
        else
        {
            cll->head=cur->next;
            free(cur);
        }  
		cll->length--;
	}
	else
	{
		cll->length--;
		for(int i=0;i<pos;i++)
		{
			prev=cur;
			cur=cur->next;
		}
		if(cur->next==NULL)
		{
			free(cur);
			prev->next=NULL;
			cll->tail=prev;
		}
		else
		{
			prev->next=cur->next;
			free(cur);
		}
		
	}
	
}

int josephus(List* cll, int k)
{
	Node *temp,*prev,*cur;
	prev=NULL;
	cur=cll->head;
	if(((cll->length)<=k)||k<0||cll->head==NULL)
	{
		
	}
	else
	{
		for(int i=0;i<=k;i++)
		{
			prev=cur;
			cur=cur->next;
		}
		while(cll->length!=1)
		{
			if (prev->next==NULL)
			{
				cll->length--;
				cur=cll->head;
				cll->head=cur->next;
				free(cur);
				prev=cll->head;
				cur=prev->next;
			}
			
			else if(cur->next==NULL)
			{
				cll->length--;
				cll->tail=prev;
				prev->next=NULL;
				free(cur);
				prev=cll->head;
				cur=prev->next;
			}
			else
			{
				cll->length--;
				prev->next=cur->next;
				temp=cur->next;
				free(cur);
				prev=temp;
				cur=prev->next;
			}
		}
	
	}
	return(prev->data);
}
