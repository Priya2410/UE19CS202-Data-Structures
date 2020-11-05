//graph is connected or not using bfs
#include<stdio.h>
void read_matrix(int g[5][5],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&g[i][j]);
}
void traverse(int u, int visited[5],int g[5][5],int n)
{
	int f=0,r=-1,q[n],v;
	q[++r]=u;
	visited[u]=1;
	while(f<=r)
	{
		u=q[f++];
		for(int v=0;v<n;v++)
		{
			if(g[u][v])
			{
				if(!visited[v])
				{
					visited[v]=1;
					q[++r]=v;
				}
			}
		}
	}
}
	
int isconnected(int g[5][5],int n)
{
	int visited[n];
	for(int u=0;u<n;u++)
	{
		for(int j=0;j<n;j++)
		{
			visited[j]=0;
		}
		traverse(u,visited,g,n);
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
				return(0);
		}
	}
	return(1);
}
	
int main()
{
	int n;
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	int g[n][n];
	read_matrix(g,n);
	if(isconnected(g,n))
	{
		printf("graph is connected\n");
	}
	else
	{
		printf("graph is disconnected\n");
	}
}
	
	