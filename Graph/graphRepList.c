//Adjacency List
#include<stdio.h>
struct Node 
{
    int data;
    struct Node *link;
};

int main()
{
    int n;//The number of vertices
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    struct Node a[n];//declare array of structures
    printf("Enter the list\n");
    read_list(a,n);
    return 0;
}

void read_list(struct Node *a,int n)
{
    int m,ele;
    for(int i=0;i<n;i++)
    {
        printf("Enter the number of nodes adjacent to %d\n",i);
        scanf("%d",&m);
        //If m=0 then continue with the next vertex
        //if m=0 no nodes are adjacent to the vertex
        if(m==0)
            continue;
        printf("Enter the nodes which are adjacent to %d\n",i);
        for(int j=0;j<m;j++)
        {
            printf("Enter the element\n");
            scanf("%d",&ele);
            a[i]=insert_end(ele,a[i]);
        }
    }
}