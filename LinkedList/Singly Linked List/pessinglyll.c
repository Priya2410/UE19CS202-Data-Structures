#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node * link;
};

struct Node* getnode()
{
	struct Node  *x;
	x=(struct Node *)malloc(sizeof(struct Node));
	if(x==NULL)
	{
		printf("insufficient memory");
		return(0);
	}
	return(x);
}
struct Node* insert_at_front(struct Node* head,int ele)
{
	struct Node *temp;
	temp=getnode();
	temp->data=ele;
	temp->link=head;
	return(temp);
}
struct Node* insert_at_rear(struct Node* head,int ele)
{
	struct Node *temp=NULL;
	temp=getnode();
	temp->data=ele;
	temp->link=NULL;
	struct Node *cur=head;
	if(head==NULL)
	{
		return(temp);
	}
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;
	return(head);
}
	
	
void display(struct Node *head)
{
	struct Node *cur=head;
	while(cur!=NULL)
	{
		printf("\t%d\t",cur->data);
		cur=cur->link;
	}
}

	
struct Node* insert_at_position(struct Node *head,int ele,int pos)
{
	struct Node *temp=getnode();
	temp->data=ele;
	temp->link=NULL;
	struct Node* first=head;
	if(pos==1)
	{
		temp->link=head;
		return(temp);
	}
	struct Node *cur=first;
	struct Node *prev=NULL;
	for(int i=1;i<=pos-1;i++)
	{
		prev=cur;
		cur=cur->link;
	}
	prev->link=temp;
	temp->link=cur;
	return(head);
}
struct Node *delete_at_front(struct Node *head)
{
	if(head==NULL)
	{
		printf("no elements in the list\n");
		return(NULL);
	}
	else
	{
		struct Node *temp;
		temp=head->link;
		printf("%d is deleted",head->data);
		free(head);
		return(temp);
	}
}
struct Node* delete_rear(struct Node *first)
{
	struct Node* cur=NULL,prev=NULL;
	if(first==NULL)
	{
		printf("list is empty\n");
		return(NULL);
	}
	if(first->link==NULL)
	{
		printf(" node deleted is=%d",first->data);
		free(first);
		return(NULL);
	}
	cur=first;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	printf("%d is deleted",cur->data);
	free(cur);
	prev->link=NULL;
	return(first);
}
struct Node* delete_at_position(struct Node* head,int pos)
{
	struct Node *cur=head,prev=NULL;
	if(cur==NULL)
	{
		printf("list is empty");
		return(NULL);
	}
	if(pos==1)
	{
		printf("%d is deleted\n",head->data);
		head=cur->link;
		free(cur);
		return(head);
	}
	else{
		for(int i=1;cur!=NULL&&i<=pos-1;i++)
		{
			prev=cur;
			cur=cur->link;
		}
		prev->link=cur->link;
		printf("%d is deleted\n",cur->data);
		free(cur);
		return(head);
	}
}

	
	
int main(void)
{
  struct Node *first=NULL;
 int ele,posistion;
 for(;;)
 {
 printf("\n 1.Insert at front\n 2.Insert at rear\n 3.Display\n 4. Insert at position\n 5.Delete at front\n 6.Delete at rear end\n 7.Delete at a position\n");
 printf("\n enter your choice\n");
 int ch;
 scanf("%d",&ch);

 switch(ch)
 {
	 case 1: printf("\n enter the element\n");
			 scanf("%d",&ele);
			 first=insert_at_front(first,ele);
			 break;
	case 2: printf("\n enter the element\n");
			scanf("%d",&ele);
			first=insert_at_rear(first,ele);
			break;
	 case 3: display(first);
			break;
	 case 4:printf("\n enter the element\n");
			scanf("%d",&ele);
			printf("enter the position");
			scanf("%d",&posistion);
			first=insert_at_position(first,ele,posistion);
			break;
			
	case 5: first=delete_at_front(first);
			break;
	case 6:
			first=delete_rear(first);
			break; 
	case 7:	
			printf("enter the position");
			scanf("%d",&posistion);
			first=delete_at_position(first,posistion);
			break;
			
	default:exit(0);
 }
 }
 return(0);
 }