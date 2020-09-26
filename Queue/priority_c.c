/*Implementation of priority queue using singly linked list */

#include <stdio.h> 
#include <stdlib.h> 

typedef struct node 
{ 
    int data; 
    int priority; // Lower values indicate higher priority (Ascending PQ)
    struct node* next; 
} NODE; 


/*Function definition starts here */

// Function to Create A New Node 
NODE* newNode(int d, int p) 
{ 
    NODE* temp = malloc(sizeof(NODE)); 
    if (temp != NULL)
    {
        temp->data = d; 
        temp->priority = p; 
        temp->next = NULL; 
    }
    return temp; 
} 
  
  
// Removes the element with the highest priority from the list 
int deQueue(NODE** head) 
{ 
    int del_item;
    NODE* temp = *head;
    if(*head == NULL){
	printf("Queue is underflow\n");
	return -1;
    }	
    del_item = (*head)->data; 
    (*head) = (*head)->next; 
    free(temp); 
    return del_item;
} 
  
// Function to insert according to priority 
void enQueue(NODE** head, int d, int p) 
{ 
    NODE* start = (*head); 
  
    // Create new Node 
    NODE* temp = newNode(d, p); 
    
    if (temp == NULL)
    {
        printf ("Unable to create a new node\n");
        exit (1);
    }
  
    //Special Case 1: if list is empty: add the first node
	if(start == NULL)
	{
		*head = temp;
		return;
	}
    // Special Case 2: The head of list has lesser priority than new node. 
    // So insert new node before head node and change head node.
 
    if ((*head)->priority > p) 
    { 
        // Insert New Node before head 
        temp->next = *head; 
        (*head) = temp; 
    } 
    else 
    { 
        // Traverse the list and find a position to insert new node 
        while (start->next != NULL && start->next->priority < p) 
        { 
            start = start->next; 
        } 
  
        // Either at the end of the list or at required position 
        temp->next = start->next; 
        start->next = temp; 
    } 
} 
  
// Function to check is list is empty 
int isEmpty(NODE** head) 
{ 
    return(*head) == NULL;
} 
  
void free_mem (NODE *head)
{
    NODE *tmp;

    for (tmp = head; tmp != NULL; tmp=tmp->next)
        free (tmp);
}

void display(NODE *head)
{
	NODE *temp;
	if(head==NULL)
		printf("Queue is empty\n");
	else{
		printf("The Priority Queue is :\n");
		for (temp = head; temp != NULL; temp=temp->next)
        		printf("%d\t",temp->data);
	}

}

int main() 
{ 
   // Create a Priority Queue 
   int value, prior;
   int choice, ch, item_deleted;   
   NODE* pq;
   do
   {
   printf("\nSelect the Operation\n");
   printf("1.Insert\n2.Delete\n3.Display");
   printf("\nEnter your choice for the operation in queue: ");
   scanf("%d",&choice);
   switch(choice)
   {   
           case 1: printf("\nEnter the value to be inserted and it's priority:");
            	     scanf("%d%d",&value,&prior);
			     enQueue(&pq,value, prior);  
                   break;
           case 2: item_deleted = deQueue(&pq); 
                   if(item_deleted != -1)
		   	printf("\nThe value deleted is %d",item_deleted);
                   break;
           case 3: display(pq);
                   break;
           default: printf("Wrong choice");
  }
  printf("\nDo you want to perform another operation (Y/N):press(1/0) ");
  scanf("%d",&ch);
  }while(ch==1);
  
  free_mem (pq);
  return 0;
}
