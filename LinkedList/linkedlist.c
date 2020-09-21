#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *link;
};

struct Node *first=NULL;

void insertat_front()
{
	int ele;
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	if(temp==NULL)
		printf("%s","No memory");
	printf("%s\n","Enter the element" );
	scanf("%d",&ele);
	temp->data=ele;
	temp->link=first;
	first=temp;
}

void insertat_end()
{
	int ele;
	struct Node *p=first;
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	if(temp==NULL)
		printf("%s","No memory");
	printf("%s\n","Enter the element" );
	scanf("%d",&ele);
	temp->data=ele;
	temp->link=NULL;
	if(p==NULL)
	{
		p=temp;
	}
	else 
	{
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}

void insert_atpos()
{

	struct Node *p=first;
	int ele,pos;
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	if(temp==NULL)
		printf("%s","No memory");
	printf("%s\n","Enter the element" );
	scanf("%d",&ele);
	printf("%s\n","Enter the position" );
	scanf("%d",&pos);
	for(int i=0;i<pos-1;i++)
		p=p->link;
	temp->data=ele;
	temp->link=p->link;
	p->link=temp;
}

void display()
{
	struct Node *p=first;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->link;
	}
}

void deleteat_front()
{
	if(first==NULL)
		printf("%s\n","The list is empty");
	else
	{
		struct Node *p=first;
		first=first->link;
		free(p);
	}
}

void deleteat_end()
{
	struct Node *p;
	if(first==NULL)
		printf("%s\n","The list is empty");
	else if(first->link==NULL)
	{
		p=first;
		first=first->link;
		free(p);
	}
	else
	{
		p=first;
		struct Node *temp=NULL;
		while(p->link!=NULL)
		{
			temp=p;
			p=p->link;
		}
		temp->link=NULL;
		free(p);
	}
}

void deleteat_pos()
{
	int pos;
	struct Node *p;
	printf("%s\n","Enter the position:");
	scanf("%d",&pos);
	if(pos==1)
	{
		p=first;
		first=first->link;
		free(p);
	}
	else
	{
		p=first;
		struct Node *q=NULL;
		for(int i=0;i<pos-1;i++)
		{
			q=p;
			p=p->link;
		}
		q->link=p->link;
		free(p);
	}
}

int main()
{
	int choice;
	int ele;
	while(1)
	{
	// printf("\n%s\n","1.Create node" );		
	printf("\n%s\n","1.Insert node at the beginning" );
	printf("%s\n","2.Insert node at a position" );
	printf("%s\n","3.Insert node at the end" );
	printf("%s\n","4.Display Node" );
	printf("%s\n","5.Delete at front" );
	printf("%s\n","6.Delete at end" );
	printf("%s\n","7.Delete at position" );
	printf("%s\n","8.Exit" );
	printf("%s\n","Enter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
	
		case 1:
		insertat_front();
		break;

		case 2:
		insert_atpos();
		break;

		case 3:
		insertat_end();
		break;

		case 4:
		display();
		break;

		case 5:
		deleteat_front();
		break;

		case 6:
		deleteat_end();
		break;

		case 7:
		deleteat_pos();
		break;

		case 8:
		exit(0);

		default:
        printf("n Wrong Choice:n");
        break;

	}
}
}


