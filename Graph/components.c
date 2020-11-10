//For undirected disconnected graph
#include<stdio.h>
int visited[50],label=0;
int a[10][10];
int n;

void create_graph()
{
    int i,j;
    while(1)
    {
        //Like n is adjacent to m 
        //Basically to know where the edge exists
        printf("Enter the source and destination\n");
        scanf("%d%d",&i,&j);
        if(i==-9 && j==-9) //just to terminate program
        break;
        a[i][j]=a[j][i]=1;//Basically n,m == m,n edge
    }
}
void dfs(int u)
{
    int v;
    visited[u]=label;
    for(v=1;v<=n;v++)
    {
        if(a[u][v]==1 && visited[u]==0)
        {
            dfs(v);
        }
    }
}
int connected_components()
{
    int i,j;
    label=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
        label++;
        dfs(i);
        }
    }
    return label;
}

int main()
{
    int i;
    int k;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    visited[i]=0;
    create_graph();
    //This holds the total number of components
    int no=connected_components();
    printf("the number of connected components are : %d\n",no);
    printf("The vertices and component number\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ----->%d\n",i, visited[i]);
    }
}