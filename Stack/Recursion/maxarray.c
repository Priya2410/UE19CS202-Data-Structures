#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int maximum(int *a,int n,int max)
{
    if(n==0)
    return max;
    else
    {
        if(a[n]>max)
        return maximum(a,n-1,a[n]);
        else
        return maximum(a,n-1,max);
    }
}
int main()
{
	int n=5;
	int a[5]={1,2,3,4,5};
	int res=maximum(a,n-1,a[0]);
	printf("%d",res);
}