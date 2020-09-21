
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
int maximum(struct Node *p)
{
	int max=-32767;
	int x=0;
	if(p==NULL)
		return max;
	else
	{
		x=maximum(p->next);
		return x>p->data?x:p->data;
	}
}
int main()
{
	int a[]={3,40,5,6};
	create(a,4);
	int max=maximum(first);
	printf("%d",max);
}