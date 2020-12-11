//Here we are also doing heap sort with two steps:
// 1.Heapify can be top down or bottom up
// 2.Readjust 

#include<stdio.h>

int main()
{
    int h[50]; // Heap Array
    int c;//position of child
    int p;//position of parent
    int n; // Number of elements
    int ele;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&h[i]);//To read the elements
    }
    //Heapify

    for(int i=1;i<n;i++)
    {
        ele=h[i];//Capturing the child element
        c=i;
        p=(c-1)/2;
        while(c>0 && (h[p]<ele))
        { //for child at 0 there is no parent
            {
              h[c]=h[p];
              c=p;
              p=(c-1)/2;
              //This entire process gives us the correct position of where the child must be placed
            }
        }
         h[c]=ele;
    }
    printf("Before Heap sort\n");
    for(int i=0;i<n;i++)
         {
             printf("%d ",h[i]);
         }
    
}