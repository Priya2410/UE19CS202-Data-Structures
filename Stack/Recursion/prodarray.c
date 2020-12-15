#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prod(int *a,int n,int p)
{
    if(n==0)
    return a[0];
    else
    {
        return a[n]*prod(a,n-1,p);
    }
}
int main()
{
	int n=5;
	int a[5]={1,2,3,4,5};
	int res=prod(a,n-1,n);
	printf("%d",res);
}