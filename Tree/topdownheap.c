#include<stdio.h>
#include<stdlib.h>

void heapify(int *h,int n)
{
    int child,val,parent;
   for(int i=1;i<=n;i++)
   {
       child=i;
       val=h[i];
       parent=(child-1)/2;
        while(child>0 && h[parent]<val)
        {
            h[child]=h[parent];
            child=parent;
            parent=(child-1)/2;
        }
        h[child]=val;
   }

   for(int i=0;i<n;i++)
    {
        printf("%d\t",h[i]);
    }
}
int main()
{
    int h[]={25,57,48,37,12,92,86,33};
    int n=8;
    heapify(h,n);
}