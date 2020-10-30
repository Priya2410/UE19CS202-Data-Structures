#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*head;
struct Node *addEmpty(struct Node* head,int data)
{
	head=(struct Node *)malloc(sizeof(struct Node));
	head->data=data;
	head->next=head;
	return head;
}
struct Node *insertatbegin(struct Node *head)
{
	int data;
	printf("%s\n","Enter the data");
	scanf("%d",&data);
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	if(head==NULL)
		return addEmpty(head,data);
	else
	{
		temp->next=head;
		struct Node *p=head;
		while(p->next!=head)
			p=p->next;
		p->next=temp;
		head=temp;
		return head;
	}

}
struct Node *insertatpos(struct Node *head)
{
	int data;int pos;
	printf("%s\n","Enter the data");
	scanf("%d",&data);
	printf("%s\n","Enter the position");
	scanf("%d",&pos);
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	if(head==NULL)
		return addEmpty(head,data);
	else
	{
		if(pos==0)
		{
			temp->next=head;
			struct Node *p=head;
			while(p->next!=head)
				p=p->next;
			p->next=temp;
			head=temp;
			return head;
		}
		else
		{
			struct Node *p=head;
			for(int i=0;i<pos-1;i++)
			{
				p=p->next;
			}
			temp->next=p->next;
			p->next=temp;
			return head;
		}
	}
}
struct Node *insertatend(struct Node *head)
{
	int data;
	printf("%s\n","Enter the data");
	scanf("%d",&data);
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	if(head==NULL)
		return addEmpty(head,data);
	else
	{
		struct Node *p=head;
		while(p->next!=head)
			p=p->next;
		p->next=temp;
		temp->next=head;
		return head;
	}
}
void display(struct Node *head)
{
	if(head==NULL)
		printf("%s\n","list is empty");
	struct Node *p=head;
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}
	while(p!=head);
}
struct Node *deleteatbegin(struct Node *head)
{
	struct Node *p=head;
	if(head->next==head)
	{
	head=NULL;
	free(p);
	return head;
	}
	while(p->next!=head)
		p=p->next;
	p->next=head->next;
	free(head);
	head=p->next;
	return head;
}
struct Node *deleteatend(struct Node *head)
{
	struct Node *p=head->next,*q;
	while(p->next!=head)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	free(p);
	return head;

}
struct Node *deleteatpos(struct Node *head)
{
	int pos;
	//Position is 1,2,3...
	printf("%s\n","Enter the position");
	scanf("%d",&pos);
	struct Node *p=head;
	struct Node *q;
	if(head->next==head)
	{
        free(head);
        printf("List is empty and element is deleted\n");
    	return NULL;
	}
    else
    {
	for(int i=0;i<=pos-1;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	free(p);
    }
	return head;
}

int main()
{
	int choice;
	head=NULL;
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
			head=insertatbegin(head);
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
			head=deleteatbegin(head);
			break;
			case 7:
			head=deleteatend(head);
			break;
			case 8:
			head=deleteatpos(head);
			break;
			case 9:
			exit(0);
			break;
			default:
			printf("%s\n","Wrong input");

		}
	}

}