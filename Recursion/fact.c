#include<stdio.h>
#include<stdlib.h>
int fact(int n)
{
    if(n==0 || n==1)
    return 1;
    else
    {
        return n*fact(n-1);
    }
    
}
int main()
{
    int n;
    printf("Enter a number\n");
    scanf("%d",&n);
    int f=fact(n);
    printf("FACT IS %d",f);
}