#include<stdio.h>

float avg(int *a,int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return a[0];
	else
		(a[n]+avg(a,n-1))/n;
}
int main()
{
	int n=5;
	int a=[1,2,3,4,5];
	float res=avg(a,n);
}