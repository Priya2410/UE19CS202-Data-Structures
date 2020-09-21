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
void check_sorted(struct Node *p)
{
	int x=-32767;
	int count=0;
	while(p!=NULL)
	{
		if(p->data<x)
		{
			count=1;
			break;
		}
		else
		{
			x=p->data;
			p=p->next;
		}
	}
	if(count==1)
		printf("%s\n","The list isnt sorted" );
	else
		printf("%s\n","The list is sorted" );
}
int main()
{
	int a[]={1,2,3,4,5};
	create(a,5);
	check_sorted(first);
}