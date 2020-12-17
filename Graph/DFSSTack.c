//Just function dont execute
int stack[20];
int top=-1;
void dfs(int graph,int n,int u)
{
    visited[u]=1;
    printf("%d ",u);
    stack[++top]=ele;
    while(top!=-1)
    {
        u=stack[top--];
        for(int v=0;v<n;v++)
        {
            if(graph[u][v]==1 && !visited[v])
            {
                visited[v]=1;
                stack[++top]=1;
            }
        }
    }

}