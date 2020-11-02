#include<stdio.h>
#include<stdlib.h>

void heapify(int *h,int n)
{
    int k,val,j;
    int heap;//heap is 1 when its a heap else 0
    //Considering Array as 1 to n
    for(int i=n/2;i>=0;i--)
    {
        k=i;
        val=h[k];
        heap=0;
        while( !(heap) && 2*k<=n) //to check if there is a left child to compare
        {
            j=2*k;//initally left child
            if(j<n) //Right child is also present
            {
                if(h[j+1]>h[j])
                j=j+1;
            }
            if(val>h[j])
            heap=1;
            else
            {
                int temp=h[k];
                h[k]=h[j];
                h[j]=temp;
                k=j;
            }
        }
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