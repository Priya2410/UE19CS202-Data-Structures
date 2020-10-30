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

void display()
{
	struct Node *p=first;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

void deleteat_pos(int pos)
{
	struct Node *p;
	if(pos==1)
	{
		p=first;
		first=first->next;
		free(p);
	}
	else
	{
		p=first;
		struct Node *q=NULL;
		for(int i=0;i<pos-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		free(p);
	}
}

void search(int key,struct Node *p)
{
	int i=1;
	while(p!=NULL)
	{
		if(p->data==key)
			break;
		else
		{
			p=p->next;
			i++;
		}
	}
	if(p!=NULL)
	{
	deleteat_pos(i);
	display();
	}
	else
	{	
		printf("%s\n","Element not found!");
		display();
	}

}
int main()
{
	int a[]={1,2,3,4,5};int ele;
	create(a,5);
	printf("%s\n","Enter the element to be searched" );
	scanf("%d",&ele);
	search(ele,first);
}