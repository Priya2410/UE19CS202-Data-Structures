#include<stdio.h>
struct Node{
	int data;
	struct Node *next;
}*first=NULL;
void create(int *a,int n)
{
	struct Node *t,*last;
	struct Node *first=(struct Node*)malloc(sizeof(struct Node));
	first->data=a[0];
	fist->next=NULL;
	last=first;
	for(int i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node))
		t->data=a[i];
		t->next=NULL;
		last->next=t;
	}

}
void display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
int main()
{
	int a[]={3,4,5,6};
	create(A,4);
	display(first);
}