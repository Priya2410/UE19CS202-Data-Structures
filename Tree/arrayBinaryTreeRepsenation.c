#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
void insert(int ele,int *a)
{
	int i=0;
	while(i<MAX_SIZE&&a[i]!=0)
	{
		if(ele<a[i])
			i=2*i+1;
		else
			i=2*i+2;
	}
	a[i]=ele;
}
void inorder(int a[],int i)
{
	if(a[i]==0)
		return;
	inorder(a,2*i+1);
	printf("%d\t",a[i]);
	inorder(a,2*i+2);
}
void preorder(int a[],int i)
{
	if(a[i]==0)
		return;
	printf("%d\t",a[i]);
	preorder(a,2*i+1);
	preorder(a,2*i+2);
}
void postorder(int a[],int i)
{
	if(a[i]==0)
		return;
	postorder(a,2*i+1);
	postorder(a,2*i+2);
	printf("%d\t",a[i]);
}

int main()
{
	int a[MAX_SIZE];
	int ele,choice;
	for(int i=0;i<MAX_SIZE;i++)
		a[i]=0;
	for(;;)
	{
		printf("1.insert\n 2.Inorder\n 3. postorder 4. preorder\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the element\n");
					scanf("%d",&ele);
					insert(ele,a);
					break;
			case 2: if(a[0]==0)
						printf("tree is empty\n");
					else
					{
						printf("inorder traversal\n");
						inorder(a,0);
						printf("\n");
					}
					break;
			case 3:if(a[0]==0)
						printf("tree is empty\n");
					else
					{
						printf(" postorder traversal\n");
						postorder(a,0);
						printf("\n");
					}
					break;
			case 4:if(a[0]==0)
						printf("tree is empty\n");
					else
					{
						printf("preorder traversal\n");
						preorder(a,0);
						printf("\n");
					}
					break;
			default:exit(0);
		}
	}
}