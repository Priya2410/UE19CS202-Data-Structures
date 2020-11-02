#include<stdio.h>
#include<stdlib.h>

void heapify(int *h,int n)
{
int k, parent,v,j;
int heap;
parent=n/2;
for(int i=n/2;i>=0;i--)
{
	k=i;
	v=h[k];
	heap=0;
	while(!heap &&2*k<=n)
	{
		j=2*k;
		if(j<n)
		{
			if(h[j]>h[j+1])
				j=j+1;
		}
		if(v<=h[j])
			heap=1;
		else
		{
			h[k]=h[j];
			k=j;
		}
	}
	h[k]=v;
}
for(int i=0;i<=n;i++)
    {
        printf("%d\t",h[i]);
    }
}
int main()
{
    int h[]={25,57,48,37,12,92,86,33};
    int n=7;
    heapify(h,n);
}