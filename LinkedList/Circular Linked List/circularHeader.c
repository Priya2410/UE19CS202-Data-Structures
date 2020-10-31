//When the header points to itself the list is empty
#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *link;
}*head;
typedef struct Node* NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(NODE));
    if(x==NULL)
    {
        printf("Insufficient Memory\n");
    }
    return x;
}
NODE insert_front(int ele,NODE head)
{
    NODE temp;
    temp=getnode();
    temp->data=ele;
    NODE first=head->link;//Holds the address of the first node
    head->link=temp;
    temp->link=first;
    return head;

}
NODE insert_rear(int ele,NODE head)
{
    NODE temp;
    temp=getnode();
    temp->data=ele;
    NODE first=head->link;
    while(first->link!=head)
    {
        first=first->link;
    }
    first->link=temp;
    temp->link=head;
    return head;
}
NODE delete_front(NODE head)
{
    NODE first=head->link;
    if(head->link==head)
    {
        printf("List is empty\n");
        return NULL;
    }
    else if(first->link==head)
    {
        free(first);
        printf("List is empty element deleted\n");
        return NULL;
    }
    else
    {
        head->link=first->link;
        free(first);
        return head;

    }

}
NODE delete_rear(NODE head)
{
    NODE last;
    NODE first=head->link;
    if(head->link==head)
    {
        printf("List is empty\n");
        return NULL;
    }
    else if(first->link==head)
    {
        free(first);
        printf("List is empty element deleted\n");
        return NULL;
    }
    else
    {
        while(first->link!=head)
        {
            last=first;
            first=first->link;
        }
        last->link=head;
        free(first);
    }
    return head;
}
void display(NODE head)
{
    if(head->link==head)
    {
        printf("List is empty\n");
    }
    else
    {
        NODE first=head->link;//Address of first node
        while(first!=head)
        {
            printf("%d\t",first->data);
            first=first->link;
        }

    }
}
int main(void)
{
 head=getnode();
 NODE first;
 first=NULL;
 head->link=head;
 int ele,posistion;
 for(;;)
 {
 printf("\n 1.Insert at front\n 2.Display\n 3.insert at rear\n 4.deletion at front\n 5.deleteion at rear\n");
 printf("\n enter your choice\n");
 int ch;
 scanf("%d",&ch);

 switch(ch)
 {
	 case 1: printf("enter the element\n");
			scanf("%d",&ele);
			first=insert_front(ele,head);
			break;
	case 2:printf("enter the element\n");
			scanf("%d",&ele);
			first=insert_rear(ele,head);
			break;
	case 3: display(first);
			break;
	case 4: first=delete_front(head);
			break;
	case 5:first=delete_rear(head);
			break;
    case 6:exit(0);
 }
 }
 return(0);
 }