#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b)
{
    if(a==1||b==1)
    return 1;
    else if(a==0)
    return b;
    else if(b==0)
    return a;
    else if(a>b)
    {
        if(a%b==0)
        return b;
        else
        {
            return gcd(a,a%b);
        }
        
    }
    else
    {
        if(b%a==0)
        return a;
        else
        {
            return gcd(b%a,b);
        }
        
    }
   
}
int main()
{
    int a,b;
    printf("Enter a number\n");
    scanf("%d",&a);
    printf("Enter a number\n");
    scanf("%d",&b);

    int f=gcd(a,b);
    printf("gcd IS %d",f);
}