#include<stdio.h>
void toh(int n,char src,char dst,char temp)
{
    //If only one disc is there then move it from src to dst
    if(n==1)
    {
        printf("move %d from %c to %c\n",n,src,dst);
    }
    else
    {
        toh(n-1,src,temp,dst);
        //Here we move n-1 discs from src to temp using dst so here our Source=A,Destination=B,Temp=C
        printf("move %d from %c to %c\n",n,src,dst);
        toh(n-1,temp,dst,src);
         //Here we move n-1 discs from src to temp using dst so here our Source=B,Destination=C,Temp=A
    }
    
}
int main()
{
    int n=3;
    toh(n,'A','C','B');
    //Here A is source,C is destination and B is temporary
}