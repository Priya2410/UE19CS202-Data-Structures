#include <stdio.h>
#include <stdlib.h>

// Node of the circular linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
// Handle of the list.
// Head points to the first node in the list.
// Tail points to the last node in the list.
typedef struct List
{
    Node *head;
    Node *tail;
    int length;
} List;

// initializes a cirucular linked list
List* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int data);

// Inserts data at offset position pos. No operation is required if pos is out of range.
void position_insert(List* cll, int data, int pos);

// Deletes the node at position pos. No operation is required if pos is out of range.
void position_delete(List* cll, int pos);

// Print the data present in the safe node according to the josephus problem.
int josephus(List* cll,int k);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List* cll);

// Deallocates resources held by the list
void destroy_list(List*);


