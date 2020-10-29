#include <stdlib.h>
#include <stdio.h>

typedef struct node node;

struct node
{
	int id;
	int time;
	node *link;
};

typedef struct list
{
	node *head;
	node *tail;
	int number_of_nodes;
} List;

typedef struct queue
{
	List *ptr_list;
} Queue;

void list_initialize(List *list);
void list_insert_rear(List *list, int id, int time);
const int node_get_id(node *node_ptr);
const int node_get_time(node *node_ptr);
void list_delete_rear(List *list);
void list_destroy(List *list);

void queue_initialize(Queue *ptr_queue);
void queue_enqueue(Queue *ptr_queue, int id, int time);
void queue_dequeue(Queue *ptr_queue);
int queue_is_empty(Queue *ptr_queue);
void queue_peek(Queue *ptr_queue);
void queue_destroy(Queue *ptr_queue);
const int queue_find_person(Queue *ptr_queue, int t);
