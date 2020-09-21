
#include<stdio.h>
#include<stdlib.h>
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
void maximum(struct Node *p)
{
	int max=p->data;
	while(p!=NULL)
	{
		if(p->data>=max)
		{
			max=p->data;
		}
		p=p->next;
	}
	printf("%d",max);
}
int main()
{
	int a[]={3,40,5,6};
	create(a,4);
	maximum(first);
}