//With tail pointer
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *link;
}*last;
//Creation of Node
struct Node *createNode(int ele)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    if(temp!=NULL)//There is memory allocated
    {
        temp->data=ele;
        temp->link=NULL;
    }
    return temp;
}

//Insertion at front
struct Node *insertatbegin(struct Node *last,int ele)
{
    struct Node *temp=createNode(ele);
    //For empty list
    if(last==NULL)
    {
        last=temp;
        temp->link=last;
    }
    else
    {
        temp->link=last->link;
        last->link=temp;
    }
    return last;
}

//Insertion at end
struct Node *insertatend(struct Node *last,int ele)
{
    struct Node *temp=createNode(ele);
    //For empty list
    if(last==NULL)
    {
        last=temp;
        temp->link=last;
    }
    else
    {
        temp->link=last->link;
        last->link=temp;
        last=temp;
    }
    return last;
}

//Insertion at a position
struct Node *insertatpos(struct Node *last,int ele,int pos)
{
    struct Node *temp=createNode(ele);
    //For pos=0
    if(pos==0)
    {
        last=insertatbegin(last,ele);
    }
    else
    {
        struct Node *p=last->link;
        for(int i=0;i<=pos-1;i++)
        {
            p=p->link;
        }
        temp->link=p->link;
        p->link=temp;
        //If position is for the insert at end
        if(p->link==last)
        {
            last=temp;
        }
    }
    return last;
}

void display(struct Node *last)
{
    struct Node *p=last->link;
    if(last==NULL)
    {
        printf("List is empty\n");
    }
    do
    {
        printf("%d\t",p->data);
        p=p->link;
    }
    while(p!=last->link);
}
//Deletion at front 
struct Node *deleteatfront(struct Node *last)
{
    if(last==NULL)
    {
    printf("List is empty\n");
    return NULL;
    }
    //If there is only one node in the list
    else if(last->link==last)
    {
        free(last);
        printf("Element deleted and list is empty now\n");
        return NULL;
    }
    else
    {
        struct Node *first=last->link;
        last->link=first->link;
        free(first);
    }
    return last;
}

//Deletion at end
struct Node *deleteatend(struct Node *last)
{
    struct Node *p;
    if(last==NULL)
    printf("List is empty\n");
    //If there is only one node in the list
    else if(last->link==last)
    {
        free(last);
        printf("Element deleted and list is empty now\n");
    }
    else
    {
        p=last->link;
        while(p->link!=last)
        {
            p=p->link;
        }
        p->link=last->link;
        free(last);
    }
    return p;
}

//Deletion at position
struct Node *deleteatpos(struct Node *last,int pos)
{
    if(last==NULL)
    printf("List is empty\n");
    //If there is only one node in the list
    else if(pos==0)
    {
        last=deleteatfront(last);
    }
     else if(last->link==last)
    {
        free(last);
        printf("Element deleted and list is empty now\n");
    }
    else
    {
        struct Node *p=last->link;
        struct Node *prev;
        for(int i=0;i<pos-1;i++)
        {
            prev=p;
            p=p->link;
        }
        prev->link=p->link;
        free(p);
    }
    return last;
}

int main()
{
	int choice;
	last=NULL;
    int data,pos;
	while(1)
	{
	printf("\n%s\n","Enter 1 for insertion at beginning");
	printf("%s\n","Enter 2 for insertion at end");
	printf("%s\n","Enter 3 for insertion at a particular position");
	printf("%s\n","Enter 4 for displaying");
	printf("%s\n","Enter 5 for deletion at beginning");
	printf("%s\n","Enter 7 for deletion at end");
	printf("%s\n","Enter 8 for deletion at position");
	printf("%s\n","Enter 9 for exit");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:
	        printf("%s\n","Enter the data\n");
	        scanf("%d",&data);
			last=insertatbegin(last,data);
			break;
			case 2:
	        printf("%s\n","Enter the data\n");
	        scanf("%d",&data);
			last=insertatend(last,data);
			break;
			case 3:
	        printf("%s\n","Enter the data\n");
	        scanf("%d",&data);
            printf("%s\n","Enter the position\n");
	        scanf("%d",&pos);
			last=insertatpos(last,data,pos);
			break;
			case 4:
			display(last);
			break;
			case 5:
			last=deleteatfront(last);
			break;
			case 7:
			last=deleteatend(last);
			break;
			case 8:
            printf("%s\n","Enter the position\n");
	        scanf("%d",&pos);
			last=deleteatpos(last,pos);
			break;
			case 9:
			exit(0);
			break;
			default:
			printf("%s\n","Wrong input");

		}
	}

}
