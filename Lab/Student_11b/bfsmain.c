#include<stdio.h>
#include "bfs.h"

int main()
{
    int n, q, u, v;
    scanf("%d %d", &n, &q);
    int **graph = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &u, &v);
        if (check_path(graph, n, u - 1, v - 1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    for (int i = 0; i < n; i++)
        free(graph[i]);
    free(graph);
    return 0;
}


