#include<stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
	//TODO
	if(v<0 || u<0 || u>n || v>n )
	return 0;
	int queue[n]; //queue to store the elements
	int temp;
	int rear=-1;
	int front=0;
	int visited[n];//Array to keep track of the nodes visted

	for(int i=0;i<n;i++)
		visited[i]=0;
	queue[++rear]=v;
	visited[v]=1;
	while(front<=rear)
	{
		int temp= queue[front++];
		if(temp == u)
		return 1;
		for(int i=0;i<n;i++)
		{
			if(graph[temp][i] && !visited[i])
			{
				queue[++rear] = i;
				visited[i]=1;
			}
		}
	}
	return 0;
}	
