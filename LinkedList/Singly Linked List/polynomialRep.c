//Polynomial Evaluation
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node 
{
    int coeff;
    int exp;
    struct Node *link;
}*poly=NULL;

void create()
{
    //temp is used to store the new node to be added for each term
    struct Node *temp,*last;//To point last node
    int num;//Number of terms
    printf("Enter the number of terms\n");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));
        printf("Enter the coeff and exp\n");
        scanf("%d %d",&temp->coeff,&temp->exp);
        temp->link=NULL;
        if(poly==NULL)
        {
            poly=last=temp;
        }
        else
        {
            last->link=temp;
            last=temp;
        }
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%dx%d+",p->coeff,p->exp);
        p=p->link;
    }
    printf("\n");
}
double eval(struct Node *q,int x)
{
    double sum=0;
    while(q!=NULL)
    {
        sum=sum+q->coeff*pow(x,q->exp);
        q=q->link;
    }
    return sum;
}
int main()
{
    create();
    display(poly);
    double res=eval(poly,1);
    printf("Result:%lf",res);
}


