#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *prev,*next;
}*head=NULL;

struct Node *insertatfront(struct Node *head)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	int data;
	printf("%s\n","Enter the data");
	scanf("%d",&data);
	if(head==NULL)
	{
		temp->data=data;
		temp->prev=temp->next=temp;
		head=temp;
		return head;
	}
	else
	{
		temp->data=data;
		struct Node *p=head;
		while(p->next!=head)
		{
			p=p->next;
		}
		temp->next=head;
		head->prev=temp;
		temp->prev=p;
		p->next=temp;
		head=temp;
		return head;
	}
}
struct Node *insertatend(struct Node *head)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	int data;
	printf("%s\n","Enter the data");
	scanf("%d",&data);
	if(head==NULL)
	{
		temp->data=data;
		temp->prev=temp->next=temp;
		head=temp;
		return head;
	}
	else
	{
		temp->data=data;
		struct Node *p=head;
		while(p->next!=head)
		{
			p=p->next;
		}
		temp->next=head;
		head->prev=temp;
		temp->prev=p;
		p->next=temp;
		return head;
	}
}
struct Node *insertatpos(struct Node *head)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	int data;
	printf("%s\n","Enter the data");
	scanf("%d",&data);
	int pos;
	printf("%s\n","Enter the position");
	scanf("%d",&pos);
	struct Node *p=head;
	for(int i=0;i<pos-1;i++)
	{
		p=p->next;
	}
	temp->data=data;
	temp->next=p->next;
	temp->prev=p;
	p->next->prev=temp;
	p->next=temp;
	return head;
}
void display(struct Node* head)
{
	struct Node *p=head;
	if(head==NULL)
	{
		printf("%s\n","List is empty");
		return;
	}
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}
	while(p!=head);
}
struct Node *deleteatfront(struct Node *head)
{
	if(head==NULL)
	{
		printf("%s\n","The list is empty" );
		return NULL;
	}
	if(head->next==head)
	{
		free(head);
		printf("%s\n","Node is deleted and now the list is empty" );
		return NULL;
	}
	struct Node *p=head;
	struct Node *q=head->next;
	while(q->next!=head)
		q=q->next;
	head=head->next;
	free(p);
	head->prev=q;
	q->next=head;
	return head;
}
struct Node *deleteatend(struct Node *head)
{
	if(head==NULL)
	{
		printf("%s\n","The list is empty" );
		return NULL;
	}
	if(head->next==head)
	{
		free(head);
		printf("%s\n","Node is deleted and now the list is empty" );
		return head;
	}
	
		struct Node *p=head->prev;
		struct Node *q=p->prev;
		q->next=head;
		head->prev=q;
		free(p);
		return head;
}
struct Node *deleteatpos(struct Node *head)
{
	int pos;
	printf("%s\n","Enter the position");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("%s\n","The list is empty" );
		return NULL;
	}
	if(pos==0)
	{
		free(head);
		printf("%s\n","Node is deleted and now the list is empty" );
		return head;
	}
	struct Node *p=head->next;
	for(int i=0;i<pos-1;i++)
	{
		p=p->next;
	}
	p->prev->next=p->next;
	p->next->prev=p->prev;
	return head;
}


int main()
{
	int choice;
	while(1)
	{
		printf("\n%s\n","Enter 1 for insertion at front");
		printf("\n%s\n","Enter 2 for insertion at end");
		printf("\n%s\n","Enter 3 for insertion at position");
		printf("\n%s\n","Enter 4 for displaying the list");
		printf("\n%s\n","Enter 5 for deletion at front");
		printf("\n%s\n","Enter 6 for deletion at end");
		printf("\n%s\n","Enter 7 for deletion at pos");
		printf("\n%s\n","Enter 8 for exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			head=insertatfront(head);
			break;
			case 2:
			head=insertatend(head);
			break;
			case 3:
			head=insertatpos(head);
			break;
			case 4:
			display(head);
			break;
			case 5:
			head=deleteatfront(head);
			break;
			case 6:
			head=deleteatend(head);
			break;
			case 7:
			head=deleteatpos(head);
			break;
			case 8:
			exit(0);
			break;
			default:
			printf("%s\n","Wrong Choice");
		}
	}

}