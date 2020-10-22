#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure using an array
typedef struct stack{
	int* arr;
	int top;
}stack;

// Initialise a stack of given size
stack* stack_initialize(int);

// Push an element onto the stack
void stack_push(stack*, int);

// Pop an element from the stack. Do not return the element
void stack_pop(stack*);

// Check if the stack is empty
int stack_is_empty(stack*);

// Return the top element of the stack
int stack_peek(stack*);

// Free the resources held by the stack
void stack_destroy(stack*);


// Convert an infix expression to postfix expression
void convert_infix_to_postfix(const char*, char*);

