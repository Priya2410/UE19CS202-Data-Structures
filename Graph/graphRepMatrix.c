//Adjacency Matrix Representation of Graph
#include<stdio.h>
void read_mat(int n,int g[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    //To print the matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
}
//n is length of the graph number of nodes in it
//u is the starting vertex
void bfs(int a[5][5],int n,int u)
{
    //Print all the nodes using bfs method
    int f=0,r=-1,q[n],v;//front,rear,queue
    int s[10]={0};//Initially all the nodes are made not visited and marked as 0
    printf("The nodes visited-%d\t",u);
    q[++r]=u;
    s[u]=1;
    printf("%d\t",u);
    while(f<=r)
    {
        u=q[f++];//Deletion 
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1)
            {
                if(s[v]==0)
                {
                    printf("%d\t",v)
                    s[v]=1;
                    q[++r]=v;
                }
            }
        }
    }
    printf("\n");
}
int main()
{
    int n;//This is the number of vertices
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    int graph[n][n];//2d matrix to represent the graph
    read_mat(n,graph);
    for(int i=0;i<n;i++)
    {
        bfs(graph,n,i);
    }
}
