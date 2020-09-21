#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *prev,*next;
}*first=NULL;

void create(int *a,int n)
{
	struct Node *t,*last;
	first=(struct Node *)malloc(sizeof(struct Node));
	int i;

	first->data=a[0];
	first->prev=NULL; //Because its the first node.
	first->next=NULL;
	last=first;

	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=a[i];
		t->prev=last;
		t->next=last->next;
		last=t;
	}
}

void display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d\n", p->data);
		p=p->next;
	}
}

int main()
{
	int a[]={2,3,1,4,5};
	create(a,5);
	display(first);
}