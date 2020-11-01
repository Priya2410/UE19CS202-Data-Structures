#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *rlink;
    struct Node *llink;
    int rthread;
};

typedef struct tree
{
    struct Node *root;
}TREE;

//To initalize root
void init(TREE *ptr)
{
    ptr->root=NULL;
}
struct Node* getnode()
{
	struct Node* temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	printf("enter the value\n");
	scanf("%d",&temp->data);
	temp->rlink=temp->llink=NULL;
	temp->rthread=1;
	return(temp);
}

void setleft(struct Node *q,struct Node *temp)
{
    if(q==NULL)
    return;
    if(q->llink!=NULL)
    return;
    else
    {
        q->llink=temp;
        temp->rlink=q;
    }
}

void setright(struct Node *p,struct Node *temp)
{
    if(p==NULL)
    return;
    if(!(p->rthread))
    return;
    else
    {
        temp->rlink=p->rlink;
        p->rlink=temp;
        p->rthread=0;
    }
}
void create(TREE* ptr)
{
    struct Node *temp,*q,*p;
    int choice;
    ptr->root=getnode();
    do
    {
        temp=getnode();
        while(p!=NULL)
        {
            q=p;
            if(temp->data < p->data)
            p=p->llink;
            else
            {
                if(temp->rthread)
                break;
                p=p->rlink;
            }
        }
        if(p==NULL)
        setleft(q,temp);
        else
        setright(p,temp);
        printf("Do you want to continue1/0\n");
			scanf("%d",&choice);
    }while(choice);

}

void inorder(TREE *ptr)
{
	struct Node *p,*q;
	p=ptr->root;
	do
    {
		q=NULL;
		//To find the left most node
		while(p!=NULL)
		{
			q=p;
			p=p->llink;
		}
		
		if(q!=NULL)
		{
			printf("%d\t",q->data);
			p=q->rlink;
		}
		while(q->rthread && p!=NULL)
		{
			printf("%d\t",p->data);
			q=p;
			p=p->rlink;
		}
	}while(q!=NULL);
}

int main()
{
	TREE t;
	create(&t);
	inorder(&t);
	return(0);
}