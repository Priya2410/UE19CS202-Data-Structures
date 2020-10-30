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
void sum(struct Node *p)
{
	int s=0;
	while(p!=NULL)
	{
		s=s+p->data;
		p=p->next;
	}
	printf("%d",s);
}
int main()
{
	int a[]={1,2,3,4,5};
	create(a,5);
	sum(first);
}