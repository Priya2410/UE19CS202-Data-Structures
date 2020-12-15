#include<stdio.h>
#define max 50
//Priority Queue Structure
struct PQ
{
    int pq[max]; //array
    int n; // number of elements 
}

//Initializing priority queue
void init(struct PQ *pt)
{
    pt->n=0; //initially the number of elements are 0

}

void display(PQ *pt)
{
    int i;
    for(i=0;i<pt->n;i++)
    {
        printf("%d",pt->pq[i]); // displaying the array elements
    }
}

int enqueue(PQ *pt,int ele)
{
    if(pt->n==max-1) //Queue is full
        return 0;
    int child=n;
    int parent=(child-1)/2;
    //To compare the child with parent and find appropriate posistion for the parent.
    while(child>0 && pq->pt[parent]<pq->pt[child])
    {
        pq->pt[child]=pq->pt[parent];
        child=parent;
        parent=(child-1)/2;
    }
    pq->pt[child]=ele;
    pq->n=pq->n+1; // Inrement number of elements
}

int dequeue(PQ *pt,int ele)
{
    int parent,child;
    *ele=pt->pq[0]; //you can only delete first element
    int last=pq->pt[n-1];
    parent=0;
    if(pt->n==1) // If there is only one element
        child=-1;
    else
    {
        child=1;
        if(child+1<pt->pt->n-1) // That is the second child is present
        {
            if(pt->pq[child+1]>pt->pq[child))
            child=child+1;
        }
        while(child>0 && last<pt->pq[child])
        {
            pt->pq[parent]=pt->pq[child];
            parent=child;
            child=2*parent+1;
            if(child+1<pt->n-1)
            {
                if(pt->pq[child+1]>pt->pq[child))
                child=child+1;
            }
            if(child>=pt->n-1)
                child=-1; // If the child exceeds the position 
        }
        pt->pq[parent]=last;
        pt->n--;
        return 1;
        }
        
    
}
int main()
{
    struct PQ pobj;
    int ele;int k;
    init(&pobj);
    printf("1.Enqueue\n2.Dequeue\n3.Display\n");
    printf("Enter the choice\n")
    scanf("%d",&choice);
    do{
    switch(choice)
    {
        case 1:
        printf("Enter the information\n");
        scanf("%d",&ele); // Element only forms the priority
        enqueue(&pobj,&ele);
        break;

        case 2:
        k=dequeue(&pobj,&ele);
        if(!k)printf("empty");
        else 
        printf("%d dequeues elements",ele);
        break;
    }
}
}