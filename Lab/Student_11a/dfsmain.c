#include<stdio.h>
#include "dfs.h"

 int main()
 {
   int t;
   scanf("%d",&t);
   while(t--)
   {
   	   int n;
	   scanf("%d",&n);
	   int ** graph = (int **)malloc(sizeof(int *)*n);
	   for(int i =0;i<n;i++)
	   {
	   		graph[i] = (int *)malloc(sizeof(int)*n);
	   		for(int j =0;j<n;j++)
	   		{
	   			scanf("%d",&graph[i][j]);
	   		}
	   }
	   int * visited = (int *)malloc(sizeof(int)*n);
	   int numberOfComponents = components(graph,visited,n);
	   printf("%d\n",numberOfComponents);
	   for(int i =0;i<n;i++)
	   {
	   		printf("%d ",visited[i]);
	   }
	   printf("\n");
	   


   }
    
   return 0;
  }

