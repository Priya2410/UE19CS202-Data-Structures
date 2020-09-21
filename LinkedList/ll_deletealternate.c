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
void delete_alternate()
{
	struct Node *prev=first;
	struct Node *p=first->next;
	while(p!=NULL && prev!=NULL)
	{
		prev->next=p->next;
		free(p);
		prev=prev->next;
		p=prev->next;
	}
}
int main()
{
	int a[]={1,2,2,3,4,5};
	int ele;
	create(a,6);
	delete_alternate();
	display(first);
}
