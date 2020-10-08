#include "5a.h"

static Node* create_Node(int data, Node* link)
{
// TODO - create and allocate dynamic space
Node *temp=(Node *)malloc(sizeof(Node));
temp->data=data;
temp->link=link;
return temp;
}
void list_initialize(List* ptr_list) 
{
//TODO - initialize structure members to default values
ptr_list->head=NULL;
ptr_list->number_of_Nodes=0;
}


void list_insert_front(List* ptr_list, int data) 
{
//TODO - perform linked list implementation of push operation.
struct Node *temp=create_Node(data,ptr_list->head);
    ptr_list->head=temp;
    ptr_list->number_of_Nodes++;
}


const int Node_get_data(Node *Node_ptr) 
{
//TODO - return the top most element
if(Node_ptr == NULL)
    return -1;
else
    return Node_ptr->data;
}


void list_delete_front(List* ptr_list) 
{
//TODO - perform linked list implementation of pop operation.
struct Node *p=ptr_list->head;
if(ptr_list->head==NULL)
    return;
if(ptr_list->head->link == NULL)
{
    free(p);
    ptr_list->head=NULL;
    ptr_list->number_of_Nodes--;
    return;
}
        ptr_list->head=p->link;
        free(p);
        ptr_list->number_of_Nodes--;
        return;
}


void list_destroy(List* ptr_list) 
{
//TODO - free the allocated space
if(ptr_list->head==NULL)
    return;
struct Node *t,*u=NULL;
t=ptr_list->head;
while(t->link!=NULL)
{
    u=t;
    t=t->link;
    free(u);
}
// free(ptr_list);
ptr_list->head=NULL;
}

void Stack_initialize(Stack *ptr_Stack) 
{
//TODO - get the memory allocation for stack, and intern call list initialize
ptr_Stack->ptr_list=(List*)malloc(sizeof(List));
list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key) 
{
//TODO	 - call the function list_insert_front
list_insert_front(ptr_Stack->ptr_list,key);
}

void Stack_pop(Stack *ptr_Stack) 
{
//TODO- call the function list_delete_front
list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack) 
{
//TODO	- return 0 if stack is not empty
if(ptr_Stack->ptr_list->head==NULL)
    return 1;
else
    return 0;

}

const int Stack_peek(Stack *ptr_Stack) 
{
//TODO	- return the top most element of the stack
//sends the head node
    return Node_get_data(ptr_Stack->ptr_list->head);
}

void Stack_destroy(Stack *ptr_Stack)
 {
//TODO	- deallocate
list_destroy(ptr_Stack->ptr_list);
}

int match_parenthesis(const char* string)
{
//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
Stack *stack;//Declare one new stack
stack=(Stack *)malloc(sizeof(Stack));
Stack_initialize(stack);
int i=0;
while(string[i])
{
    if(string[i]=='(' || string[i]== '{' || string[i]== '[')
        Stack_push(stack,string[i]);
    if(string[i]==')' || string[i]=='}' || string[i]==']')
    {
        if(Stack_is_empty(stack))
        {
            return 0;
        }
        else if(!( ((Stack_peek(stack)=='(')&& string[i]==')') ||
            ((Stack_peek(stack)=='[') && string[i]==']') || 
            ((Stack_peek(stack)=='{')&& string[i]=='}')
)
            )
        {
            return 0;
        }
        Stack_pop(stack);
    }
    i++;
}
if(Stack_is_empty(stack))
    return 1;
else
    return 0;
}	


 

