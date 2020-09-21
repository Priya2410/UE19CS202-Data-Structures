#include<stdlib.h>
#include<stdio.h>
struct Node{
	int data;
	struct Node *next;
}*first=NULL;

void create(int *a,int n)
{
	struct Node *t,*last;
	first=(struct Node*)malloc(sizeof(struct Node));
	first->data=a[0];
	first->next=NULL;
	last=first;
	for(int i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}
void display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
void duplicate(struct Node *p)
{
	struct Node *q=p->next;
	while(q!=NULL)
	{
	if((p->data) != (q->data))
	{
		p=q;
		q=q->next;
	}
	else
	{
		p->next=q->next;
		free(q);
		q=p->next;
	}
	}
	display(first);
}

int main()
{
	int a[]={1,2,2,2,3,4,5};
	create(a,7);
	duplicate(first);
}