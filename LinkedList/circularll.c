#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*last;

struct Node *addToEmpty(struct Node *last,int data) 
{ 
    last = (struct Node*)malloc(sizeof(struct Node));  
    last -> data = data; 
    last -> next = last; 
    return last; 
} 
struct Node* insertatbegin(struct Node *last)
{
	int data;
	printf("%s\n","Enter the data");
	scanf("%d",&data);
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	if (last == NULL) 
     return addToEmpty(last,data);
	else
	{
		temp->next=last->next;
		last->next=temp;
		return last;
	}

}
struct Node* insertatend(struct Node *last)
{
	int data;
	printf("%s\n","Enter the data");
	scanf("%d",&data);
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	if (last == NULL) 
     return addToEmpty(last,data);
	else
	{
	
		temp->next=last->next;
		last->next=temp;
		last=temp;
		return last;
	}
}

struct Node* insertatpos(struct Node *last)
{
	int data;int pos;
	printf("%s\n","Enter the data");
	scanf("%d",&data);
	printf("%s\n","Enter the position");
	scanf("%d",&pos);
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	if (last == NULL) 
     return addToEmpty(last,data);
	else if(pos==0)
	{
		temp->next=last->next;
		last->next=temp;
		return last;
	}
	else
	{
		struct Node *p=last->next;
		for(int i=0;i<pos-1;i++)
		{
			p=p->next;
		}
		temp->next=p->next;
		p->next=temp;
		if(p->next==last)
			last=temp;
		return last;
	}
}
struct Node *deleteatbegin(struct Node *last)
{
	if(last==NULL)
		printf("%s\n","List is empty" );
	else if(last->next==last)
	{
		free(last);
	}
	else
	{
		struct Node *p=last->next;
		last->next=p->next;
		free(p);
		return last;
	}
}
struct Node *deleteatend(struct Node *last)
{
	if(last==NULL)
		printf("%s\n","List is empty" );
	else if(last->next==last)
	{
		free(last);
		printf("%s\n","List is empty after deletion");
	}
	else
	{
		struct Node *p=last->next;
		while(p->next!=last)
		{
			p=p->next;
		}
		p->next=last->next;
		free(last);
		return p;
	}
}
struct Node *deleteatpos(struct Node *last)
{
	int pos;
	printf("%s\n","Enter the position");
	scanf("%d",&pos);
	if(last==NULL)
		printf("%s\n","List is empty" );
	if(pos==1)
	{
		struct Node *p=last->next;
		last->next=p->next;
		free(p);
		return last;
	}
	else
	{
		struct Node *q,*p=last->next;
		for(int i=0;i<pos-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		free(p);
		return last;
	}

}
void display(struct Node *last)
{
	if(last==NULL)
		printf("%s\n","List is empty");
	struct Node *p=last->next;
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}
	while(p!=last->next);
}
int main()
{
	int choice;
	last=NULL;
	while(1)
	{
	printf("\n%s\n","Enter 1 for insertion at beginning");
	printf("%s\n","Enter 2 for insertion at end");
	printf("%s\n","Enter 3 for insertion at a particular position");
	printf("%s\n","Enter 4 for displaying");
	printf("%s\n","Enter 5 for deletion at beginning");
	printf("%s\n","Enter 7 for deletion at end");
	printf("%s\n","Enter 8 for deletion at position");
	printf("%s\n","Enter 9 for exit");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			last=insertatbegin(last);
			break;
			case 2:
			last=insertatend(last);
			break;
			case 3:
			last=insertatpos(last);
			break;
			case 4:
			display(last);
			break;
			case 5:
			last=deleteatbegin(last);
			break;
			case 7:
			last=deleteatend(last);
			break;
			case 8:
			last=deleteatpos(last);
			break;
			case 9:
			exit(0);
			break;
			default:
			printf("%s\n","Wrong input");

		}
	}

}