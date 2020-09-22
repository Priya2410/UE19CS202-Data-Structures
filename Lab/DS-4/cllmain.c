#include <stdio.h>
#include <stdlib.h>
#include "cll.h"

int main()
{

    List* cll = initialize_list();
    int ele,choice,pos,k;
    
    do
    {
        scanf("%d",&choice);

        switch(choice)
        {
            // Insert at position;
            case 1:
                scanf("%d %d",&ele,&pos);
                position_insert(cll,ele,pos);
                break;

            // Delete at position
            case 2:
                scanf("%d",&pos);
                position_delete(cll, pos);
                break;

            // Josephus problem
            case 3:
                scanf("%d",&k);
                ele = josephus(cll,k);
                printf("%d\n",ele);
                break;

            // Print entire list
            case 4:
                display(cll);
                break;        
        }
    }
    while (choice != 0);

    destroy_list(cll);
    return 0;
}

List* initialize_list()
{
    List* cll = (List*)malloc(sizeof(List));
    cll->head = NULL;
    cll->tail = NULL;
    cll->length = 0;
    return cll;
}

Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void display(List* cll)
{
	if(cll->length == 0)
        printf("EMPTY");
  	  else
   	 {
        Node* temp = cll->head;
        for(int i=0;i<cll->length;i++)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }    
    printf("\n");
}

void destroy_list(List* cll)
{
	Node *p = cll->head;
	Node *q = NULL;
	for(int i=0;i<cll->length;i++)
    	{
		q = p;
		p = p->next;
		free(q);
	}
	
    free(cll);
}
