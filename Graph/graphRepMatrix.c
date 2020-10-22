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
int main()
{
    int n;//The number of vertices
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    int graph[n][n];//2d matrix to represent the graph
    read_mat(n,graph);
}
