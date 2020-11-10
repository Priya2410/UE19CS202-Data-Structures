#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct Node 
{
    int data;
    struct Node *rlink;
    struct Node *llink;
};
struct Node *create(char *postfix)
{
    int i,k=0;
    struct Node *st[20];//Stack creation 
    char sym; //To read each symbol in the expression
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));//Creation of node for each symbol.
    for(i=0;(sym=postfix[i])!='\0';i++) //To read the symbol till we reach the end of the expression
    {
        temp->rlink=NULL; //Creation of node for each symbol.
        temp->llink=NULL;
        temp->data=sym;
    if(isalnum(sym))
    {
        st[k++]=temp; //To check if the symbol if alphabet or a digit we push the element
    }
    else
    {
        temp->rlink=st[--k]; //Else we pop it and assign the current symbol's rlink and link to the elements popped
        temp->llink=st[--k];
        st[k++]=temp;
    }
    return st[k--]; //To return the top of the stack
}

float eval(struct Node *root)
{
    int num;
    switch(root->data)
    {
        case '+':
            return(eval(root->llink)+eval(root->rlink));
            break;
        case '-':
            return(eval(root->llink)-eval(root->rlink));
            break;
        case '*':
            return(eval(root->llink)*eval(root->rlink));
            break;
        case '/':
            return(eval(root->llink)/eval(root->rlink));
            break;
        case '$':
            return(pow(eval(root->llink),eval(root->rlink)));
            break;
        default:
            if(isalpha(root->data)) //To check if the data is a alphabet
            {
                printf("%c",root->data);
                scanf("%d",&num);
                return num;
            }
            else
            {
                return (root->data-'0'); //To convert it to number
            }
            
    }
}
int main()
{
    char postfix[20];
    float result;
    struct Node *root=NULL;
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    root=create(postfix);
    result=eval(root);
    printf("The result is =%f\n",result);
}