#include<stdio.h>
int power(int a,int b)
{
    if(b==0 || a==1)
    return 1;
    else if(a==0)
    return 1;
    else
        return a*power(a,b-1);
}
int main()
{
    int a,b;
    printf("Enter a number\n");
    scanf("%d",&a);
    printf("Enter a number\n");
    scanf("%d",&b);

    int f=power(a,b);
    printf("Power IS %d",f);
}