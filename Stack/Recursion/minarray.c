#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int minimum(int *a,int n,int min)
{
    if(n==0)
    return min;
    else
    {
        if(a[n]<min)
        return minimum(a,n-1,a[n]);
        else
        return minimum(a,n-1,min);
    }
}
int main()
{
	int n=5;
	int a[5]={1,2,3,4,5};
	int res=minimum(a,n-1,a[0]);
	printf("%d",res);
}