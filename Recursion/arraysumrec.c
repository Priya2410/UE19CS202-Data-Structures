#include<stdio.h>
#include<stdlib.h>
int sum(int *a,int n)
{
    if(n==1)
    return a[0];
    else
    {
        return a[n-1]+sum(a,n-1);
    }
}
int main()
{
    int n;
    printf("Enter a number\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    int s=sum(a,n);
    printf("%d",s);
}