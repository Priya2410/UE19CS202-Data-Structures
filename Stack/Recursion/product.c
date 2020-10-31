#include<stdio.h>
#include<stdlib.h>
int product(int a,int b)
{
    if(b==0||a==0)
    return 0;
    else
    {
        return a+product(a,b-1);
    }
}
int main()
{
    int a,b;
    printf("Enter a number\n");
    scanf("%d",&a);
    printf("Enter a number\n");
    scanf("%d",&b);

    int f=product(a,b);
    printf("Product IS %d",f);
}