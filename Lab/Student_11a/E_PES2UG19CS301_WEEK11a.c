#include"dfs.h"

  int components(int ** graph,int * visited,int n)
  {
   int i;
   int label=0;
   for(i=0;i<n;i++)
     visited[i]=0;

   for(i=0;i<n;i++)
   {
     if(visited[i]==0)
     {
       ++label;
       dfs(i,graph,visited,n,label);
     }
   }
   return label;
  }


  
  void dfs(int v , int **graph,int * visited,int n,int label)
  {
    int w;
    visited[v]=label;
      
    for(w=0;w<n;w++)
    {
      if((graph[v][w]==1)&&(visited[w]==0))
         dfs(w,graph,visited,n,label);
    }
  }


  
  














 


     



