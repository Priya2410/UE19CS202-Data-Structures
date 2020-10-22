#include "6a.h"

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
//TODO	
ptr_List->head=NULL;
ptr_List->number_of_Nodes=0;
}

void List_insert_front(List* ptr_List, int data) 
{
//TODO	
Node *temp=create_Node(data,NULL);
if(ptr_List->head==NULL)
{
	ptr_List->head=temp;
	return;
}
else
{
	temp->link=ptr_List->head;
	ptr_List->head=temp;
}
ptr_List->number_of_Nodes++;
}

const int Node_get_data(Node *Node_ptr) 
{
	//TODO
	if(Node_ptr==NULL)
	   return -1;
	else
	{
		return Node_ptr->data;
	}
	
}

void List_delete_front(List* ptr_List)
{
	//TODO
	Node *temp=ptr_List->head;
	if(ptr_List->head==NULL)
	{
		return;
	}
	else if(ptr_List->head->link==NULL)
	{
		free(temp);
		ptr_List->head=NULL;
		ptr_List->number_of_Nodes--;
	}
	else
	{
		ptr_List->head=ptr_List->head->link;
		free(temp);
		ptr_List->number_of_Nodes--;
	}
	
}

void List_destroy(List* ptr_List) 
{
	//TODO
	if(ptr_List->number_of_Nodes==0)
	{
		return;
	}
	else
	{
		Node *t,*u=NULL;
		t=ptr_List->head;
		while(t->link!=NULL)
		{
			u=t;
			t=t->link;
			free(u);
		}
		free(ptr_List);
	}
	
}


void stack_initialize(Stack *ptr_stack) 
{
	// TODO
	ptr_stack->ptr_List=(List*)malloc(sizeof(List));
	List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
	// TODO
	List_insert_front(ptr_stack->ptr_List,key);
}

void stack_pop(Stack *ptr_stack) 
{
	// TODO
	List_delete_front(ptr_stack->ptr_List);
}

int stack_is_empty(Stack *ptr_stack) 
{
	// TODO
	if(ptr_stack->ptr_List->head==NULL)
		return 1;
	else
	{
		return 0;
	}
	
}

const int stack_peek(Stack *ptr_stack)
{
	//TODO
	return Node_get_data(ptr_stack->ptr_List->head);
}

void stack_destroy(Stack *ptr_stack) 
{
	// TODO
	List_destroy(ptr_stack->ptr_List);
}

int postfix_eval(const char* expression) 
{
    // TODO
	Stack *stack=(Stack*)malloc(sizeof(Stack));
	stack_initialize(stack);
	int op1,op2;
	char sym;
	int val;
	int power(int x,int y);
	for(int i=0;sym!='\0';i++)
	{
		sym=expression[i];
		if(sym=='0'||sym=='1'||sym=='2'||sym=='3'||sym=='4'||sym=='5'||
			sym=='6'||sym=='7'||sym=='8'||sym=='9')
		{
			stack_push(stack,sym-'0');
		}
		else
		{
				switch(sym)
				{
					case '+':   op2=stack_peek(stack);
								stack_pop(stack);
								op1=stack_peek(stack);
								stack_pop(stack);
					 		  	stack_push(stack,op1+op2);
						      	break;
					case '-':   op2=stack_peek(stack);
								stack_pop(stack);
								op1=stack_peek(stack);
								stack_pop(stack);
					 		  	stack_push(stack,op1-op2);
						      	break;
					case '*':   op2=stack_peek(stack);
								stack_pop(stack);
								op1=stack_peek(stack);
								stack_pop(stack);
					 		  	stack_push(stack,op1*op2);
						      	break;
					case '/': 
							    op2=stack_peek(stack);
								stack_pop(stack);
								op1=stack_peek(stack);
								stack_pop(stack);
							  if(op2!=0)
							  stack_push(stack,op1/op2);
							  break;
					case '^': 
								op2=stack_peek(stack);
								stack_pop(stack);
								op1=stack_peek(stack);
								stack_pop(stack);
							if(op2==0)
							val=1;
							else if(op1==0)
							val=0;
							else
							{
								val=1;
								for(int i=1;i<=op2;i++)
								{
									val=val*op1;
								}
							}
							stack_push(stack,val);
							break;
				}
		}
	}
	int result=stack_peek(stack);
	stack_destroy(stack);
	return result;
}
