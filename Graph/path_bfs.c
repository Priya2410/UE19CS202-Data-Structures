/*dfs list*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node *NODE;
NODE a[10];
int p=0;

NODE getnode()
{
	NODE x;
	x=(NODE) malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("out of memory\n");
		exit(0);
	}
	return(x);
}
NODE insert_rear(int ele,NODE first)
{
	NODE temp;
	NODE cur;
	temp=getnode();
	temp->info=ele;
	temp->link=NULL;
	if(first==NULL)
		return temp;
	cur=first;
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=temp;
	return first;
}

void read_ad_list(NODE a[],int n)
{
	int i,j,m,ele;
	for(i=0;i<n;i++)
	{
		printf("enter the number of nodes adjacent to %d\n",i);
		scanf("%d",&m);
		if(m==0)
			continue;
		printf("enter the nodes adjacent to %d\n",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&ele);
			a[i]=insert_rear(ele,a[i]);
		}
	}
}

void printall(int u,int d,int visited[10],int path[10])
{
	visited[u]=1;
	path[p]=u;
	p++;
	if(u==d)
	{
			
		for(int i=0;i<p;i++)
		{
			printf("%d ",path[i]);
		}
		printf("\n");
	}
	else{
		for(NODE temp=a[u];temp!=NULL;temp=temp->link)
			if(!visited[temp->info])
			{
				printall(temp->info,d,visited,path);
			}
	}
	p--;
	visited[u]=0;
}
	
void printpath(int s,int d,int n)
{
	int visited[10];
	int path[10];
	int p=0;
	for(int i=0;i<n;i++)
		visited[i]=0;
	printall(s,d,visited,path);
}

			
int main()
{
	int i,so,de,n;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	printf("enter the adjacency list\n");
	read_ad_list(a,n);
	printf("enter the source and destination\n");
	scanf("%d%d",&so,&de);
	printpath(so,de,n);
}