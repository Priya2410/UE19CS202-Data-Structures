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
int display(struct Node *p)
{
	if(p==NULL)
		return 0;
	else
		return p->data+display(p->next);
}
int main()
{
	int a[]={3,4,5,6};
	create(a,4);
	int sum=display(first);
	printf("%d",sum);
}