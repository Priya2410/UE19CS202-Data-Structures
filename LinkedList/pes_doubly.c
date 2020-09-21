#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("insufficient memory\n");
		return(0);
	}
	return(temp);
}
NODE insert_front(NODE first,int ele)
{
	NODE temp;
	temp=getnode();
	temp->data=ele;
	temp->llink=temp->rlink=NULL;
	if(first==NULL)
	{
		return (temp);
	}
	temp->rlink=first;
	first->llink=temp;
	return(temp);
}
void display(NODE first)
{
	NODE cur=first;
	if(first==NULL)
	{
		printf("list is empty");
		return;
	}
	while(cur!=NULL)
	{
		printf("%d\t",cur->data);
		cur=cur->rlink;
	}
}
NODE insert_end(NODE first, int ele)
{
	NODE temp=getnode();
	temp->data=ele;
	temp->rlink=temp->llink=NULL;
	if(first==NULL)
	{
		return temp;
	}
	NODE cur=first;
	while(cur->rlink!=NULL)
	{
		cur=cur->rlink;
	}
	cur->rlink=temp;
	temp->llink=cur;
	return (first);
}
NODE delete_front(NODE first)
{
	NODE cur=NULL;
	if(first==NULL)
	{
		printf("list is empty\n");
		return(NULL);
	}
	if(first->rlink==NULL)
	{
		printf("%d is deleted\n",first->data);
		free(first);
		return(NULL);
	}
	cur=first->rlink;
	cur->llink=NULL;
	printf("%d is deleted\n",first->data);
	free(first);
	return(cur);
}
NODE delete_rear(NODE first)
{
	if(first==NULL)
	{
		printf("list is empty\n");
		return(NULL);
	}
	if(first->rlink==NULL)
	{
		printf("%d is deleted",first->data);
		free(first);
		return(NULL);
	}
	NODE cur=first,prev=NULL;
	while(cur->rlink!=NULL)
	{
		prev=cur;
		cur=cur->rlink;
	}
	printf("%d is deleted\n",cur->data);
	free(cur);
	prev->rlink=NULL;
	return(first);
}
NODE insert_pos(NODE first,int pos,int ele)
{
	NODE temp=getnode();
	temp->data=ele;
	temp->rlink=temp->llink=NULL;
	if(pos<=0)
	{
		printf("invalid position");
	    return;
	}
	if(pos==1)
	{
		temp->rlink=first;
		first->llink=temp;
		return(temp);
	}
	NODE cur=first,prev=NULL;
	for(int i=1;cur->rlink!=NULL&&i<=pos-1;i++)
	{
		 prev=cur;
		 cur=cur->rlink;
	}
	prev->rlink=temp;
	temp->llink=prev;
	temp->rlink=cur;
	cur->llink=temp;
	return(first);
}
		
	
	
	
	




int main(void)
{
 NODE head=NULL;
 int ele,pos;
 for(;;)
 {
 printf("\n 1.Insert at front\n 2.Insert at rear\n 3.Display\n 4. Insert at position\n 5.Delete at front\n 6.Delete at rear end\n 7.Delete at a position\n");
 printf("\n enter your choice\n");
 int ch;
 scanf("%d",&ch);

 switch(ch)
 {
	 case 1:  printf("enter the element");
			  scanf("%d",&ele);
			  head=insert_front(head,ele);
			  break;
	case 2: printf("enter the elements\n");
			scanf("%d",&ele);
			head=insert_end(head,ele);
			break;
			 
	case 3: display(head);
			break;
	case 4: printf("enter the position and element");
	        scanf("%d %d",&pos,&ele);
			head=insert_pos(head,pos,ele);
			break;
	case 5: head=delete_front(head);
			break;
	case 6: head=delete_rear(head);
	        break;
	 
	default:exit(0);
 }
 }
 return(0);
 }
 