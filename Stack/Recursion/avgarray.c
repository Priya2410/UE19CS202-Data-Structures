#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double average(int *y, int i,int p) {
    double result;
    result = (double)y[i] / (double)p;
    if (i == 0)
        return result;
    else
        return result + average(y, i-1,p);
}
int main()
{
	int n=5;
	int a[5]={1,2,3,4,5};
	double res=average(a,n-1,n);
	printf("%lf",res);
}