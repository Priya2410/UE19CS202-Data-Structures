#include <stdio.h>
#include <stdlib.h>
#define debug printf("HERE")

typedef struct node {
	int data;
	struct node *link;
}Node;

typedef struct list {
	Node *head;
	int number_of_Nodes;
}List;

/* initializes a linked List */
void List_initialize(List* List); 

void List_insert_front(List* List, int data);

void List_delete_front(List *List);

/* Returns the element that (*Node_ptr) contains */
const int Node_get_data(Node* Node_ptr);

/* deallocates resources held by the List */
void List_destroy(List* List); 


typedef struct {
	List *ptr_List;	
} Stack;

void stack_initialize(Stack* ptr_stack);
void stack_push(Stack* ptr_stack, int data);
void stack_pop(Stack* ptr_stack);
int stack_is_empty(Stack* ptr_stack);
const int stack_peek(Stack* ptr_stack);
void stack_destroy(Stack* ptr_stack);

/* The implementations for the above functions are provided below main() */

/* Returns the result of the postfix expression */
int postfix_eval(const char * expression);
/* TODO:
 * Provide suitable implementation for the above function declaration, namely, postfix_eval()
 */
 
