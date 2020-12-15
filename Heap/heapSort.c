void max_heapify(int *a,int n,int i)
{
    //Here i specifies the location where we must heapify
    int largest=i;
    int lchild=2*i;
    int rchild=2*i+1;

    if(lchild<=n && a[largest]<lchild)
    {
        largest=lchild;
    }

    if(rchild<=n && a[largest]<rchild)
    {
        largest=rchild;
    }

    if(largest!=i) // That is if the parent's value doesnt follow the parental dominance then swap
    {
        int *temp;
        temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;

        heapify(a,n,largest);
    }
}

void heap_sort()
{
    for(i=n/2-1;i>=0;i--)
    {
        max_heapify(a,n,i); // to convert every element to max heap
    }
    for(i=n-1;i>0;i--)
    {
        int *temp;
        temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        max_heapify(a,i,0);
    }
}

