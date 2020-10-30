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
	if(p==NULL)
		printf("%s\n","No elements present");
}

void delete_allnodes()
{
	struct Node *p=first;
	while(p!=NULL)
	{
		first=first->next;
		free(p);
		p=first;
	}
}

int main()
{
	int a[]={1,2,2,3,4,5};
	int ele;
	create(a,6);
	delete_allnodes();
	display(first);
}